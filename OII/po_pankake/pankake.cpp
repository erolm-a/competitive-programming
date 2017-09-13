#include <bits/stdc++.h>

using namespace std;
unordered_set<string> already_met;
queue<int> moves;

string status;
void prepara(int N)
{
    status.resize(N);
    for(int i = 0; i < N; i++)
        status[i] = '0' + i;

    already_met.insert(status);

    for(int i = 2; ;)
    {
        reverse(status.begin(), status.begin() + i);
        if(already_met.find(status) != already_met.end()) {
            reverse(status.begin(), status.begin() + i);
            i++;
            if(i > N) {
                moves.push(2);
                return;
            }

        }
        else {
            already_met.insert(status);
            moves.push(i);
            i = 2;
        }
    }

}

int ribalta()
{
    int ris = moves.front();
    moves.pop();
    return ris;
}
