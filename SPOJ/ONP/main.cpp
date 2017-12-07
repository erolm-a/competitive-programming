#include <bits/stdc++.h>

using namespace std;



inline int priority(char c)
{
    if(c == '(') return -1;
    if(c == '+' || c == '-') return 0;
    if(c == '*' || c == '/') return 1;
    return 2;
}

stack<char> ops;

inline void clear(char c)
{
    while(!ops.empty() && (c == ')' || priority(c) < priority(ops.top()))) {
        char s = ops.top();
        ops.pop();
        if(s == '(')
            break;
        cout << s;
    }
    if(c != ')') ops.push(c);
}
int main()
{
    int tc;
    string s;

    ios_base::sync_with_stdio(false);

    cin >> tc;
    while(tc--) {
        cin >> s;
        for(char c: s) {
            if(c == '(')
                ops.push(c);
            else if(c >= 'a' && c <= 'z')
                cout << c;
            else clear(c);
        }
        while(!ops.empty()) {
            cout << ops.top();
            ops.pop();
        }
        cout << '\n';
    }
    return 0;

}
