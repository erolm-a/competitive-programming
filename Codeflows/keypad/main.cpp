#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

#define char2int(c) (c - 'A')
#define MODULO ((ll) 1e9+7)

int no_of_press[26];
int char2key[26];
int key2length[8];

using pii = pair<int, int>;
using ll = long long;

void preprocess(vector<string>& keys) {
    for(int i = 0; i < 8; i++) {
        key2length[i] = keys.size();
        for(int j = 0; keys[i][j]; j++) {
            int ch = char2int(keys[i][j]);
            char2key[ch] = i;
            no_of_press[ch] = j+1;
        }
    }
}

vector<ll> build_dp(int length, int k) {
    vector<ll> dp(length+1);
    for(int i = 1; i <= length; i++) {
        dp[i] = 1;
        for(int j = i - k; j < i; j++) {
            if(j <= 0) continue;
            dp[i] += dp[j];
            dp[i] %= MODULO;
        }
    }
    return dp;
}

/*
 * Complete the 'countMessages' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY keys
 *  2. STRING message
 */
int countMessages(vector<string> keys, string message) {
    preprocess(keys);

    // convert the message into a number array
    vector<pii> message_seq;
    int longest = 0;
    for(auto CH: message) {
        if(!isalpha(CH)) continue;
        int ch = char2int(CH);
        int key = char2key[ch];
        if(message_seq.empty() || message_seq.back().first != key)
            message_seq.push_back({key, no_of_press[ch]});
        else message_seq.back().second += no_of_press[ch];

        longest = max(longest, message_seq.back().second);
    }

    auto dp_3 = build_dp(longest, 3), dp_4 = build_dp(longest, 4);

    ll ris = 1;
    for(pii p: message_seq) {
        ris *= (key2length[p.first] == 3 ? dp_3 : dp_4)[p.second];
        ris %= MODULO;
    }

    return (int) ris;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string keys_count_temp;
    getline(cin, keys_count_temp);

    int keys_count = stoi(ltrim(rtrim(keys_count_temp)));

    vector<string> keys(keys_count);

    for (int i = 0; i < keys_count; i++) {
        string keys_item;
        getline(cin, keys_item);

        keys[i] = keys_item;
    }

    string message;
    getline(cin, message);

    int result = countMessages(keys, message);

    cout << result << "\n";

    //cout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
