#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10000000 // big haystack, just to test
int lps[MAX_N+1];
char pat[MAX_N+1];
char line1[MAX_N+1], line2[MAX_N+1];
int M, N;
int ris;

void preprocess() {
    int i = 1, len = 0;
    while(i < M) {
        if(pat[i] == pat[len]) lps[i++]=++len;
        else if(len == 0) lps[i++] = 0;
        else len = lps[len-1];
    }
}

int count(const char *txt) {
    int ris = 0;

    int i = 0, j = 0;
    while(i < N) {
        if(txt[i] == pat[j]) i++, j++;
        if(j == M) {
            ris++;
            j = lps[j-1];
        }
        else if(i < N && pat[j] != txt[i]) {
            if(j) j = lps[j-1];
            else i++;
        }
    }
    return ris;
}

int main()
{
    scanf("%d", &N);
    scanf(" %s %s", line1, line2);

    reverse(line2, line2 + N);

    scanf(" %d", &M);

    (void)getchar(); // newline
    for(int i = 0; i < M; i++){
        pat[i] = (getchar() == '<' ? '^' : 'v');
    }

    preprocess();
    int ris = count(line1);
    for(int i = 0; i < M; i++)
        pat[i] = (pat[i] == '^' ? 'v': '^');

    ris+=count(line2);
    printf("%d\n", ris);
}
