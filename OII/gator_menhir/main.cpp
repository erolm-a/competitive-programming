#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10000
int main()
{
    ifstream i_f("input.txt");
    ofstream o_f("output.txt");
    int pesi[MAX_N];
    int N;

    i_f >> N;
    for(int i = 0; i < N; i++)
        i_f >> pesi[i];

    sort(pesi, pesi + N);
    int ris = 0;

    int l = 0, h = N-1;
    while(l < h)
    {
        if(pesi[l] + pesi[h] <= 400)
            l++;
        h--;
        ris++;
    }
    if(l == h) ris++;

    o_f << ris << endl;
}
