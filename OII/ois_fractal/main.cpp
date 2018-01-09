#include <cstdio>

using namespace std;

#define MODULO 32749
int coeffs[32][4] = {{3, 2, 3, 3}};

int main()
{
    int N;
    scanf("%d", &N);
    int e = 1, s = 0;
    for(int i = 0; i < 32; i++) {
        if(i > 0) {
            coeffs[i][0] = (coeffs[i-1][0]*coeffs[i-1][0] + coeffs[i-1][1]*coeffs[i-1][2]) % MODULO;
            coeffs[i][1] = (coeffs[i-1][0]*coeffs[i-1][1] + coeffs[i-1][1]*coeffs[i-1][3]) % MODULO;
            coeffs[i][2] = (coeffs[i-1][2]*coeffs[i-1][0] + coeffs[i-1][3]*coeffs[i-1][2]) % MODULO;
            coeffs[i][3] = (coeffs[i-1][2]*coeffs[i-1][1] + coeffs[i-1][3]*coeffs[i-1][3]) % MODULO;
        }

        if(N & (1<<i)) {
            int temp_e = e;
            e = (e*coeffs[i][0] + s*coeffs[i][1]) % MODULO;
            s = (temp_e*coeffs[i][2] + s*coeffs[i][3]) % MODULO;
        }
    }
    printf("%d %d\n", e, s);
}
