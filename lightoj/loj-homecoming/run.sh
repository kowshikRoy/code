#!/bin/sh

while(true); do
    python3 gen.py > in
    ./sane < in > out1
    ./a.out < in > out2

    if ! cmp -s out1 out2; then
        cat out1
        cat out2
        cat in
        exit 1
    else
        cat out1
        printf "OK\n"
    fi
done

