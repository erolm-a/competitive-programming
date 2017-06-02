#include <cstdio>
#include <cctype>

#define MAX_N 10
#define MAX_L 200000
char passwd[MAX_N+1], input_string[MAX_L+1];
int N, L;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %s", &N, &L, input_string);

    bool failed = false;
    for(int i = 0; i < L/2; i++) {
        char c1 = input_string[i], c2 = input_string[L-i-1],
                c;
        int digit;
        if(c1 == c2) continue;
        else if(isdigit(c1)) digit = c1 - '0', c = c2;
        else if(isdigit(c2)) digit = c2 - '0', c = c1;
        else {failed = true; break;}
        if(passwd[digit] == '\0')
            passwd[digit] = c;
        else if(passwd[digit] != c) {failed = true; break;}
    }

    for(int i = 0; i < N; i++)
        if(!passwd[i])
            failed = true;

    if(!failed)
        puts(passwd);
    else puts("impossibile");
}
