#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define MAX_S 100008

char c_str[2*MAX_S];

int crossover(char *a_str, char *b_str, int a_l, int b_l, char *c) {
    if(a_l == 0) {
        for(int i = 0; i < b_l; i++) c[i] = b_str[i];
        return b_l;
    }
    if(b_l == 0) {
        for(int i = 0; i < a_l; i++) c[i] = a_str[i];
        return a_l;
    }
    if(*a_str == b_str[b_l-1])
        return crossover(b_str, a_str+1, b_l-1, a_l-1, c);
    c[0] = b_str[b_l-1];
    int N = crossover(a_str+1, b_str, a_l-1, b_l-1, c+1);
    c[N+1] = a_str[0];
    return N+2;
}

int main()
{
    ifstream i_f("input.txt");
    ofstream o_f("output.txt");

    char a_str[MAX_S+1], b_str[MAX_S+1];

    i_f >> a_str >> b_str;

    (void) crossover(a_str, b_str, strlen(a_str), strlen(b_str), c_str);
    o_f << c_str; // la stringa conterrà almeno un '\0'

    return 0;
}
