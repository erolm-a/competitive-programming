#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
string v[MAX_N];
int DP[MAX_N];
int N;

// si salta da a a b
bool close(string& a, string& b)
{
    if(a.size() < b.size() || a.size() - b.size() > 1) return false;

    if(a.size() == b.size())  {
        int i;
        for(i = 0; i < a.size() && a[i] == b[i]; i++);
        char tmp = a[i];
        for(int j = i+1; j < a.size(); j++)
        {
            if(a[j] > a[i]) a[i] = a[j];
            if(a == b) {a[i] = tmp; return true;}
            a[i] = tmp;
        }
    }
    else {
        string tmp;
        for(int i = 0; i < a.size(); i++) {
            tmp = a;
            tmp.erase(i, 1);
            if(tmp == b)     {return true;}

        }
    }
    return false;
}

int main()
{
    ifstream in("input.txt");
    ofstream of("output.txt");

    in >> N;
    for(int i = 0; i < N; i++)
        in >> v[i];

    sort(v, v + N, [](const string & a, const string& b) {return a.size() > b.size() || (a.size() == b.size() && a < b);});
    for(int i = 0; i < N; i++) {
        DP[i] = 1;
        for(int j = 0; j < i; j++)
            if(close(v[j], v[i]))
                DP[i] = max(DP[i], DP[j] + 1);
        }

    of << *max_element(DP, DP + N) << endl;
}
