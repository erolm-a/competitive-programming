#include <cstdio>
#include <cassert>
#include <string>
#define MAXN 10000
#define MAXL 64
using namespace std;

int lcs(string a, string b) {
    static int LCS[60][60];


}

int invalid(int N, char U[][MAXL]) {
    int LCS[];
}


char U[MAXN][MAXL];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%s", U[i]));

    fprintf(fw, "%d\n", invalid(N, U));
    fclose(fr);
    fclose(fw);
    return 0;
}
