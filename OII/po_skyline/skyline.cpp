#define MAX_H 2000000-1
#define MAX_N 1000000

bool max_before[MAX_N];
bool max_after[MAX_N];

int valuta(int N, int* H) {
    max_before[0] = false;
    int cur_max = H[0];
    for(int i = 1; i < N; i++)
        if(H[i] > cur_max)
            cur_max = H[i], max_before[i] = false;
        else max_before[i] = true;

    cur_max = H[N-1];
    for(int i = N-2; i >= 0; i--)
        if(H[i] > cur_max)
            cur_max = H[i], max_after[i] = false;
        else max_after[i] = true;

    int res = 0;
    for(int i = 1; i < N-1; i++)
        if(max_before[i] && max_after[i]) res++;
    return res;
}

void progetta(int N, int K, int* H) {
    H[0] = MAX_H;
    for(int i = 1; i <= K; i++)
        H[i] = i*2-1;

    H[K+1] = MAX_H-2;
    for(int i = K+2; i < N; i++)
        H[i] = H[i-1]-2;
}
