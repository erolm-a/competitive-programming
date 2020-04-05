#include <bits/stdc++.h>

using namespace std;

#define FOR(a,b) for(int i = a; i < b; i++)
#define FOR_REV(a,b) for(int i = a; i >= b; i--)

int total_time, problems;
unordered_map<string, int> score_per_problem;


int global_ctr;

struct Player {
    unordered_set<string> solved;
    int score, last_ok, tie;
    string name;

    bool operator<(const Player& other) {
        if(score > other.score) return true;
        else if(score == other.score) {
            if(last_ok < other.last_ok)
                return true;
            else if(last_ok == other.last_ok)
                return tie < other.tie;
        }
        return false;
    }
};

map<string, string> submission2prob;
struct submission {
    string first;
    int second;
    int third;
};

map<string, submission> submissions;

int main()
{
    int total_time;
    cin >> total_time;
    int problems;
    cin >> problems;

    FOR(0, problems) {
        string input;
        int val;
        cin >> val >> input;
        score_per_problem[input] = val;
    }
    int logs;
    cin >> logs;
    map<string, Player> players;


    FOR(0, logs) {
        int timestamp;
        string cont_name, pr_name, subm_id, status;
        cin >> timestamp >> status >> subm_id;

        if(players.find(cont_name) == players.end())
            players[cont_name] = Player{};


        if(status == "SUBMIT") {
            cin >> cont_name >> pr_name;
            players[cont_name].name = cont_name;
            if(timestamp > total_time)
                continue;
            if(players[cont_name].solved.find(pr_name) != players[cont_name].solved.end())
                continue;

            submission2prob[subm_id] = pr_name;
            submissions[subm_id] = {cont_name, timestamp, i};
        }
        else if(status == "ACCEPT") {
            cont_name = submissions[subm_id].first;
            int pending = submissions[subm_id].second;
            int t = submissions[subm_id].third;
            pr_name = submission2prob[subm_id];
            if(players[cont_name].solved.find(pr_name) == players[cont_name].solved.end()) {
                players[cont_name].last_ok = max(players[cont_name].last_ok, pending);
                players[cont_name].tie = t;
                players[cont_name].solved.insert(pr_name);
                players[cont_name].score += score_per_problem[pr_name];
            }
        }
    }

    vector<Player> scoreboard;
    for(auto it = players.begin(); it != players.end(); it++) {
        scoreboard.push_back(move(it->second));
    }

    sort(scoreboard.begin(), scoreboard.end());

    FOR(0, scoreboard.size()) {
        if(!scoreboard[i].score) break;
        cout << scoreboard[i].score << ' ' << scoreboard[i].name << endl;
    }
}
