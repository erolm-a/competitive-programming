#include <algorithm>
#include <cstdio>

using namespace std;

int fibonacci[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
                   1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025,
                   121393, 196418, 317811, 514229, 832040, 1346269};

int main()
{
    int N;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    char ris[] = "0000000000000";

    int len;


    while(N > 0)
    {
        int i = lower_bound(fibonacci, fibonacci + sizeof(fibonacci) / sizeof(int), N) - fibonacci;
        if(fibonacci[i] != N) i--;
        ris[i] = '1';
        N -= fibonacci[i];
    }

    len = 0;
    for(int i = 0; i < 31; i++)
        if(ris[i] != '0') len = i;
    ris[len+1] = '\0';
    printf("%s\n", ris);
}
