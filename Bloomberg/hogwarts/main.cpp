//Problem        : Warrior Of Hogwarts
//Language       : C++

#include <bits/stdc++.h>

using namespace std;

map<int, int> memo;
queue<int> q;

int main() {

    int N;
    cin >> N;

    memo[N] = 0;
    q.push(N);

    while(true) {
        int n = q.front();
        q.pop();
        if(n == 1)
            break;
        if(memo.find(n-1) == memo.end() || memo[n-1] > memo[n] + 1) {
            q.push(n-1);
            memo[n-1] = memo[n]+1;
        }
        if(n % 3 == 0 && (memo.find(n/3) == memo.end() || memo[n/3] > memo[n] + 1)) {
            q.push(n/3);
            memo[n/3] = memo[n]+1;
        }
        if(n % 2 == 0 && (memo.find(n/2) == memo.end() || memo[n/2] > memo[n] + 1)) {
            q.push(n/2);
            memo[n/2] = memo[n]+1;
        }
    }

    cout << memo[1] << endl;
}
