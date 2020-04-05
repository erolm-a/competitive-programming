#include <iostream>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    if(m % n) {
        cout << -1 << endl;
        return 0;
    }

    int ris = 0, rem = m/n;
    while(rem != 1) {
        if(rem % 2 == 0)
            ris++, rem /= 2;
        else if(rem % 3 == 0)
            ris++, rem /= 3;
        else {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << ris << endl;

}
