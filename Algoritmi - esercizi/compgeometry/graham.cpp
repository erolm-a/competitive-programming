#include <bits/stdc++.h>

using namespace std;

struct pt {
  int x, y;

  pt operator+(const pt& other) const { return {x+other.x, y+other.y}; }
  pt operator-(const pt& other) const { return {x-other.x, y-other.y}; }
  pt operator*(const pt& other) const { return {x*other.x + y*other.y}; }
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

using ptpt = pair<pt,pt>;

// call if two points are collinear (i.e. ccw(
pt pick_outer(pt a, pt b, pt o) {
  pt ao = a-o, bo = b-o;
  return ao.y > bo.y ? ao : bo;
}

auto sort_by_polar(vector<pt>& points) {
  // first lookup for the bottomest, leftmost point
  
  sort(points.begin(), points.end());
  auto best_p = points[0];

  auto cmp = [best_p](const pt& p1, const pt& p2) {return ccw(p1, p2, best_p);};
  set<pt, decltype(cmp)> sorted (points.begin()+1, points.end(), cmp);

  return make_pair(best_p, sorted);
}

void graham(vector<pt>& points, vector<pt>& ch) {
    // point has operator< and operator> which will sort by polar coordinates
    auto sorted_result = sort_by_polar(points);
    auto p0 = sorted_result.first; auto sorted_by_polar = sorted_result.second;
    
    ch.push_back(p0);

    auto p = sorted_by_polar.begin();

    // add the other two points
    ch.push_back(*p++);
    ch.push_back(*p++);

    for(; p != sorted_by_polar.end(); p++) {
        // it is turning right ?
        if(ch.size() > 1 && !ccw(*p, ch[ch.size()-2], ch.back()))
            ch.pop_back();
        ch.push_back(*p);
    }
}
int main() {
  vector<pt> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
  vector<pt> ch;

  graham(points, ch);
  cout << "Result\n";
  for(auto p: ch)
    cout << p << endl;
}
