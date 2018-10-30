#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
constexpr ull MODULO = 1000000007;
#define MAX_EXPR 700001

char input[MAX_EXPR];
size_t input_len;

// num_of_operands, num_of_satisfiying combinations

struct parse_t {
    ull op_num, satisfying_num; int last_index;
};

bool prefix(const char *str, const char *pre)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

ull powers_of_2[MAX_EXPR];

parse_t parse(int i)
{
    if(prefix(input+i, "X")) {
        return {1, 1, i};
    }
    if(prefix(input+i, "OR")) {
        auto res1 = parse(i+3);
        auto res2 = parse(res1.last_index+2);

        return {res1.op_num+res2.op_num, (res1.satisfying_num*powers_of_2[res2.op_num] +
                                         (MODULO + powers_of_2[res1.op_num]-res1.satisfying_num)*res2.satisfying_num)
                                        % MODULO, res2.last_index+1};
    }
    if(prefix(input+i, "NOT")) {
        auto res = parse(i+4);
        return {res.op_num, (MODULO + powers_of_2[res.op_num] - res.satisfying_num) % MODULO, res.last_index+1};
    }

    if(prefix(input+i, "AND")) {
        auto res1 = parse(i+4);
        auto res2 = parse(res1.last_index+2);

        return {res1.op_num+res2.op_num, (res1.satisfying_num*res2.satisfying_num) % MODULO, res2.last_index+1};
    }
    return {0, 0, 0}; // BOH
}

int main() {
    powers_of_2[0] = 1;
    for(int i = 1; i < MAX_EXPR; i++)
        powers_of_2[i] = (powers_of_2[i-1]*2) % MODULO;

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> input;
        cout << parse(0).satisfying_num << endl;
    }
}
