#include <stack>
#include <vector>
#include <cstdio>

using namespace std;

int pesci[100000];
short direzione[100000];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)    
        scanf("%hd %d", &direzione[i], &pesci[i]);

    int sin = 0;
    stack<int> destra;

    for(int i = 0; i < N; i++) {
        if(direzione[i] == 0)
            destra.push(pesci[i]);
        else {
            while(destra.size() > 0 && destra.top() < pesci[i])
                destra.pop();
            if(destra.size() == 0) sin++;
        }
    }
    printf("%ld\n", destra.size() + sin);
}
