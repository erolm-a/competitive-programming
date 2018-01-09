#include <bits/stdc++.h>

using namespace std;
#define MAX_N (int)1e6
char pat[MAX_N+1], txt[MAX_N+1];

vector<int> pos;
int lps[MAX_N];

void preprocess() {
    for(int i = 1, len=0; pat[i] != '\0';) {
        if(pat[i]==pat[len]) lps[i++]=++len;
        else if(len) len = lps[len-1];
        else lps[i++] = 0;
    }
}
void count() {
    preprocess();
    pos.clear();
    int i = 0, j = 0;
    while(txt[i]) {
        if(txt[i] == pat[j]) i++, j++;
        if(!pat[j]) {
            pos.push_back(i-j+1);
            j = lps[j-1];
        }
        else if(txt[i] && pat[j] != txt[i]) {
            if(j) j = lps[j-1];
            else i++;
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%s %s", txt, pat);
        count();
        if(pos.size()) {
            printf("%lu\n", pos.size());
            for(int i: pos)
                printf("%d ", i);
        }
        else printf("Not Found\n");
        puts("");
    }
}
