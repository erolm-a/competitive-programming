#include <bits/stdc++.h>

int readInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

using namespace std;

#define MAX_N 1000001
bitset<MAX_N> stats;
int nums[MAX_N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N = readInt();

    for(int i = 1; i <= N; i++)
        nums[i] = readInt();

    for(int i = 1; stats[i] == false; stats[i]=true, i=((i+nums[i])%N)+1);

    printf("%d\n", (int) (N - stats.count()));
    for(int i=1; i <= N; i++)
        if(!stats[i]) printf("%d ", i);
    printf("\n");
}
