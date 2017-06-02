#include <bits/stdc++.h>

using namespace std;

#define MAX_N 2000
int dp[MAX_N];
int piet[MAX_N];

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    int N;
    input >> N;
    for(int i = 0; i < N; i++)
        input >> piet[i];

    dp[N-1] = piet[N-1];
    for(int i = N-2; i >= 0; i--)
    {
        int idx = i + piet[i] + 1;
        if(idx > N && piet[i] > dp[i+1])
            dp[i] = piet[i];
        else if(idx < N && piet[i] + dp[idx] > dp[i+1])
            dp[i] = piet[i] + dp[idx];
        else
            dp[i] = dp[i+1];
    }
    output << dp[0];
}
