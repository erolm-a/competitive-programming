#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int dp[100] = {1};
set<int> coins;
bool expressable(int i) {
    if(i < *coins.begin()) {
        if(i > 0) dp[i] = -1;
        return false;
    }
    if(dp[i]) return dp[i] == 1;
    for(int j: coins)
        if(expressable(i - j)) return (dp[i] = 1);
    dp[i] = -1; return false;
}
int main()
{
    int N;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;
    while(N--) {
        int k;
        in >> k;
        coins.insert(k);
        dp[k] = 1;
    }
    for(int i = *coins.begin()+1; i < 100; i++)
        if(!expressable(i)) {
            out << i;
            return 0;
        }
}
