read -a Files <<< $(cat modi)

for f in "${Files[@]}"; do
    git add $f
    git commit -m "feat(cses): Add $f solution"
    echo $f
done
