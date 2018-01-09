#include <iostream>

using namespace std;

// trivial KMP

#define MAX_N 10000000 // big haystack, just to test
int lps[MAX_N];
char pat[MAX_N+1];
int M;

void preprocess() {
    int i = 1, len = 0;
    while(i < M) {
        if(pat[i] == pat[len]) lps[i++]=++len;
        else if(len == 0) lps[i++] = 0;
        else len = lps[len-1];
    }
}

void count() {
    preprocess();

    char ch;
    scanf(" %c", &ch);
    int j = 0, i = 0;
    while(ch != '\n') {
        if(ch == pat[j]) {
            ch = getchar();
            i++;
            j++;
        }

        if(j == M) {printf("%d\n", i-j); j = lps[j-1];}
        else if(ch != '\n' && pat[j] != ch) {
            if(j) j = lps[j-1];
            else ch = getchar(), i++;
        }
    }
}
int main()
{
    while(1 == scanf("%d", &M)) {
        scanf("%s", pat);
        count();
        puts("");
    }
}
