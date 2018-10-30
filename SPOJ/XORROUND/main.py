#!/usr/bin/python3

# Prove that after pth step (where p is a power of two)
# a_n = a_n ^ a_(n-p) ^ a_(n+p)

def main():
    tc = int(input())

    for t in range(tc):
        N, K = [int(x) for x in input().split()]
        A = [int(x) for x in (input()).split()]

        while(K > 0):
            p = K & (-K)
            K = K - p
            A = [A[i] ^ A[(i-p)%N] ^ A[(i+p)%N] for i in range(N)]

        for x in A:
            print("%d " % x, end="")
        print()

main()
