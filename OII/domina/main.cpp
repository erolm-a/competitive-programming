#include <bits/stdc++.h>

#define MAX_N 1001
int readInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

std::vector<int> from[MAX_N], to[MAX_N];
int potenziale[MAX_N];
int N, M;

std::bitset<MAX_N> coalizione;
std::bitset<MAX_N> visited;
int get_potenziale(int step, int r)
{
    visited[r] = true;
    if(step == 2) return 1;
    int ris = 0;
    for(int i: from[r])
        if(!visited[i])
            ris += 1 + get_potenziale(step+1, i);
    return ris;
}

void calcola()
{
    bool sconfitte, vittorie;
    for(int tries = 0; tries <= 30; tries++) {
        for(int i = 1; i <= N; i++)
        {
            sconfitte = false, vittorie = false;
            int pot_nemico = 0;

            for(int j: to[i]) {
                if(to[j].size() == 0) goto fine;
                if(coalizione[j])
                    sconfitte = true, pot_nemico += potenziale[j];
            }

            for(int j: from[i])
                if(coalizione[j])
                    vittorie = true, pot_nemico += potenziale[j];

            if(!vittorie) {
                if(!sconfitte) { coalizione[i] = true; continue;}
                else if(from[i].size() == 0) continue;
            }
            if(pot_nemico < potenziale[i] || to[i].size() == 0) {
                for(int j: from[i])
                    coalizione[j] = false;
                for(int j: to[i])
                    coalizione[j] = false;
                coalizione[i] = true;
            }
        fine:;
        }
    }
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    N = readInt(), M = readInt();

    for(int i = 0; i < M; i++)
    {
        int a, b;
        a = readInt(), b = readInt();
        from[a].push_back(b);
        to[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        potenziale[i] = get_potenziale(0, i);
        visited.reset();
    }


    calcola();

    for(int i = 1; i <=N; i++)
        if(coalizione[i]) printf("%d ", i);
    printf("\n");

}
