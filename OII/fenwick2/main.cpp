#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_N 1000000
#define MODULO 1000000007ll
int N, S[MAX_N];
vector<int> assoc;
long long fen_tree[MAX_N+2];
void update(int i, long long val) {i++; do fen_tree[i]+=val, fen_tree[i]%=MODULO; while((i+=(i & -i)) <= N+1);}
long long query(int i)
{
    i++;
    long long res = 0;
    while(i) {
        res+=fen_tree[i];
        res%=MODULO;
        (i -= (i & -i));
    }
    return res;
}

int readInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    N = readInt();
    for_each(S, S + N, [](int& i){i = readInt();});
    int tempS[MAX_N];
    memcpy(tempS, S, sizeof S);
    sort(tempS, tempS + N);
    assoc.push_back(tempS[0]);
    for(int i = 1; i < N; i++)
        if(tempS[i] != assoc.back())
            assoc.push_back(tempS[i]);

    for(int i = 0; i < N; i++) {
        auto p = lower_bound(assoc.begin(), assoc.end(), S[i]) - assoc.begin();
        update(p, query(p-1)+1);
    }
    printf("%lld\n", query(assoc.size()));
}
