#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dim;

int main()
{
    vector<int> N;
    vector<int> R;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%*d %d", &dim);
    N.resize(dim);
    R.resize(dim);

    for(int i = 0; i < dim; i++)
        scanf("%d", &N[i]);

    sort(N.begin(), N.end());

    for(int i = 0; i < dim; i++)
        R[i] = (i % 2 ? N[i/2] : N[dim - i/2 - 1]);

    for(int i: R)
        printf("%d ", i);
    printf("\n");

    return 0;
}
