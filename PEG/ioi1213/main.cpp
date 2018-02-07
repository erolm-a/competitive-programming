#include <bits/stdc++.h>

using namespace std;
#define MAX_N 1000000

#define STEP_SIZE 21
struct command{
    char c;
    int step[STEP_SIZE] = {-1};
    int n;
    command() {fill(step, step + STEP_SIZE, -1);}
} commands[MAX_N];
int i;

int main()
{
    int N;
    scanf("%d", &N);
    char q;
    while(N--) {
        scanf(" %c", &q);
        char ch; int chd;
        switch(q) {
            case 'T':
                scanf(" %c", &ch);
                commands[i].c = ch;
                commands[i].step[0] = i-1;
                if(i)
                    commands[i].n = commands[i-1].n+1;

                for(int j = 1; j < STEP_SIZE && commands[i].step[j-1] != -1; j++)
                        commands[i].step[j] = commands[commands[i].step[j-1]].step[j-1];
                i++;
                break;
            case 'U':
                scanf(" %d", &chd);
                commands[i] = commands[i-chd-1];
                i++;
                break;
            case 'P':
                scanf(" %d", &chd);
                chd = commands[i-1].n-chd;
                int j = i-1;
                for(int step = ffs(chd)-1; chd > 0; chd -= (1 << step), step = ffs(chd)-1)
                    j = commands[j].step[step];
                printf("%c\n", commands[j].c);
        }
    }
}
