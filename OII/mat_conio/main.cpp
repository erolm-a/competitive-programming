#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100000
int primi[MAX_N], top, conio;
bool vet[MAX_N+1];

void init() {
    for(int i = 2; i < MAX_N; i++)
        if(!vet[i]) {
            primi[top++] = i;
            for(int j = i*2; j < MAX_N; j+=primi[top-1])
                vet[j] = true;
        }
    for(int i = 0; i < top; i++)
        fprintf(stderr, "%d\n", primi[i]);
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &conio);
    init();
    if(!vet[conio])
        printf("2\n");
    else {
        int ris = 1;
        while(conio > 1)
            for(int i = 0; primi[i] <= conio; i++)
                if(conio % primi[i] == 0) {
                    ris++, conio /= primi[i];
                    i--;
                }

        printf("%d\n", ris);
    }

}
