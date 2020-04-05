#include <bits/stdc++.h>

using namespace std;

set<int> taken;
int N, D;
#define MAX_N 12
int elems[MAX_N];
int best_sol = 0;

void maytake(int i) {
    if(i >= N) {
        best_sol = max(best_sol, (int) taken.size());
        return;
    }
    maytake(i+1);
    if(taken.find(elems[i]) == taken.end()) {
        taken.insert(elems[i]);
        maytake(i + D);
        taken.erase(elems[i]);
    }
}
int main() {
    int k;
    cin >> N >> k >> D;

    for(int i = 0; i < N; i ++)
        cin >> elems[i];

    maytake(0);

    cout << best_sol;
}
