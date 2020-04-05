#include <cstdio>

using namespace std;

bool solve() {
    int n;
    int sum = 0;
    char ch;

    scanf("%d", &n);

    while(n--) {
        scanf(" %c", &ch);
        if (ch == '(')
            sum++;
        else sum--;
        if (sum < -1)
            return false;
    }
    return sum == 0;
}

int main()
{
    if(solve()) puts("Yes"); else puts("No");

}
