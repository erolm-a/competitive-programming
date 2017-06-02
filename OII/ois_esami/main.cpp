#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);
    int dp_ultimo[N], dp_primo[N], dp_boh[N];

    for(int i = 0; i < N; i++)
        scanf("%d", &dp_ultimo[i]);

    memcpy(dp_primo, dp_ultimo, N * 4); // sizeof(int) = 4
    memcpy(dp_boh, dp_ultimo, N * 4);

    // primo caso: escludiamo l'ultimo...
    for(int i = N - 4; i >= 0; i--)
        dp_ultimo[i] += *max_element(dp_ultimo + i + 2, dp_ultimo + N - 1);


    for(int i = N - 3; i > 0; i--)
        dp_primo[i] += *max_element(dp_primo + i + 2, dp_primo + N);

    for(int i = N - 4; i > 0; i--)
        dp_boh[i] += *max_element(dp_boh + i + 2, dp_boh + N - 1);



    int max_dp = max(dp_primo[1], max(dp_ultimo[0], dp_boh[2]));
    printf("%d\n", max_dp);


    return 0;
}
