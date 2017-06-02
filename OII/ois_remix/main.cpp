#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    char msg[N+1], ris[N+1];
    scanf(" %s", msg);

    int i, j;
    bool whitespace;
    for(i = 0, j = 0; i < N; i++) {
        if(msg[i] == 'P' && strncmp(msg + i, "PaH", 3) == 0) {
            i += 2, whitespace = true;
        }
        else if(msg[i] == 'T' && strncmp(msg + i, "TuNZ", 4) == 0) {
            i += 3, whitespace = true;
        }
        else {
            if(j > 0 && whitespace)
                ris[j++] = ' ';
            whitespace = false;
            ris[j++] = msg[i];
        }
    }
    ris[j] = '\0';
    printf("%s\n", ris);
    return 0;
}
