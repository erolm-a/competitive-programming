#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int nextInt(){
    int n=0 , ch=getchar();
    while( ch < '0' ) ch=getchar();
    while( ch >= '0' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
    return n;
}


static int G[100005];
static int C[100005];
static int da[100005];
static int a [100005];

int pianifica(int N, int M, int da[], int a[], int C[], int G[]);


int main(){
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));

    int N = nextInt();
    int M = nextInt();

    int i;
    for(i=0; i<N; i++){
        G[i] = nextInt();
    }
    for(i=0; i<M; i++){
        C[i] = nextInt();
    }
    for(i=0; i<N-1; i++){
        da[i] = nextInt();
        a[i] = nextInt();
    }


    printf("%d\n", pianifica(N,M,da,a,C,G));

    fclose(stdin);
    fclose(stdout);

    return EXIT_SUCCESS;
}
