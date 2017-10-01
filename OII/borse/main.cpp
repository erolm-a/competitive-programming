#include <bits/stdc++.h>

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

std::vector<int> sol;
void ricorri(int rim)
{
    if(!rim){
        for(int i: sol) printf("%d ", i);
        printf("\n");
        return;
    }

    for(int i = 1; i <= (sol.size() ? std::min(sol.back(), rim) : rim); i++) {
        sol.push_back(i);
        ricorri(rim - i);
        sol.pop_back();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N = readInt();
    ricorri(N);
}
