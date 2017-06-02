#include <fstream>

using namespace std;

int main()
{
    unsigned long long N;
    ifstream("input.txt") >> N;
    ofstream("output.txt") << (N > 1 ? N * (N - 1) / 4.0 : 1) << '\n';
    return 0;
}
