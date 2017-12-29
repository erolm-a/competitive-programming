#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10000
unordered_map<string, int> cif;

void convert(string& a, int k) {
    for(char &i: a)
        if(i - k >= 'a')
            i-=k;
       else i = i+26-k;
}
int main()
{
    ifstream in("input.txt");
    ofstream of("output.txt");

    int N, D;

    in >> N >> D;

    for(int i = 0; i < N; i++)
    {
        string w;
        in >> w;
        if(w[0] != 'a')
            convert(w, w[0] - 'a');
        cif[w]++;
    }

    int m = 0;
    for(auto& i: cif)
        m = max(m, i.second);

    of << m << endl;
}
