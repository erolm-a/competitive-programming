#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int c, even = 0, odd = 0;
    while(N--) {
        cin >> c;
        if(c%2==0) even++;
    }
    if(even <= 1)
        cout << "NO\n";
    else cout << "YES\n";
}
