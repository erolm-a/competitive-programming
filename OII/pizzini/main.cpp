#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;



#define MAX_N 100
#define MAX_STR 80

int main()
{
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");
    char anagrams[MAX_N][MAX_STR + 1];
    int anagrams_id[MAX_N];
    map<string, int> map_anagrams;
    int size;
    int N;
    fscanf(in, "%d", &N);
    for(int i = 0; i < N; i++)
    {
        fscanf(in, "%s", anagrams[i]);
        string cp = anagrams[i];
        sort(cp.data(), cp.data() + cp.size());
        auto it = map_anagrams.find(cp);
        if(it != map_anagrams.end())
            it->second++;
        else
            anagrams_id[i] = size, map_anagrams[cp] = size, size++;
    }

}
