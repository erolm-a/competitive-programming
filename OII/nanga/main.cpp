#include <cstdio>
#include <map>

using namespace std;

int main()
{
    // spero che l'altitudine non diventi mai negativa
    map<int, int> freqs;
    int last = 5000, N, max_freq = 1, freq_temp = 5000, misurato;
    freqs[5000] = 1;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &N);

    while(N--) {
        scanf("%d", &misurato);
        last += misurato;
        if(++freqs[last] > max_freq)
            max_freq = freqs[last], freq_temp = last;
    }
    printf("%d\n", freq_temp);
    return 0;
}
