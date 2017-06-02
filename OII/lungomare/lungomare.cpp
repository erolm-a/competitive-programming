#include <utility>
#include <algorithm>
#define MAX_L 10000000

struct pll { long long first, second;};

struct {
    pll v[MAX_L+2];
    int i = 0;
    void push(pll val) {v[i++] = val;}
    pll top() const {return v[i-1];}
    void pop() {i--;}
    bool empty() const {return i==0;}
} next_stack;


long long int percorri(int N, long long int L, long long int D[], long long int P[])
{
    next_stack.push(pll{L, -L});

    for(int i = N-1; i >= 0; i--)
        while(true)
        {
            if(P[i] - D[i] <= next_stack.top().second)
                next_stack.pop();
            else {
                if(P[i] + D[i] < next_stack.top().first)
                    next_stack.push(pll{P[i] + D[i], P[i] - D[i]});
            break;
            }
        }

    while(next_stack.top().second >= 0)
        next_stack.pop();

    long long ris = 0;
    ris = next_stack.top().first;

    pll prec = next_stack.top();
    next_stack.pop();
    while(!next_stack.empty())
    {
        pll at = next_stack.top();
        next_stack.pop();
        ris = std::max(ris, at.first + prec.second);
        prec = at;
    }

    return ris;
}
