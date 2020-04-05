#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
#define MAX_N 1000000
int scores[MAX_N][2];
bitset<MAX_N> locked;
int friends[MAX_N];

struct player{
  int a, b;
  int score;

  player(int A, int B): a{A}, b{B} {
    if(B != -1) score = scores[a][1] + scores[b][1];
    else score = scores[a][0];
  }

  bool operator<(const player& other) const {
    return score < other.score || (score == other.score && b > -1);
  }
};

vector<player> players;

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, K;
  scanf("%d %d", &N, &K);

  for(int i = 0; i < N; i++)
  {
    int f, f_score, a_score;
    scanf("%d %d %d", &f, &a_score, &f_score);
    friends[i] = f;
    scores[i][0] = a_score;
    scores[i][1] = f_score;
    players.emplace_back(i, -1);
    if(friends[f] == i && i > 0)
      players.emplace_back(friends[i], i);
  }

  int res = 0;
  sort(players.begin(), players.end());
  if(K == N) {
      for(player& i: players)
          if(i.b > -1)
              res+=i.score;
  } else {

      for(auto p = players.rbegin(); p != players.rend() && K > 0; p++)
      {
        if(!locked[p->a] && ((p->b > -1 && K >= 2) || p->b == -1))
        {
          locked[p->a] = true;
          locked[friends[p->a]] = true;
          res += p->score;
          K -= 1 + (p->b > -1);
        }
      }
  }

  printf("%d\n", res);
  return 0;
}
