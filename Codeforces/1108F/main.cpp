#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200001
vector<int> elements;

template<int N>
struct DSU {
    minstd_rand my_rand; // faster than Twister-Mersenne
    int parent[N];
    DSU() {
        iota(parent, parent + N, 0);
    }
    int find(int i) {
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    bool merge(int i, int j) {
        i = find(i);
        j = find(j);
        if(i == j) return false;

        if(this->my_rand() % 2) // seems it's got a randomized O(ack^-1(N)) complexity!
            swap(i, j);
        parent[i] = j;
        return true;
    }
};

using edge = tuple<int, int, int>;

DSU<MAX_N> dsu;

int main()
{
    vector<tuple<int, int, int>> edges;
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(c, a, b);
    }

    sort(edges.begin(), edges.end());
    int ris = 0;
    for(int i = 0; i < m;) {
        int weight;
        tie(weight, ignore, ignore) = edges[i];

        int limit = i;
        while(limit < m && get<0>(edges[limit]) == weight) limit++;

        int cnt = limit - i;
        for(int j = i; j < limit; j++)
            if(dsu.find(get<1>(edges[j])) == dsu.find(get<2>(edges[j])))
                cnt--;
        for(int j = i; j < limit; j++) {
            int a, b; tie(ignore, a, b) = edges[j];
            cnt -= dsu.merge(a, b);
        }

        ris += cnt;

        i = limit;
    }
    cout << ris << endl;
}
