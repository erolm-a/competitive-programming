#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

int* nastro;
int** st, **pt;
char** visited;

int N, S, C;

#define SUCCESS 2
#define FAILURE 1

bool trivial_dfs(int id, int state)
{
    fprintf(stderr, "id: %d; state: %d\n", id, state);
    if(id == 0) {return SUCCESS;}
    visited[id][state] = FAILURE;
    int new_state = st[state][nastro[id]];
    int new_pos = id + pt[state][nastro[id]];
    if(visited[new_pos][new_state])
        return (visited[id][state] = visited[new_pos][new_state]) == SUCCESS;
    else
        return visited[id][state] =
                trivial_dfs(new_pos, new_state) ? SUCCESS : FAILURE;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d", &N, &S, &C);
    nastro = new int[N];
    st = new int*[S];
    pt = new int*[S];
    visited = new char*[N];
    for(int i = 0; i < S; i++)
        st[i] = new int[C], pt[i] = new int[C];

    int in_st, in_sym, out_st, out_sym;

    for(int i = 0; i < S*C; i++)
        scanf("%d %d %d %d", &in_st, &in_sym, &out_st, &out_sym),
                st[in_st][in_sym] = out_st,
                pt[in_st][in_sym] = out_sym;


    for(int i = 0; i < N; i++)
        scanf("%d", nastro + i), visited[i] = new char[S];
    memset(*visited, 0, S*N);
    memset(*visited, SUCCESS, S);

    vector<int> ok;
    for(int i = 0; i < N; i++, success = 0)
    {
        if(!visited[i][0])
            trivial_dfs(i, 0);
        if(visited[i][0] == SUCCESS)
            ok.push_back(i);
    }
    printf("%lu\n", ok.size());
    for(int i: ok)
        printf("%d\n", i);
}
