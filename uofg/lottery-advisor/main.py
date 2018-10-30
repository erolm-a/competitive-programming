#!/usr/bin/python3
import random

def main():
    t = int(input())
    for i in range(t):
        l, r, x = [int(x) for x in input().split()]
        y = x
        while y == x:
            y = random.randint(l, r)
        print(y)

if __name__ == "__main__":
    main()
