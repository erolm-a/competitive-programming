#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000000

char in_string[MAX_N+1];
int N;

int start, end;

int F[] = {
       1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584,
    4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811,
    514229, 832040
};

int end_of_fibstr(int begin)
{
    if(begin == N - 1)
        return N;

    if(in_string[begin] == in_string[begin+1])
        return begin+1;
    int i = 2;
    for(; i < sizeof(F)/sizeof(int) && F[i] + begin <= N &&
        strncmp(in_string + begin, in_string + begin + F[i-1], F[i-2]) == 0;
        i++)
        ;
    return begin + F[i-1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    scanf("%s", in_string);
    for(int i = 0; i < N; i++)
    {
        int end = end_of_fibstr(i);
        if(end - i > ::end - start)
            ::end = end, start = i;
    }
    printf("%d %d", start+1, ::end);
}
