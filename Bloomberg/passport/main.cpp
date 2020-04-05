#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<pair<int, int>> booth;

    int N, M;
    cin >> N >> M;
    int counter[N];
    fill(counter, counter + N, 0);

    for(int i = 0; i < N; i++) {
        booth.insert(make_pair(0, i));
    }
    while(M--) {
        int x;
        cin >> x;
        auto it = booth.begin();
        int sum = it->first, pos = it->second;
        booth.erase(it);
        counter[pos]++;
        if(counter[pos] % 10 == 0)
            booth.insert({sum + x + 5, pos});
        else
            booth.insert({sum + x, pos});

    }

    for(int i = 0; i < N; i++)
        cout << counter[i] << ' ';
    cout << endl;
}
