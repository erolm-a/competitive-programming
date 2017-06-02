#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>
using namespace std;

#define MAX_TILES 50
#define MAX_A 10
#define MAX_B 5

short up[MAX_TILES], down[MAX_TILES], right[MAX_TILES], left[MAX_TILES];

vector<int> adj_up[1 << MAX_A],
            adj_left[1 << MAX_A],
            adj_both[1 << MAX_A][1 << MAX_A];

bool used[MAX_TILES];
int A, B, N;
int sol[MAX_B][MAX_B];

void print() {
    for(int i = 0; i < B; i++) {
        for(int j = 0; j < B; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
    exit(0);
}

void calc(int a, int b) {
    if(a == B)
        print();
    if(a == 0 && b == 0)
        for(int i = 0; i < N; i++) {
            used[i] = true;
            sol[a][b] = i;
            calc(a, b+1);
            used[i] = false;
        }
    else if(a == 0)
        for(auto i: adj_left[right[sol[a][b-1]]]) {
            if(!used[i]) {
                used[i] = true;
                sol[a][b] = i;
                calc(a + (b == B-1), (b+1) % B);
                used[i] = false;
            }
        }
    else if(b == 0)
        for(auto i: adj_up[down[sol[a-1][b]]]) {
            if(!used[i]) {
                used[i] = true;
                sol[a][b] = i;
                calc(a, b+1);
                used[i] = false;
            }
        }
    else {
        for(auto i: adj_both[down[sol[a-1][b]]][right[sol[a][b-1]]])
            if(!used[i]) {
                used[i] = true;
                sol[a][b] = i;
                calc(a + (b == B-1), (b+1)%B);
                used[i] = false;
            }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d", &A, &B, &N);
    char tile[MAX_A][MAX_A+1];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < A; j++)
            scanf(" %s", tile[j]);
        for(int j = 0; j < A; j++) {
            up[i] |= (tile[0][j] - '0') << (A - j - 1);
            down[i] |= (tile[A-1][j] - '0') << (A - j - 1);
            right[i] |= (tile[j][A-1] - '0') << (A - j - 1);
            left[i] |= (tile[j][0] - '0') << (A - j - 1);
        }
        adj_up[up[i]].push_back(i);
        adj_left[left[i]].push_back(i);
        adj_both[up[i]][left[i]].push_back(i);
    }


    calc(0, 0);
    return 0;
}
