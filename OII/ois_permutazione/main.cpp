#include <cstdio>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int K;
    scanf("%d", &K);

    char perm[27];
    int left = 0, right = 0, dir = 2;
    for(int i = 0; i < 26; i++) {
        if(K-- > 0)
            perm[i] = (i % 2 ? ('Z' - left++) : ('A' + right++));
        else switch(dir) {
            case 0: perm[i] = 'Z' - left++; break;
            case 1: perm[i] = 'A' + right++; break;
            case 2: dir = (right + left) % 2, i--;
        }
    }
    perm[26] = '\0';
    printf("%s\n", perm);
    return 0;
}
