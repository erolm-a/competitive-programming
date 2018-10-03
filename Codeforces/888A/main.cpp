#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int V[N];

    for(int i = 0; i < N; i++)
        cin >> V[i];

    int res = 0;
    for(int i = 1; i < N - 1; i++)
        if((V[i] > V[i-1] && V[i] > V[i+1]) ||
                (V[i] < V[i-1] && V[i]<V[i+1]))
            res++;

    cout << res << '\n';
    return 0;
}
