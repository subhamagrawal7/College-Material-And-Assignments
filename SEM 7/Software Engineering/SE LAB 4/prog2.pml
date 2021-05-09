proctype gcd(int a;int b) {
    if
    :: (b == 0) -> printf("ans is %d\n", a)
    :: (b != 0) -> run gcd(b, a % b)
    fi
}

init {
    run gcd(5, 10);
}