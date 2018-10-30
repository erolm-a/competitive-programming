#include <bits/stdc++.h>

using namespace std;

int l;

void increment_word(char* word) {
    bool is_z = word[0] == 'z';
    for(int i = 1; i < l; i++)
        if(word[i] != word[0]) is_z = false;

    if(is_z)
        fill(word, word + ++l, 'a');
    else
        for(int i = l-1; i>=0; i--)
            if(word[i] == 'z') word[i] = 'a';
            else {word[i]++; break;}
}
int main()
{
    int n;
    cin >> n;
    char cur_word[100000];
    cur_word[0] = 'a';
    l = 1;

    for(int i = 0; i < n; i++) {
        cout << cur_word << endl;
        increment_word(cur_word);
    }
}
