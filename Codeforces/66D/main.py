#!/usr/bin/python3

import math
import functools

prime_list = [2,3]

def sieve(primes_no):
    p = 5
    while len(prime_list) < primes_no:
        isprime = True
        for q in range(3, int(math.sqrt(p))+1, 2):
            if p % q == 0:
                isprime = False
                break
        if isprime == True:
            prime_list.append(p)
        p += 2

def main():
    n = int(input())
    if n == 2:
        print("-1")
        exit()
    sieve(n)

    for i in range(n):
        print(functools.reduce(lambda x,y : x*y, prime_list[:i]+prime_list[i+1:], 1))

if __name__ == "__main__":
    main()
