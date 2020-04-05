#include <bits/stdc++.h>

using namespace std;
int main() {
    int tcs;
    cin >> tcs;
    for(int tc = 1; tc <= tcs; tc++) {
        cout << "Case #" << tc << ": ";
        string N;
        cin >> N;
        vector<int> A, B;
        A.resize(N.size());
        B.resize(N.size());
        for(int i = 0; i < N.size(); i++)
            if(N[i] != '4')
                A[i] = N[i] - '0', B[i] = 0;
            else A[i] = B[i] = 2;
            
        int start = 0;
        while(A[start] == 0) start++;
        for(int i = start; i < A.size(); i++)
            cout << A[i];
        cout << ' ';
        
        start = 0;
        while(B[start] == 0) start++;
        for(int i = start; i < A.size(); i++)
            cout << B[i];
        cout << endl;
    }
}
