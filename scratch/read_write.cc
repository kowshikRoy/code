#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void readLine(int fd, char *str, size_t max) {
    size_t pos = 0;
    while (pos < max) {
        ssize_t n = read(fd, str + pos, 1);
        if (n == 0) {
            sleep(1);
        } else if (n == 1) {
            if (str[pos] == '\0') { return; }
            pos++;
        } else {
            perror("read() failure");
            exit(2);
        }
    }
    fprintf(stderr, "Didn't receive null terminator in time\n");
    exit(2);
}

#define CHILD_STDIN_READ   pipefds_input[0]
#define CHILD_STDIN_WRITE  pipefds_input[1]
#define CHILD_STDOUT_READ  pipefds_output[0]
#define CHILD_STDOUT_WRITE pipefds_output[1]
#define CHILD_STDERR_READ  pipefds_error[0]
#define CHILD_STDERR_WRITE pipefds_error[1]

int main(int argc, char **argv) {
    int pipe_status;
    int pipefds_input[2], pipefds_output[2], pipefds_error[2];

    pipe_status = pipe(pipefds_input);
    if (pipe_status == -1) {
        perror("Error creating the pipe");
        exit(EXIT_FAILURE);
    }

    pipe_status = pipe(pipefds_output);
    if (pipe_status == -1) {
        perror("Error creating the pipe");
        exit(EXIT_FAILURE);
    }

    pipe_status = pipe(pipefds_error);
    if (pipe_status == -1) {
        perror("Error creating the pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == 0) {
        dup2(CHILD_STDIN_READ, 0);
        dup2(CHILD_STDOUT_WRITE, 1);
        dup2(CHILD_STDERR_WRITE, 2);
        // Close in the child the unused ends of the pipes
        close(CHILD_STDIN_WRITE);
        close(CHILD_STDOUT_READ);
        close(CHILD_STDERR_READ);

        execl("/usr/bin/wc", "wc");
    } else if (pid > 0) {
        close(CHILD_STDIN_READ);
        close(CHILD_STDOUT_WRITE);
        close(CHILD_STDERR_WRITE);
        while (1) {
            sleep(1);
            write(CHILD_STDIN_WRITE, "abcd\n", strlen("abcd") + 1);
            char buf[100];
            int rlen = read(CHILD_STDOUT_READ, buf, 100);
            printf("Output %s\n", buf);
        }
    } else {
        perror("fork");
        exit(2);
    }
    return 0;
}