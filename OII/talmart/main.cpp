#include <bits/stdc++.h>

using namespace std;

#define MAX_N 250000
int N, nums[MAX_N];

int calcola()
{
    int increasing = 1, decreasing = 0;

    bool israising = true;
    for(int i = 1; i < N; i++)
        if(nums[i] > nums[i-1] && !israising)
            israising=true, increasing++;
        else if(nums[i] < nums[i-1] && israising)
            israising=false, decreasing++;

    return increasing + decreasing;
}

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
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    N = readInt();
    (void) readInt();
    for(int i = 0; i < N; i++)
        nums[i] = readInt();

    printf("%d\n", calcola());
}
