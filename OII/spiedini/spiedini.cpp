#include <bits/stdc++.h>

int max_strawberries = 0;
int solve(int N, int K, int* S)
{
    int p, s = N;
    int toll_s;

    if(S[0] > K) // corner case: non è prendibile nessun frutto da destra
    {
        for(s = N-1, toll_s = 0; s >= 0 && toll_s + S[s] <= K; toll_s += S[s], s--)
            if(S[s] == 0) max_strawberries++;
        return max_strawberries;
    }

    for(p = 0, toll_s = 0;
        p < N && toll_s + S[p] <= K; toll_s += S[p], p++)
        if(S[p] == 0) max_strawberries++;
    if(p == N) return max_strawberries;
    if(p > 0) p--;


    int cur_strawberries = max_strawberries;

    do{
        while(s > p && toll_s + S[s-1] <= K)
        {
            s--;
            if(S[s] == 0) cur_strawberries++;
            toll_s += S[s];
        }

        max_strawberries = std::max(max_strawberries, cur_strawberries);
        toll_s -= S[p];
        if(S[p] == 0) cur_strawberries--;
        p--;
    } while(p >= 0);

    while(s > p && toll_s + S[s-1] <= K)
    {
        s--;
        if(S[s] == 0) cur_strawberries++;
        toll_s += S[s];
    }
    max_strawberries = std::max(max_strawberries, cur_strawberries);

    return max_strawberries;
}
