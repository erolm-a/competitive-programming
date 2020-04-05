#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
int Q;

struct people {
    int x, y; char dir;
};

vector<vector<people>> groups;

inline bool conflict(people a, people b) {
    // avoid symmetries
    if(a.dir >= b.dir) swap(a, b);

    // north-south conflict
    if((a.dir == 'N' && b.dir == 'S'))
        return a.y >= b.y - 1;

    if((a.dir == 'E' && b.dir == 'W'))
        return a.x >= b.x - 1;

    return false;
}

inline pii best_corner(const vector<people>& group) {
    int x = 0, y = 0;

    for(const people& p: group) {
        if(p.dir == 'N' && p.y >= y)
            y = p.y + 1;
        else if(p.dir == 'E' && p.x >= x)
            x = p.x + 1;
    }

    return {x, y};
}

int main()
{
    int tcs;
    cin >> tcs;

    for(int tc = 1; tc <= tcs; tc++) {
        groups.clear();
        int P;
        cin >> P >> Q;

        people p;

        for(int i = 0; i < P; i++) {
            cin >> p.x >> p.y >> p.dir;
            //cout << endl << "OUT " << p.x << ' ' << p.y << ' ' << p.dir << endl;

            if(groups.empty())
                groups.push_back({p});
            else
                for(int group = 0; group < groups.size(); group++) {
                    for(people q: groups[group])
                        if(conflict(p, q)) {
                            // take every person in that group that might give conflicts and copy that in a brand new set
                            groups.push_back({p});
                            for(people r: groups[group])
                                if(!conflict(p, r))
                                    groups.back().push_back(r);
                            goto for_end;
                        }
                    groups[group].push_back(p);
                    for_end:
                    ;
                }
        }

        // take the greatest set

        vector<int> candidates;

        //cout << "Number of groups: " << groups.size() << endl;
        //for(auto& V: groups)
        //    cout << V.size() << endl;


        for(int i = 0; i < groups.size(); i++)
            if(candidates.empty() || groups[i].size() > groups[candidates[0]].size())
                candidates = {i};
            else if(!candidates.empty() && groups[i].size() == groups[candidates.front()].size())
                candidates.push_back(i);

        //cout << "Chosen set size: " << groups[best_set].size() << endl;

        vector<pii> candidates_piis;
        for(int i: candidates)
            candidates_piis.push_back(best_corner(groups[i]));

        pii answer = *min_element(candidates_piis.begin(), candidates_piis.end());

        cout << "Case #" << tc << ": " << answer.first << ' ' << answer.second << '\n';
    }

    return 0;

}
