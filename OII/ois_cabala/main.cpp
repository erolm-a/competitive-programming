#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 1000
int N, M;
char bible[MAX_N][MAX_N+1];
//bool visited[MAX_N][MAX_N];

int orizz(int i, int j) {
    int count; char ch;
    for(count = 0, ch = bible[i][j]; j < M && bible[i][j] == ch; j++, count++)
        //visited[i][j] = true;
        ;
    return count;
}
int vert(int i, int j) {
    int count; char ch;
    for(count = 0, ch = bible[i][j]; i < N && bible[i][j] == ch; i++, count++)
        //visited[i][j] = true;
        ;
    return count;
}

int diag1(int i, int j) {
    int count; char ch;
    for(count = 0, ch = bible[i][j]; i < N && j < M && bible[i][j] == ch; i++, j++, count++)
        //visited[i][j] = true;
        ;
    return count;
}

int diag2(int i, int j) {
    int count; char ch;
    for(count = 0, ch = bible[i][j]; i < N && j >= 0 && bible[i][j] == ch; i++, j--, count++)
        //visited[i][j] = true;
        ;
    return count;
}

int risolvi() {
    int ris[4], maximal = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            //if(!visited[i][j]) {
                ris[0] = orizz(i, j);
                ris[1] = vert(i, j);
                ris[2] = diag1(i, j);
                ris[3] = diag2(i, j);

                maximal = max(maximal, *max_element(ris, ris + 4));
            //}
    }
    return maximal;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf(" %s", bible[i]);

    printf("%d\n", risolvi());

    return 0;
}
