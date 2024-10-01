#include <iostream>
#include <cstdio>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main()
{
    char fileName[] = "sharedFile";
    int fd = open(fileName, O_RDWR);
    auto wlen = write(fd, "hello", 6);
    // fsync(fd);
    std::cout << "Written " << wlen << " bytes" << std::endl;
    
    char buf[100];
    int newfd = open(fileName, O_RDONLY);
    auto rlen = read(newfd, buf, 100);
    std::cout << "Read " << rlen << " bytes" << std::endl;
    
    std::cout<< "Read: " << buf << std::endl;
    
}
