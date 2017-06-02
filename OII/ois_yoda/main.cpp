#include <cstdio>

using namespace std;

#define MAX 100000
int main()
{
    char messaggio[MAX + 1];
    int letto, i;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for(i = 0; (letto = getchar()) != EOF && letto != '\n'; i++) {
        if(letto == ' ')
            letto = '\0';
        messaggio[i] = letto;
    }
    messaggio[i] = '\0';

    for(i-=2; i > 0; i--)
        if(messaggio[i] == '\0') {
            printf("%s ", messaggio + i + 1);
        }
    printf("%s\n", messaggio);

    return 0;
}
