#include <bits/stdc++.h>

template<typename Int>
Int readInteger () {
    bool minus = false;
    Int result = 0;
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

#define readint readInteger<int>
#define MAX_N 100000

int link[MAX_N], S[MAX_N], dp[MAX_N];
int v(int a) {switch(S[a]){case 0: return 100; case 1: return 300; default: return 500;}}
int linka(int i) {return link[i] < 0 ? 0 : dp[link[i]];}
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N = readint();

    for(int i = 0; i < N; i++)
        S[i] = readint();

    dp[0] = v(0);
    dp[1] = v(1) + dp[0];
    dp[2] = v(2) + dp[1];
    fill(link, link + 3, -1);

    for(int i = 3; i < N; i++)
    {
        int a = v(i) + linka(i-1), b = v(i) + v(i-1) + linka(i-2), c = v(i) + v(i-1) + v(i-2) + linka(i-3);
        int t = max({a, b, c});
        dp[i] = t;
        if(t == a)
            link[i] = i-1;
        else if(t == b)
            link[i] = i-2;
        else link[i] = i-3;
    };
    for(int i = 0; i < N; i++)
        fprintf(stderr, "%d ", dp[i]);

    printf("%d\n", dp[N-1]);
}
