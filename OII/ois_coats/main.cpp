#include <fstream>

using namespace std;


int main()
{
    ifstream i_f("input.txt");
    ofstream o_f("output.txt");
    int N, twos, t, count = 0;
    i_f >> N;

    for(int i = 0; i < N; i++) {
        i_f >> t;
        if(t == 2) twos++;
        count += t;
    }
    ofstream("output.txt") << (double) (twos + 1) * twos / (2 * count);
    return 0;
}
