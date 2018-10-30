#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000
int giorgio[MAX_N][MAX_N];
int nums[MAX_N];
int N;

int pow_minus1[] = {1, -1};

double pow_of_2[MAX_N];

void prepara_giorgio() {

    pow_of_2[0] = 1.;
    pow_of_2[1] = 2.;
    for(int i = 2; i < N; i++)
        pow_of_2[i] = pow_of_2[i-1]*2.;

    for(int i = 0; i < N; i++) {
        giorgio[i][i] = nums[i];
        for(int j = i+1; j < N; j++)
            giorgio[i][j] = giorgio[i][j-1] + pow_minus1[(j-i) % 2]*nums[j]/pow_of_2[j-i];

        for(int j = i-1; j >= 0; j--)
            giorgio[i][j] = giorgio[i][j+1] + pow_minus1[(i-j) % 2]*nums[j]/pow_of_2[i-j];
    }
}

pair<int, char> memo[MAX_N][MAX_N];

int dp(int i, int j)
{
    if(j < i) return 0;
    if(memo[i][j].first) return memo[i][j].first;
    // dato che i giocatori sono solo 2, si conserva la parità delle mosse
    if((i + N - j - 1) % 2 == 0) // William
    {
        if(nums[i] + dp(i+1, j) < nums[j] + dp(i, j-1))
            memo[i][j] = {nums[j] + memo[i][j-1].first, 'R'};
        else memo[i][j] = {nums[i] + memo[i+1][j].first, 'L'};
    }
    // Giorgio
    else if(fabs(giorgio[i][j] - giorgio[j][i]) < 1.e-6) {
        // sceglie William
        if(dp(i+1, j) < dp(i, j-1))
            memo[i][j] = {memo[i][j-1].first, 'R'};
        else memo[i][j] = {memo[i+1][j].first, 'L'};
    }
    else if(giorgio[i][j] > giorgio[j][i])
        memo[i][j] = {dp(i+1, j), 'L'};
    else memo[i][j] = {dp(i, j-1), 'R'};

    return memo[i][j].first;
}

template<typename Int>
Int readInteger () {
    Int result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    result = ch-'0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    return result;
}

#define readint readInteger<int>
int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    N = readint();

    for(int i = 0; i < N; i++)
        nums[i] = readint();

    prepara_giorgio();

    dp(0, N-1);
    for(int i = 0, j = N-1; j >= i;) {
        putchar(memo[i][j].second);
        if(memo[i][j].second == 'R') j--;
        else i++;
    }
}
