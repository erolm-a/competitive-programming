#include <bits/stdc++.h>

using namespace std;

string input, result;

int main()
{
    cin >> input;
    cin >> result;

    int left1 = 0, right1 = input.size() - 1, right2 = result.size()-1;
    for(; left1 < input.size() && input[left1] == result[left1]; left1++);
    for(; right1 >= 0 && right2 >= 0 && input[right1] == result[right2]; right1--, right2--);

    if((left1 + (input.size() - right1 - 1) <= result.size()) && input[left1] == '*' && input[right1] == '*')
        cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
