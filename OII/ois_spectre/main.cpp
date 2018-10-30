#include <bits/stdc++.h>

using namespace std;

#define MAX_S 11
char ris[MAX_S], op1[MAX_S], op2[MAX_S];
unordered_set<string> deps;

int main()
{
    int N, r = 0;
    scanf("%d", &N);
    while(N--) {
        scanf(" %s = %s %*c %s", ris, op1, op2);
        if(deps.find(op1) == deps.end() && deps.find(op2) == deps.end()) r++;
        deps.insert(ris);
    }

    printf("%d\n", r);
}
