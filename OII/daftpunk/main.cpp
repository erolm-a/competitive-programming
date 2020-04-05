#include <bits/stdc++.h>

using namespace std;

#define ALPHABET 26
struct prefix_tree {
    struct node {
        bool isword{false};
        int counter{1};
        node* elems[ALPHABET];
        node(bool end=false): isword{end} {fill(elems, elems + ALPHABET, nullptr);}
        void insert(char c, bool end=false) {elems[c-'a'] = new node(end);}
        ~node() {for(int i = 0; i < ALPHABET; i++) if(elems[i]) delete elems[i];}
    };

    node* root;
    prefix_tree() {root = new node;}
    template<typename it>
    void insert_word(it begin, it end) {
        for(node*r = root; begin != end; r = r->elems[*begin-'a'], begin++)
            if(!r->elems[*begin-'a']) r->insert(*begin, begin+1==end);
            else r->elems[*begin-'a']->counter++;
    }

    void lcp() {
        vector<node*> pos;
        for(int i = 0; i < ALPHABET; i++)
            if(root->elems[i] && root->elems[i]->counter > 1)
                pos.push_back(root->elems[i]);
        // potenzialmente

    }

    void print(node* r) {
        if(r->isword) cout << "FOUND A WORD!\n";
        for(int i = 0; i < ALPHABET; i++)
            if(r->elems[i]) {
                cout << (char) ('a' + i) << '\n';
                print(r->elems[i]);
            }
    }
};

int main()
{
    prefix_tree s;
    string v[] = {"ever", "every", "never", "nowhere", "noway", "ok"};
    for(int i = 0; i < 6; i++)
        s.insert_word(v[i].begin(), v[i].end());

    s.print(s.root);
}
