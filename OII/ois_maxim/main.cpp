#include <bits/stdc++.h>
using namespace std;

struct myqueue {
    queue<int> q;
    deque<int> d;

    void pop() {int x = q.front(); q.pop(); if(x == d.front()) d.pop_front();}
    int top() {return d.front();}
};

struct minqueue: public myqueue {
    void push(int x) {
        q.push(x);
        while(d.size() && x < d.back())
            d.pop_back();
        d.push_back(x);
    }
};

struct maxqueue: public myqueue {
    void push(int x) {
        q.push(x);
        while(d.size() && x > d.back())
            d.pop_back();
        d.push_back(x);
    }
};



int main() {
    int N, K;
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    K++;

    minqueue minq; maxqueue maxq;

    while(N--, K--)
    {
        int x; cin >> x;
        minq.push(x);
        maxq.push(x);
    }
    int sadness = maxq.top() - minq.top();
    while(N-- > 0)
    {
        int x; cin >> x;
        maxq.pop(); minq.pop();
        maxq.push(x);
        minq.push(x);
        sadness = max(sadness, maxq.top() - minq.top());
    }
    cout << sadness;
}
