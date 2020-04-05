#include <bits/stdc++.h>

using namespace std;

int main() {
    int tcs;
    cin >> tcs;

    for(int tc = 1; tc <= tcs; tc++) {
        cout << "Case #" << tc << ": ";
        int N;
        cin >> N;
        string risp;
        cin >> risp;
        for(char ch: risp)
            if(ch == 'E')
                cout << 'S';
            else
                cout << 'E';
        cout << endl;
    }
}
