#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;

int l10, l16, bipasso;

#define MAX_N 20000
pair<int, int> computer[MAX_N];

enum {
    L10, L16
};

int N, M, totale;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &M);
    char str[8];
    for(int i = 0; i < N; i++)
        scanf(" %d", &computer[i].first);
    for(int i = 0; i < N; i++) {
        scanf(" %s", str);
        if(strcmp(str, "L10") == 0)
            computer[i].second = L10;
        else if(strcmp(str, "L16") == 0)
            computer[i].second = L16;
    }
    for(int i = 0; i < M; i++) {
        scanf(" %s", str);
        if(strcmp(str, "L10") == 0)
            l10++;
        else if(strcmp(str, "L16") == 0)
            l16++;
        else
            bipasso++;
    }

    sort(computer, computer + N);

    for(int i = N-1, j = 0; i >= 0 && j < M; i--) {
        if(computer[i].second == L10) {
            if(l10 == 0 && bipasso > 0) totale += computer[i].first, bipasso--, j++;
            else if(l10 > 0) totale += computer[i].first, l10--, j++;
        }
        if(computer[i].second == L16) {
            if(l16 == 0 && bipasso > 0) totale += computer[i].first, bipasso--, j++;
            else if(l16 > 0) totale += computer[i].first, l16--, j++;
        }
    }

    printf("%d\n", totale);

    return 0;
}
