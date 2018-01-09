#include <iostream>

using namespace std;

#define MAX_H 100
#define MAX_S 1000
#define MODULO 1000000007
char m[MAX_H][MAX_H];
int dp[MAX_H][MAX_H][MAX_S];

int main()
{
    int H, W;
    string S;
    cin >> S >> H >> W;
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++) {
            cin >> m[i][j];
            if(m[i][j] == S.back())
                dp[i][j][S.size()-1] = 1;
        }
    for(int s = (int)(S.size())-2; s >= 0; s--)
        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++) {
                if(m[i][j] != S[s]) continue;
                long long k = 0;
                bool up = i > 0;
                bool down = i < H - 1;
                bool left = j > 0;
                bool right = j < W - 1;

                if(up) k = (k + dp[i-1][j][s+1]) % MODULO;
                if(up && left) k = (k + dp[i-1][j-1][s+1]) % MODULO;
                if(up && right) k = (k + dp[i-1][j+1][s+1]) % MODULO;
                if(left) k = (k + dp[i][j-1][s+1]) % MODULO;
                if(right) k = (k + dp[i][j+1][s+1]) % MODULO;
                if(down) k = (k + dp[i+1][j][s+1]) % MODULO;
                if(down && left) k = (k + dp[i+1][j-1][s+1]) % MODULO;
                if(down && right) k = (k + dp[i+1][j+1][s+1]) % MODULO;

                dp[i][j][s] = k;
            }

    long long res = 0;
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            res = (res + dp[i][j][0]) % MODULO;

    cout << res << '\n';
}
