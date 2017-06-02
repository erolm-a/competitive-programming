#include <cstdio>
#include <cctype>

using namespace std;

#define MAX_L 100000
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char msg[MAX_L + 1];
    int N;
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++) {
        msg[i] = getchar();
        if(isalpha(msg[i])) msg[i] = msg[i] > 96 ? msg[i] - 32 : msg[i] + 32;
    }
    puts(msg);
}
