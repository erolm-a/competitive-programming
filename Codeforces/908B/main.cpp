#include <bits/stdc++.h>

using namespace std;

int n, m;
#define MAX_N 50
char maze[MAX_N][MAX_N+1];
char S[2*MAX_N+1], sz_S;
int perm[4] = {0, 1, 2, 3};
int start_h, start_w;

#define check(h, w) (h >= 0 && h < n && w >= 0 && w < m && maze[h][w] != '#')
bool possible()
{
    int h = start_h, w = start_w;

    for(int i = 0; i < sz_S; i++) {
        if(maze[h][w] == 'E') return true;
        switch(perm[S[i] - '0']) {
        case 0:
            h--; break;
        case 1:
            w++; break;
        case 2:
            h++; break;
        case 3:
            w--; break;
        }
        if(!check(h, w))
            return false;
    }
    return false;

}
int count()
{
    int count = 0;
    do {
        if(possible()) count++;
    }while(next_permutation(perm, perm + 4));
    return count;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", maze[i]);
    scanf("%s", S);
    sz_S = strlen(S);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(maze[i][j] == 'S') {
                start_h = i, start_w = j; break;
            }


    printf("%d\n", count());
}
