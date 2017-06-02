#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX 5000

unsigned max_budget, N;

int tot;
vector<unsigned> sol;
unsigned int prezzo[MAX];

void risolvi(int budget, size_t disponibile, vector<unsigned> usati) {
    if(budget == 0) {
        tot = 0;
        sol = usati;
        return;
    }
    if(budget > 0 && budget < tot) {
        tot = budget;
        sol = usati;
    }
    if(budget < 0 || disponibile == N)
        return;
    risolvi(budget, disponibile + 1, usati);
    usati.push_back(prezzo[disponibile]);
    risolvi(budget - prezzo[disponibile], disponibile + 1, usati);
}

int main() {
    FILE* in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");

    fscanf(in, "%d %d", &N, &max_budget);
    tot = max_budget;

    for(size_t i = 0; i < N; i++)
        fscanf(in, " %d", &prezzo[i]);


    risolvi(max_budget, 0, {});
    for(auto i: sol)
        fprintf(out, "%d\n", i);

    fclose(in);
    fclose(out);
}
