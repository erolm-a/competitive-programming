#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int disp[] = {0, -1}, par[] = {0, -1}, N;
    int pari = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int c;
        scanf("%d", &c);
        if(c % 2) {
            if(c > disp[1]) {
                if(c > disp[0]) {
                    swap(disp[0], disp[1]);
                    disp[0] = c;
                }
                else disp[1] = c;
            }
        } else {
            if(c > par[1]) {
                if(c > par[0]) {
                    swap(par[0], par[1]);
                    par[0] = c;
                }
                else par[1] = c;
            }
            pari++;
        }
    }
    int M = 0;
    if((N == 1 && pari == 0) || (N == 2 && pari == 1)) M = -1;
    else if(disp[1] == -1 && par[1] != -1) M = par[0] + par[1];
    else if(par[1] == -1 && disp[1] != -1) M = disp[0] + disp[1];
    else M = max(disp[0] + disp[1], par[0] + par[1]);
    printf("%d\n", M);
    return 0;
}
