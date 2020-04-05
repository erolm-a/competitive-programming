#include <bits/stdc++.h>

using namespace std;

struct pt {
  int x, y;

  pt operator+(const pt& other) const { return {x+other.x, y+other.y}; }
  pt operator-(const pt& other) const { return {x-other.x, y-other.y}; }
  int operator*(const pt& other) const { return x*other.x + y*other.y; }
  friend istream &operator>>(istream& input, pt& p) {
    input >> p.x >> p.y;
    return input;
  }
  friend ostream &operator<<(ostream& output, const pt& p) {
    output << p.x << ' ' << p.y;
    return output;
  }

  int operator^(const pt& other) const {return x*other.y - other.x*y;}

  bool operator<(const pt& other) const {return y < other.y || (y == other.y && x < other.x); }
  bool operator>(const pt& other) const {return y > other.y || (y == other.y && x > other.x); }

};

bool ccw(pt a, pt b, pt o) {return ((a - o) ^ (b - o)) > 0;}

using vpt = vector<pt>;

void sort_by_polar(vpt points, pt o) {
    sort(points.begin(), points.end(), [o](const pt& a, const pt& b) {
        if(ccw(a, b, o) == 0) return a*a < b*b;
        return atan2(a.y - o.y, a.x - o.x) < atan2(b.y - o.y, b.x - o.x);
    });
}

vpt graham(vpt &points) {
    if(points.size() <= 3)
        return points;
    assert(min_element(points.begin(), points.end()) != points.end());
    sort_by_polar(points, *min_element(points.begin(), points.end()));
    vpt sol {points[0], points[1], points[2]};
    for(int i = 3; i < points.size(); i++) {
        while(sol.size() > 1 && !ccw(points[i], sol[sol.size()-2], sol.back()))
            sol.pop_back();
        sol.push_back(points[i]);
    }

    return sol;
}

bool is_in_line(pt a1, pt a2, pt a3) {
    return a3.x >= min(a1.x, a2.x) && a3.x <= max(a1.x, a2.x) &&
            a3.y >= min(a1.y, a2.y) && a3.y <= max(a1.y, a2.y);
}
bool segment_intersect(pt a1, pt a2, pt a3, pt a4) {
    int     det1 = (a1-a4)^(a3-a4),
            det2 = (a2-a4)^(a3-a4),
            det3 = (a3-a2)^(a1-a2),
            det4 = (a4-a2)^(a1-a2);

    return ((det1*det2 < 0 && det3*det4 < 0) ||
            (det1 == 0 && is_in_line(a3, a4, a1)) ||
            (det2 == 0 && is_in_line(a3, a4, a2)) ||
            (det3 == 0 && is_in_line(a1, a2, a3)) ||
            (det4 == 0 && is_in_line(a1, a2, a4)));
}

bool polygons_intersect(vpt&& p1, vpt&& p2) {

    for(int i = 0; i < p1.size()-1; i++)
        for(int j = 0; j < p2.size() - 1; j++)
            if(segment_intersect(p1[i], p1[i+1], p2[j], p2[j+1]))
                return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    for(int t = 1; ; t++) {
        int d, p;
        cin >> d >> p;
        if(d+p == 0) return 0;
        vpt dv(4*d), pv(4*p);

        for(int i = 0; i < 4*d; i+=4) {
            cin >> dv[i] >> dv[i+1];
            dv[i+2] = {dv[i].x, dv[i+1].y};
            dv[i+3] = {dv[i+1].x, dv[i].y};
        }
        for(int i = 0; i < 4*p; i+=4) {
            cin >> pv[i] >> pv[i+1];
            pv[i+2] = {pv[i].x, pv[i+1].y};
            pv[i+3] = {pv[i+1].x, pv[i].y};
        }

        if(polygons_intersect(graham(dv), graham(pv)))
            cout << "Case " << t << ": It is not possible to separate the two groups of vendors.\n\n";
        else
            cout << "Case " << t << ": It is possible to separate the two groups of vendors.\n\n";
    }
}
