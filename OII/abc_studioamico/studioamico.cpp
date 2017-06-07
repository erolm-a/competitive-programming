#include <algorithm>

using namespace std;

int num_2[11], num_5[11];


bool associabili(int N, int* voti2, int* voti5)
{
    for(int i = 0; i < N; i++)
        ++num_2[*(voti2++)], ++num_5[*(voti5++)];

    for(int i = 10, j = 10; i > 0;) {
        if(i == j && num_2[i] + num_5[i] > 0 && num_5[i] <= num_2[i])
            return false;
        if(num_5[j] >= num_2[i])
            num_5[j] -= num_2[i], num_2[i] = 0;
        else num_2[i] -= num_5[j], num_5[j] = 0;

        if(num_5[j] == 0) j--;
        if(num_2[i] == 0) i--;
    }
    return true;
}
