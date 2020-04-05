#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


struct StackWithMin {
    stack<pair<int, int>> S;

    void push(int x) {
        S.push(make_pair(x, S.empty() ? x : min(S.top().second, x)));
    }

    int pop() {
        int x = S.top().first;
        S.pop();
        return x;
    }

    int get_min() {
        return S.top().second;
    }

    bool empty() {return S.empty();}
};



struct QueueWithStack {
    stack<int> s1, s2;

    void push(int x) {
        s2.push(x);
    }

    int pop() {
        if(!s1.size())
            while(s2.size()) {
                int x = s2.top();
                s2.pop();
                s1.push(x);
            }
        int x = s1.top();
        s1.pop();
        return x;
    }

    bool empty() {return s1.empty() && s2.empty();}
};

struct QueueWithMin {
    stack<pair<int, int>> s1, s2;

    void push(int x) {
        s2.push(make_pair(x, s2.empty() ? x : min(s2.top().second, x)));
    }

    int pop() {
        if(s1.empty()) {
            while(!s2.empty()) {
                auto x = s2.top();
                s2.pop();
                x.second = s1.empty() ? x.first : min(x.first, s1.top().second);
                s1.push(x);
            }
        }
        auto x = s1.top(); s1.pop();
        return x.first;
    }

    int get_min() {
        return s1.empty() ? s2.top().second : (s2.empty()? s1.top().second : min(s1.top().second, s2.top().second));
    }

    bool empty() {return s1.empty() && s2.empty();}
};

int main()
{
    QueueWithStack qws;
    qws.push(1);
    qws.push(2);
    qws.push(3);

    for(int i = 0; i < 3; i++)
        qws.push(qws.pop()*3);
    while(!qws.empty())
        cout << qws.pop() << '\n';

    QueueWithMin qwm;
    qwm.push(3);
    qwm.push(2);
    qwm.push(4);
    qwm.push(5);
    //qwm.push(0);

    while(!qwm.empty()) {
        cout << "Minimo attuale: " << qwm.get_min() << '\n';
        qwm.pop();
    }
}
