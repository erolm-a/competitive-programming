#!/usr/bin/python3

def main():
    n, m, k = [int(x) for x in input().split()]

    if k == 1:
        print(-1)
        exit(0)
    # can m be written in base k using at most n digits?

    digits = []
    while m > 0:
        digits.append(m % k)
        m //= k

    if len(digits) > n:
        print("-1")

    else:
        digits = digits + [0]*(n-len(digits))
        for i in reversed(digits):
            print("%d " % i, end="")

if __name__ == "__main__":
    main()
