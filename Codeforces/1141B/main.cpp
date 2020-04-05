#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<bool> a;

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x == 1;
    }

    int count = 0;
    int max_count = count;
    //find most repeated string


    // just count backwards

    int backwards = 0;
    for(int i = n-1; a[i] && i >= 0; i--, backwards++)
        ;

    for(int i = 0; i < n; i++) {
        if(a[i]) {
            for(count = i == 0 ? backwards : 0; i < n && a[i]; i++, count++)
                ;
            if(max_count < count)
                max_count = count;
        }
    }

    cout << max_count;

}
