#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1001
int main()
{
    ifstream in("input.txt");
    ofstream of("output.txt");

    int N;
    long long DP[MAX_N], V[MAX_N];

    in >> N;
    for(int i = 0; i < N; i++)
        in >> V[i];
    sort(V, V + N);

    DP[0] = 1;
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < i; j++)
            if(V[i] % V[j] == 0)
                DP[i] = max(DP[i], DP[j] + 1);
    }

    of << *max_element(DP, DP + N) << endl;
}
