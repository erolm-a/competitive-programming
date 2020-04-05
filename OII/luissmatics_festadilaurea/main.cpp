#include <fstream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int P[4] = {2, 4, 5, 7};
int prices[4], num[4];

int DP[101][4];

int min_cost(int persone, int cur = 0) {
    int costo = INT_MAX;
    if(persone <= 0) return 0;
    if(DP[persone][cur] != INT_MAX) return DP[persone][cur];
    if(cur == 3) {
        int limit = ceil((float)persone/P[3]);
        if(persone > limit)
            return INT_MAX;
        return DP[persone][3] = limit*prices[3];
    }

    int limit = min(num[cur], (int)ceil((float)persone/P[cur]));
    for(int i = 0; i <= limit; i++) {
        int other = min_cost(persone - i*P[cur], cur+1);
        if(other == INT_MAX) continue;
        costo = min(costo, i*prices[cur]+other);
    }

    return DP[persone][cur] = costo;
}
int main()
{
    fill(*DP, *DP + 101*4, INT_MAX);
    int persone;
    ifstream in("input.txt");
    in >> persone;
    for(int i = 0; i < 4; i++)
        in >> num[i] >> prices[i];
    ofstream("output.txt") << min_cost(persone);
}
