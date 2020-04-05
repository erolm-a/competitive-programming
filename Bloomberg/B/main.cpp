#include <bits/stdc++.h>

using namespace std;

#define FOR(a,b) for(int i = a; i < b; i++)
#define FOR_REV(a,b) for(int i = a; i >= b; i--)

int k;
bool diff_only_two(string&a, string& b) {
    int ctr = 0;
    FOR(0, k) {
        if(a[i] != b[i]) ctr++;
        if(ctr > 2) return false;
    }
    return ctr == 2;
}
int main()
{
    int alpha_size, n;
    set<string> strs;
    string input;

    cin >> alpha_size >> input >> n >> k;

    FOR(0, n) {
        cin >> input;
        strs.insert(input);
    }

    // make array from list
    vector<string> elems(strs.size());
    copy(strs.begin(), strs.end(), elems.begin());

    int ris = 0;
    for(int i = 0; i < elems.size(); i++)
        for(int j = i+1; j < elems.size(); j++)
            if(diff_only_two(elems[i], elems[j]))
                ris ++;

    cout << ris << "\n";
}
