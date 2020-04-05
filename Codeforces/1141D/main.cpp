#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;

    int n;
    cin >> n;
    cin >> a >> b;

    set<int> first_sets[27], second_sets[27];

    for(int i = 0; i < a.size(); i++)
        first_sets[isalpha(a[i]) ? a[i] - 'a' : 26].insert(i);

    for(int i = 0; i < b.size(); i++)
        second_sets[isalpha(b[i]) ? b[i] - 'a' : 26].insert(i);

    vector<pair<int, int>> matching;

    for(int i = 0; i < 26; )
        if(min(first_sets[i].size(), second_sets[i].size())) {
            matching.push_back({*first_sets[i].begin(), *second_sets[i].begin()});
            first_sets[i].erase(first_sets[i].begin());
            second_sets[i].erase(second_sets[i].begin());
        } else i++;

    // check pairs between first jollies and second set

    for(int i = 0; i < 27 && first_sets[26].size();) {
        if(second_sets[i].size()) {
            matching.push_back({*first_sets[26].begin(), *second_sets[i].begin()});
            first_sets[26].erase(first_sets[26].begin());
            second_sets[i].erase(second_sets[i].begin());
        }
        else i++;
    }

    // opposite
    for(int i = 0; i < 27 && second_sets[26].size();) {
        if(first_sets[i].size()) {
            matching.push_back({*first_sets[i].begin(), *second_sets[26].begin()});
            second_sets[26].erase(second_sets[26].begin());
            first_sets[i].erase(first_sets[i].begin());
        } else i++;
    }

    cout << matching.size() << endl;
    for(int i = 0; i < matching.size(); i++)
        cout << matching[i].first + 1 << ' ' << matching[i].second + 1 << endl;
}
