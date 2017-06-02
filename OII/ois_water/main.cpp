#include <cstdio>
#include <cassert>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_set>

#define MAX_N 10000000
#define LIMIT 1000000000


using namespace std;
int N;

unordered_set<int> visited;
queue<pair<int, int>> bfs;

inline void check(int num, int counter) {
    if(num > LIMIT || visited.find(num) != visited.end())
        return;
    bfs.push(make_pair(num, counter));
    visited.insert(num);
}

int empty() {
    int c = 0;
    bfs.push(make_pair(N, c));
    while(!bfs.empty()) {
        auto x = bfs.front();
        c = x.second;
        bfs.pop();
        if(x.first == 0)
            return c;

        check(x.first * 2, c+1);
        check(x.first+1, c+1);
        check(x.first-1, c+1);
        while(x.first % 3 == 0)
            check(x.first /= 3, c+1);
    }
    return 42;
}

int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    fprintf(fw, "%d\n", empty());
    fclose(fr);
    fclose(fw);
    return 0;
}
