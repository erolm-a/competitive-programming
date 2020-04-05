#include <bits/stdc++.h>

using namespace std;

struct tree {
    bool ending;
    tree* children[26];
    tree(): ending{false} {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
    ~tree() { for(int i = 0; i < 26; i++) if(children[i]) delete children[i];}
};

tree* root;

void insert(string s, tree* t ) {
    //cout << "Inserting " << s << endl;
    for(int i = 0; i < s.size(); i++) {
        tree* ptr = t->children[s[i] - 'A'];
        if(ptr == nullptr) {
            //cout << "Creating new node for letter " << s[i] << endl;
            ptr = t->children[s[i] - 'A'] = new tree;
            ptr->ending = i == s.size() - 1;
        }
        t = ptr;
    }
}

int f(tree* t) {
    bool has_children = false;
    int sum = 0;
    for(int i = 0; i < 26; i++)
        if(t->children[i]) {
            has_children = true;
            sum += f(t->children[i]);
        }
            
    if(!has_children) {
        cout << "No child found, so returning 1\n";
        return 1;
    }
    if(t->ending)
        sum += 1;
    if(t != root && sum >= 2)
        sum -= 2;
    
    cout << "Parent has " << sum << "\n";
    return sum;
}

int main() {
    int tcs;
    cin >> tcs;
    
    for(int tc = 1; tc <= tcs; tc++) {
        int N;
        cin >> N;
        tree t;
        root = &t;
        for(int i = 0; i < N; i++) {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            insert(s, &t);
        }
        cout << "Case #" << tc << ": " <<  N - f(&t) << endl;
    }
}
