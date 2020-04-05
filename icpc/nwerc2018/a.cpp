#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

using VD = vector<double>;
VD xs, ys;

int N;

VD solve(const VD& arr)
{
    VD sol;
    sol.push_back(arr[0]);

    VD sums;
    sums.push_back(0);
    sums.push_back(arr[0]);

    for(int i = 1; i < arr.size(); i++)
    {
        sums.push_back(sums.back() + arr[i]);
        if (arr[i] > sol.back())
            sol.push_back(arr[i]);
        else {
            int j;
            for(j = i-1; fabs(sol[j] - sol[j-1]) <= EPS || (sums[i+1] - sums[j]) / (i - j + 1) < sol[j-1]; j--)
                ;
           
            double avg = (sums[i+1] - sums[j]) / (i - j + 1);
            for(; j < i; j++)
                sol[j] = avg;
            sol.push_back(avg);
        }
    }

    return sol;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) { o << '['; for (const T& x: v) o << x << ' '; o << ']'; return o;}

int main()
{
    cin >> N;
    while(N--) {
        int x, y;
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
    }

    auto pos_xs = solve(xs), pos_ys = solve(ys);
    double sol = 0;
    for(int i = 0; i < xs.size(); i++)
        sol += pow(pos_xs[i] - xs[i], 2) + pow(pos_ys[i] - ys[i], 2);

    cout << sol << endl;
}
