#include <cstdio>
#include <cassert>
#include <queue>

int N, K;

using namespace std;
priority_queue<int, vector<int>, greater<int>> deck;
int somma;

int round(int C) {
    if(deck.size() < static_cast<unsigned>(K)) {
        deck.push(C);
        somma += C;
    }
    else if(deck.top() < C) {
        somma -= deck.top();
        somma += C;
        deck.pop();
        deck.push(C);
    }
    return somma;
}


int main() {
    FILE *fr, *fw;
    int C, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++) {
        assert(1 == fscanf(fr, "%d", &C));
        fprintf(fw, "%d ", round(C));
    }
    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
