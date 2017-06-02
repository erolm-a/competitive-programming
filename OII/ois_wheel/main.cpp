#include <cstdio>
#include <deque>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_Q 40000
int N, Q;
int minimal, maximal;
deque<int> wheel;
int queries[2*MAX_Q][2];

void preprocess() {
    minimal = min_element(wheel.begin(), wheel.begin() + N) - wheel.begin();
    maximal = max_element(wheel.begin() + N, wheel.end()) - wheel.begin();
    queries[0][0] = wheel[minimal], queries[0][1] = wheel[maximal];

    for(int i = 1; i < 2*N; i++) {
        // rotate
        wheel.push_front(wheel.back());
        wheel.pop_back();


        if(wheel[0] <= queries[i-1][0])
            minimal = 0;
        else if(minimal == N-1)
            minimal = min_element(wheel.begin(), wheel.begin() + N) - wheel.begin();
        else minimal++;

        if(wheel[N] >= queries[i-1][1])
            maximal = N;
        else if(maximal == 2*N - 1)
            maximal = max_element(wheel.begin() + N, wheel.end()) - wheel.begin();
        else
            maximal++;

        queries[i][0] = wheel[minimal], queries[i][1] = wheel[maximal];
    }
    wheel.push_front(wheel.back());
    wheel.pop_back();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    wheel.resize(2*N);
    for(int i = 0; i < 2*N; i++) scanf(" %d", &wheel[i]);

    preprocess();
    scanf("%d", &Q);

    int ciclo = 0;
    for(int i = 0; i < Q; i++)
    {
        int a;
        scanf(" %d", &a);
        ciclo = (ciclo + a) % (2*N);
        fprintf(stderr, "%d\n", ciclo);
        printf("%d %d\n", queries[ciclo][0], queries[ciclo][1]);
    }

    return 0;
}
