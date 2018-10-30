#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N, l = 0, d = 0, r = 0, u = 0;
    cin >> N;
    for(int i = 0;i < N;i++)
    {
        char c;
        cin >> c;
        switch (c) {
        case 'L':
            l++;
            break;
        case 'R':
            r++;
            break;
        case 'D':
            d++;
            break;
        case 'U':
            u++;
            break;
        default:
            break;
        }
    }
    cout << 2*(min(l, r) + min(u, d)) << '\n';
}
