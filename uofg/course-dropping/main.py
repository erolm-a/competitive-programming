#!/usr/bin/python3

def main():
    n, k = [int(x) for x in input().split()]
    courses = dict()
    for i in range(n):
        s, t = input().split()
        t = int(t)
        if not s in courses:
            courses[s] = t
        else:
            courses[s] += t

    if k == 0:
        print(0)

    else:
        print(sum(sorted(courses.values())[-k:]))

if __name__ == "__main__":
    main()

