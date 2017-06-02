#include <algorithm>

void permute(int subtask, int N, int V[], int R[])
{
    std::sort(V, V + N);

    for(int i = 0; i < N; i++)
        R[i] = (i % 2 ? V[i/2] : V[N - i/2 - 1]);
}
