#include <cstdio>

using namespace std;
long long readInt () {
    long long result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    result = ch - '0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    return result;
}

int main()
{
    long long R, C;
    (void)readInt();
    R = readInt();
    C = readInt();
    printf("%lld\n", C*(R-C+1));
    return 0;
}
