#include <iostream>
#include <vector>

using namespace std;

vector<int> z;

void z_function(const string& s) {
    const int n = s.size();

    z.resize(n);

    for(int i = 1, l = 0, r = 0; i < n; i++) {
        if(i <= r)
            z[i] = min(z[i-l], r-i+1);
        while(i + z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

vector<int> found;
void string_matching(const string& haystack, const string& needle) {
    string p = needle + '$' + haystack;
    z_function(p);

    for(int i = needle.size()+1; i < p.size(); i++)
        if(z[i] == needle.size()) found.push_back(i - needle.size()-1);
}

int main()
{
    string haystack, needle;
    cin >> haystack >> needle;
    string_matching(haystack, needle);
    for(int i: found)
        cout << i << ' ';
    cout << endl;
}
