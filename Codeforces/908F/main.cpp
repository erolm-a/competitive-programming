#include <bits/stdc++.h>

using namespace std;

#define MAX_N 300000
int n[MAX_N], c[MAX_N];
int N;

using ll = long long;
vector<int> greens, reds, blues;

set<int> adj_list[MAX_N];

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf(" %d", n + i);
        char co;
        scanf(" %c", &co);
        switch (co) {
        case 'R':
            reds.push_back(i);
            break;
        case 'B':
            blues.push_back(i);
            break;

        case 'G':
            greens.push_back(i);
            break;
        }
    }

    int j = 0;
    int red_dist = 0;
    for(int i = 0; i < reds.size(); i++)
    {
        if(greens.size() && reds[i] > greens.back())
            red_dist += reds[i] - greens.back();

        while(j < greens.size() && reds[i] < greens[j])
            j++;

        int left_to_green = reds[i] - greens[j];
        int left_to_red = i > 0 ? reds[i] - reds[i-1] : INT_MAX;
        int right_to_green = j < greens.size() - 1 ? greens[j+1] - reds[i] : INT_MAX;
        int right_to_red = i < reds.size() - 1 ? reds[i+1] - reds[i] : INT_MAX;

        int choices[] = {INT_MAX, left_to_green, left_to_red, right_to_green, right_to_red};
        switch(min_element(choices, choices + 4) - choices)
        {
            case 0:
                break;
            case 1:
                adj_list[reds[i]].insert(greens[j]);
                adj_list[greens[j]].insert(reds[i]);
                break;
            case 2:
                adj_list[reds[i]].insert(reds[i-1]);
                adj_list[reds[i-1]].insert(reds[i]);
                break;
            case 3:
                adj_list[reds[i]].insert(greens[j+1]);
                adj_list[greens[j+1]].insert(reds[i]);
                break;
            case 4:
                adj_list[reds[i]].insert(reds[i+1]);
                adj_list[reds[i+1]].insert(reds[i]);
                break;
        }
    }


}
