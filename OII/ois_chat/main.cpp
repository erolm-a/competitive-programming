#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

#define MAX_N 100000
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);
    char username[10];
    unordered_set<string> used;
    vector<string> us_list;
    for(int i = 0; i < N; i++) {
        scanf(" %10s", username);
        us_list.push_back(string(username));
    }
    for(auto p = us_list.rbegin(); p != us_list.rend(); p++)
        if(used.find(*p) == used.end()) {
            used.insert(*p);
            printf("%s\n", p->c_str());
        }

    return 0;
}
