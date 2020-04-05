//Problem        : 2016 Qualifiers - SuperSkills
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
unordered_map<string, int> name2int;
map<int, string> int2name;
vector<int> adj_list[MAX_N];
unordered_set<string> langs[MAX_N];
int N, M;
int root;

void explore() {
    vector<int> sol;
    while(true) {
        bool ok = false;
        for(int i: adj_list[root]) {
            if(langs[i].size()) {
                ok = true;
                break;
            }
        }
        if(!ok) {
            vector<string> names;
            for(int i: sol)
                names.push_back(int2name[i]);
            sort(names.begin(), names.end());
            for(int i = 0; i < sol.size(); i++)
                cout << sol[i]<<",\n"[i==sol.size()-1];
            return;
        }
        // first, erase the languages I know
        for(auto& s: langs[root])
            for(int i: adj_list[root])
                langs[i].erase(s);

        // then, sort the sets by size
        sort(adj_list[root].begin(), adj_list[root].end(), [](int a, int b) {return langs[a].size() < langs[b].size();});

        // eventually, take the skills you don't have from the first set
        langs[root].insert(langs[0].begin(), langs[0].end());
    }
}

int main() {
   cin >> N;

    for(int i = 0; i < N; i++) {
        string s, l;
        cin >> s >> l;
        if(name2int.find(s) == name2int.end()) {
            name2int[s] = i;
            int2name[i] = s;
        }
        langs[name2int[s]].insert(s);
    }
    cin >> M;

    for(int i = 0; i < M; i++) {
        string a, b;
        cin >> a >> b;
        adj_list[name2int[a]].push_back(name2int[b]);
        adj_list[name2int[b]].push_back(name2int[a]);
    }
    string name;
    cin >> name;
    root = name2int[name];
    explore();
    return 0;
}
