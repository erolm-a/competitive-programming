#include <bits/stdc++.h>

using namespace std;

string n;
bool palindromic()
{
    for(int i = 0; i < n.size()/2; i++)
        if(n[i] != n[n.size() - i - 1])
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;

    int zeros = 0;
    if(palindromic()) {cout << "YES\n"; return 0;}
    for(int i = n.size()-1; i>=0 && n[i] == '0'; i--)
        zeros++;

    n = string(zeros, '0') + n;
    if(palindromic()) {cout << "YES\n"; return 0;}
    else cout << "NO\n";
    return 0;
}
