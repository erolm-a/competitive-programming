#include <bits/stdc++.h>

using namespace std;


int ContaOperazioni(int N, int K, int* secchi)
{
    int sum = 0;

    vector<int> carenti, eccedenti;

    for(int i = 0; i < N; i++)
        if(secchi[i] > K)
            eccedenti.push_back(secchi[i]);
        else if(secchi[i] < K)
            carenti.push_back(secchi[i]);

    for(int i = 0, j = 0; i < eccedenti.size() && j < carenti.size();)
    {
        int delta = min(K - carenti[j], eccedenti[i] - K);
        // se posso darglieli
        carenti[j] += delta;
        eccedenti[i] -= delta;
        if(carenti[j] == K) j++;
        if(eccedenti[i] == K) i++;
        sum += delta;
    }

    for(int i: carenti)
        sum += (K - i);

    for(int i: eccedenti)
        sum += (i - K);

    return sum;
}
