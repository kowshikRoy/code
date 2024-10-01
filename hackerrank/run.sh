while true; do
    python3 gen.py > in
    ./sane < in > out1
    python3 a.py < in > out2

    if ! cmp -s out1 out2; then
        cat out1
        cat out2
        cat in
        exit 1
    else
        printf "OK\n"
    fi

done
