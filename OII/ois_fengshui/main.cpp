#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>

#define MAX_N 1000

using namespace std;
vector<int> horiz[MAX_N+1];
bitset<MAX_N+1> flagged[MAX_N+1];

int N;

int calculate() {
    int max_l = 0;
    for(int i = 0; i < MAX_N; i++)
        if(horiz[i].size()) {
            sort(horiz[i].begin(), horiz[i].end());
            for(int j = 0; j < horiz[i].size() - 1; j++)
                for(int k = j+1; k < horiz[i].size() &&
                    i + horiz[i][k] - horiz[i][j] <= MAX_N; k++)
                    if(flagged[i+horiz[i][k]-horiz[i][j]][horiz[i][j]] &&
                       flagged[i+horiz[i][k]-horiz[i][j]][horiz[i][k]] &&
                       horiz[i][k] - horiz[i][j] > max_l)
                        max_l = horiz[i][k] - horiz[i][j];
        }
    return max_l;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        flagged[y][x] = true;
        horiz[y].push_back(x);
    }
    printf("%d\n", calculate());

    return 0;
}
