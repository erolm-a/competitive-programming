#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> temp, p, q;
    int n;

    cin >> n;
    p.resize(n);
    q.resize(n-1);
    for(int i = 0; i < n-1; i++)
        cin >> q[i];

    for(int i = 0; i < n-1; i++)
        p[i+1] = p[i] + q[i];

    temp = p;
    sort(temp.begin(), temp.end());

    for(int i = 1; i < n; i++) {
        if(temp[i] != temp[i-1] + 1) {
            cout << -1;
            return 0;
        }
    }

    int to_add = -*min_element(p.begin(), p.end()) + 1;
    for(int i = 0; i < n; i++)
        cout << p[i] + to_add << ' ';


}
