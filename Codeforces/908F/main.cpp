#include <bits/stdc++.h>

using namespace std;

#define MAX_N 300000
int n[MAX_N], c[MAX_N];
int N;


int main()
{
    set<int> col_closer[3];


    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf(" %d", n + i);
        char co;
        scanf(" %c", &co);
        switch (co) {
        case 'R':
            c[i] = 0;
            break;
        case 'B':
            c[i] = 1;
            break;

        case 'G':
            c[i] = 2;
            break;
        }
        col_closer[c[i]].insert(i);
    }


    int last = -1;
    long long ris = 0;
    for(int i: col_closer[2])
    {
        if(i != *col_closer[2].begin())
            ris += n[i] - n[last];
        last = i;
    }


    for(int color = 0; color < 2; color++)
        for(int i: col_closer[color]) {
            long long diff = LLONG_MAX; int tmp;
            if(*col_closer[color].begin() != i)
                tmp = *col_closer[color].lower_bound(i-1),
                        diff = n[i] - n[tmp];
            if(col_closer[2].lower_bound(i) != col_closer[2].end()) {
                tmp = *col_closer[2].lower_bound(i);
                if(n[i] - n[tmp] < diff)
                    diff = n[i] - n[tmp];
            }

            if(col_closer[2].upper_bound(i) != col_closer[2].end()) {
                tmp = *col_closer[2].upper_bound(i);
                if(n[tmp] - n[i] < diff)
                        diff = n[i] - n[tmp];
            }
            ris += diff;
    }

    printf("%lld\n", ris);
}
