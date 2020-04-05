#include <bits/stdc++.h>

using namespace std;

#define MAX_Q 1000
#define MAX_LEN 10001
tuple<int, char, char> queries[MAX_Q];
int Q;

int main()
{
    char S[MAX_LEN];

    int n = strlen(S);

    if(isdigit(S[0]) || S[0] == '\n' || n == 0) return 0;
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++) {
        int a; char b, c;
        scanf("%d %c %c", &a, &b, &c);
        queries[i] = make_tuple(a,b,c);
    }

    for(--Q; Q >= 0; --Q) {
        int pos; char a, b;
        tie(pos, a, b) = queries[Q];
        if(pos >= n)
            continue;
        for(int i = pos; i < n; i++) {
            if(S[i] == a) S[i] = b;
            else if(S[i] == toupper(a)) S[i] = toupper(b);
            else if(S[i] == b) S[i] = a;
            else if(S[i] == toupper(b)) S[i] = toupper(a);
        }
    }

    cout << S << '\n';
}
