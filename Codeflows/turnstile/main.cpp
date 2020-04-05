#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getTimes' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY time
 *  2. INTEGER_ARRAY direction
 */

#define ENTERING 0
#define LEAVING 1

using pii = pair<int, int>;

vector<int> getTimes(vector<int> time, vector<int> direction) {
    queue<pii> entering, leaving;
    for(int i = 0; i < time.size(); i++)
        if(direction[i])
            leaving.push({time[i],i});
        else entering.push({time[i],i});


    vector<int> answer(time.size());

    int last_used = INT_MIN;
    int cur_time = -2;
    int last_state = ENTERING;

    while(entering.size() && leaving.size()) {
        cur_time = max(cur_time, min(entering.front().first, leaving.front().first));
        cout << "Current time: " << cur_time << endl;
        // check if only one of the two is present at the same time
        if(cur_time >= entering.front().first && cur_time < leaving.front().first) {
            cout << "Serving the one entering at time "  << entering.front().first << endl;
            answer[entering.front().second] = last_used = cur_time++;
            last_state = ENTERING;
            entering.pop();
        }
        else if(cur_time >= leaving.front().first && cur_time < entering.front().first) {
            cout << "Serving the one leaving at time "  << leaving.front().first << endl;
            answer[leaving.front().second] = last_used = cur_time++;
            last_state = LEAVING;
            leaving.pop();
        }

        // contemporary
        else if(last_used != cur_time-1 || last_state == LEAVING) {
            cout << "Serving the one leaving at time "  << leaving.front().first << endl;
            answer[leaving.front().second] = last_used = cur_time++;
            last_state = LEAVING;
            leaving.pop();
        }
        else {
            cout << "Serving the one entering at time "  << entering.front().first << endl;
            answer[entering.front().second] = last_used = cur_time++;
            last_state = ENTERING;
            entering.pop();
        }
    }

    // serve the remaining ones

    while(!entering.empty()) {
        auto p = entering.front(); entering.pop();
        answer[p.second] = (cur_time = max(cur_time, p.first)); cur_time++;
    }

    while(!leaving.empty()) {
        auto p = leaving.front(); leaving.pop();
        answer[p.second] = (cur_time = max(cur_time, p.first)); cur_time++;
    }

    return answer;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string time_count_temp;
    getline(cin, time_count_temp);

    int time_count = stoi(ltrim(rtrim(time_count_temp)));

    vector<int> time(time_count);

    for (int i = 0; i < time_count; i++) {
        string time_item_temp;
        getline(cin, time_item_temp);

        int time_item = stoi(ltrim(rtrim(time_item_temp)));

        time[i] = time_item;
    }

    string direction_count_temp;
    getline(cin, direction_count_temp);

    int direction_count = stoi(ltrim(rtrim(direction_count_temp)));

    vector<int> direction(direction_count);

    for (int i = 0; i < direction_count; i++) {
        string direction_item_temp;
        getline(cin, direction_item_temp);

        int direction_item = stoi(ltrim(rtrim(direction_item_temp)));

        direction[i] = direction_item;
    }

    vector<int> result = getTimes(time, direction);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

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
