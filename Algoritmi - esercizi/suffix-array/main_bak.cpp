#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_S 1000000

#define ALPHABET_SIZE 128 - ' '
deque<char*> alphabet_cs[ALPHABET_SIZE];
int alphabet_cs_counter[ALPHABET_SIZE];

deque<char*> zero_cs;

// Stable and O(N)
void counting_sort(char** to_order, int digit, size_t N)
{
    zero_cs.clear();
    for(int i = 0; i < ALPHABET_SIZE; i++)
        alphabet_cs[i].clear();
    for(size_t i = 0; i < N; i++)
        if(to_order[i][digit] == '\0')
            zero_cs.push_back(to_order[i]);
        else
            alphabet_cs[(int)to_order[i][digit] - ' '].push_back(to_order[i]);
    copy(zero_cs.begin(), zero_cs.end(), to_order);
    int j = zero_cs.size();

    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        alphabet_cs_counter[i] = alphabet_cs[i].size();
        while(!alphabet_cs[i].empty()) {
            to_order[j++] = alphabet_cs[i].front();
            alphabet_cs[i].pop_front();
        }
    }
}


// O(NlogN)?
void MSDradix_sort(char** to_order, size_t N, int len, size_t starting_digit=0)
{
    if(len - starting_digit < ALPHABET_SIZE)
        sort(to_order, to_order + N, [starting_digit](const char* a, const char* b){
            return strcmp(a + starting_digit, b + starting_digit) < 0;
        });
    else {
        counting_sort(to_order, starting_digit, N);
        int prec = 0;
        for(int i = 0; i < ALPHABET_SIZE; i++)
            if(alphabet_cs_counter[i] > 1) {
                MSDradix_sort(to_order + prec, prec + alphabet_cs_counter[i], len, starting_digit+1);
                prec += alphabet_cs_counter[i];
            }
    }
}

int main()
{
    char suffix_string[MAX_S+1];
    fill(suffix_string, suffix_string + MAX_S, '\0');
    fgets(suffix_string, MAX_S, stdin);
    int s = strlen(suffix_string);
    suffix_string[--s] = '\0';
    char** testing = new char*[s];
    for(int i = 0; i < s; i++)
        testing[i] = suffix_string + i;

    MSDradix_sort(testing, s, s);

    for(int i = 0; i < s; i++)
        cout << testing[i] - suffix_string << endl;
}
