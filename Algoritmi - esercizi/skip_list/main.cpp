#include <bits/stdc++.h>

using namespace std;
//struct node {
//    int key;
//    node** nxt;
//    node(int k, size_t s): key{k}, nxt{new node*[s+1]} {
//        fill(nxt, nxt + s+1, nullptr);
//    }
//};
//struct skiplist {
//    size_t maxlvl;
//    size_t level{0}; // actual skiplist height
//    size_t random_level() {
//        size_t r = rand(), l = 0;
//        while(l < maxlvl && r & 1) l++, r>>=1;
//        return l;
//    }
//    node* _header;
//    skiplist(size_t m): maxlvl{m}, _header{new node(-1, maxlvl)} {}
//    void insert(int key) {
//        node *c = _header;
//        node *update[maxlvl + 1];
//        fill(update, update + maxlvl+1, nullptr);
//        for(int i = level; i >= 0; i--) {
//            while(c->nxt[i] != nullptr && c->nxt[i]->key < key)
//                c = c->nxt[i];
//            update[i] = c;
//        }
//        if((c = c->nxt[0]) == nullptr || c->key != key) {
//            auto rlevel = random_level();
//            if(rlevel > level) {
//                for(auto i = level+1; i < rlevel+1; i++)
//                    update[i] = _header;
//                level = rlevel;
//            }
//            node *n = new node(key, rlevel);
//            for(int i = 0; i<=rlevel;i++) {
//                n->nxt[i] = update[i]->nxt[i];
//                update[i]->nxt[i] = n;
//            }
//        }
//    }
//    void display()
//    {
//        cout<<"\n*****Skip List*****"<<"\n";
//        for (size_t i=0;i<=level;i++)
//        {
//            node *n = _header->nxt[i];
//            cout << "Level " << i << ": ";
//            while (n != nullptr) {
//                cout << n->key<<" ";
//                n = n->nxt[i];
//            }
//            cout << "\n";
//        }
//    }
//};
const int INF=2e9;

struct skip_list
{
    struct node
    {
        int num;
        vector<node*> nxt;
        vector<node*> prv;
        node(int x):num(x){}
    } *begin,*end;

    skip_list()
    {
        begin=new node(-INF);
        end  =new node(+INF);
        begin->nxt={  end};
        begin->prv={    0};
        end  ->nxt={    0};
        end  ->prv={begin};
    }

    node *find(int x)
    {
        node *cur=begin;
        int cl=begin->nxt.size();
        while(cl>=0)
        {
            while(cl<cur->nxt.size() && cur->nxt[cl]->num<x) cur=cur->nxt[cl];
            cl--;
        }
        return cur->nxt[0];
    }
    void insert(int x)
    {
        node *r=find(x);
        node *l=r->prv[0];
        node *it=new node(x);
        int cl=-1;
        while(cl==-1 || rand()%2)
        {
            cl++;
            if(cl>=begin->nxt.size())
            {
                begin->nxt.push_back(0);begin->prv.push_back(0);
                end  ->nxt.push_back(0);end  ->prv.push_back(0);
            }
            while(cl>=l->nxt.size())  l=l->prv[cl-1];
            while(cl>=r->nxt.size())  r=r->nxt[cl-1];
            l->nxt[cl]=it;
            r->prv[cl]=it;
            it->nxt.push_back(r);
            it->prv.push_back(l);
        }

    }

    void erase(int x)
    {
        node *it=find(x);
        for(int i=0;i<it->nxt.size();i++)
        {
            it->nxt[i]->prv[i]=it->prv[i];
            it->prv[i]->nxt[i]=it->nxt[i];
        }
        delete it;
    }
} ;
int main()
{
    srand((unsigned) time(NULL));

    vector<int> test;
    for(int i = 0; i < 20; i++)
        test.push_back(i);
    random_shuffle(test.begin(), test.end());

    skip_list lst;
    for(int i: test)
        lst.insert(i);

    return 0;
}
