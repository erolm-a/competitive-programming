#include <bits/stdc++.h>

using namespace std;
#define MAX_N 10000
#define MAX_S 31
char tasks[MAX_N][MAX_S];
pair<string, string> labels[MAX_N];

int N, K;

int lcp(char* a, char* b) {
    int i = 0;
    for(i = 0; a[i] != '\0' && a[i]==b[i]; i++);
    return i;
}

int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
        scanf(" %s", tasks[i]);

    labels[0].first = string(tasks[0],lcp(tasks[0], tasks[N/K-1])+1);

    for(int i = 0; i < K-1; i++) {
        int dim1 = max(lcp(tasks[i*(N/K)], tasks[(i+1)*(N/K)-1]),lcp(tasks[(i+1)*(N/K)-1], tasks[(i+1)*(N/K)]))+1;
        int dim2 = max(lcp(tasks[(i+1)*(N/K)-1], tasks[(i+1)*(N/K)]), lcp(tasks[(i+1)*(N/K)], tasks[(i+2)*(N/K)-1]))+1;
        labels[i].second = string(tasks[(i+1)*(N/K)-1], dim1);
        labels[i+1].first = string(tasks[(i+1)*(N/K)], dim2);
    }

    labels[K-1].second = string(tasks[N-1], lcp(tasks[N-1], tasks[N - N/K])+1);
    for(int i = 0; i < K; i++) {
        for(char& c: labels[i].first)
            c = toupper(c);
        for(char& c: labels[i].second)
            c = toupper(c);
        printf("%s-%s\n", labels[i].first.c_str(), labels[i].second.c_str());
    }
}
