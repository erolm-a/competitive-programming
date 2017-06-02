#!/usr/bin/python3

import sys
import random

def main():
    if len(sys.argv) is not 3:
        print("Uso: {} numero_vertici peso_massimo".format(sys.argv[0]))
        return
    random.seed()
    N = int(sys.argv[1])
    max_peso = random.randint(0, int(sys.argv[2]))
    M = random.randint(1, N*(N-1)/2)
    
    archi = dict()
    for i in range(1, N+1):
        archi[i] = list()
        
    for i in range(0, M):
        while 1:
            a = random.randint(1, N)
            b = random.randint(1, N)
            if not(a == b or b in archi[a] or a in archi[b]):
                archi[a].append([b, random.randint(1, max_peso)])
                break
    
    generated = open("input.txt", "w");
    generated.write("{} {}\n".format(N, M));
    for i in range(1, N+1):
        for j in archi[i]:
            generated.write("{} {} {}\n".format(i, j[0], j[1]))
    
    generated.close()
    
main()
