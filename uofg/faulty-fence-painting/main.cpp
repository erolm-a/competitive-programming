#include <vector>
#include <stack>
#include <iostream>

using namespace std;
vector<int> count;
vector<int> elems;
vector<bool> taken;

int main(){
    int tc;
    cin >> tc;

    while(tc--) {
        int n, f;
        cin >> n >> f;
        count.clear();
        elems.clear();
        taken.clear();
        count.resize(f+1);
        elems.resize(n);
        taken.resize(f+1);


        for(int i = 0; i < n; i++) {
            cin >> elems[i];
            count[elems[i]]++;
        }

        stack<int> sequence;

        if(count[f] == 0) {
            cout << "NO" << endl;
            continue;
        }

        int i;
        for(i = 0; i < n; i++) {
            if(sequence.empty() || sequence.top() <= elems[i]) {
                if(!taken[elems[i]])
                    sequence.push(elems[i]);
                taken[elems[i]] = true;
                count[elems[i]]--;
                if(count[elems[i]] == 0)
                    sequence.pop();
            }
            else break;
        }
        cout << (i < n ? "NO" : "YES") << "\n";
    }
}
