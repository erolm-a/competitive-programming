#include <bits/stdc++.h>

using namespace std;

#define MAX_Q 40000
int N, Q;
int queries[2*MAX_Q][2];
int nums[2*MAX_Q];

template <class compare>
struct my_queue {
    deque<int> D;
    queue<int> Q;
    void push(int x) {
        Q.push(x);
        while(!D.empty() && compare()(D.back(), x))
            D.pop_back();
        D.push_back(x);
    }

    int pop() {
        if(D.front() == Q.front())
            D.pop_front();
        int x = Q.front(); Q.pop(); return x;
    }

    int top() {return D.front();}
};

my_queue<greater<int>> min_q;
my_queue<less<int>> max_q;

void preprocess() {
    for(int i = 0; i < 2*N; i++) {
        queries[i][0] = min_q.top(), queries[i][1] = max_q.top();
        min_q.push(max_q.pop());
        max_q.push(min_q.pop());
    }
}



template<typename Int>
Int readInteger () {
    bool minus = false;
    Int result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

#define readint() readInteger<int>()
int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    N = readint();

    for(int i = 0; i < 2*N; i++)
        nums[i] = readint();

    for(int i = 2*N-1; i >=N; i--)
        max_q.push(nums[i]);
    for(int i = N-1; i >= 0; i--)
        min_q.push(nums[i]);

    Q = readint();
    preprocess();
    int start = 0;
    while(Q--) {
        start = (start + readint()) % (2*N);
        printf("%d %d\n", queries[start][0], queries[start][1]);
    }
}
