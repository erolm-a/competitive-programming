#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;

  point operator+(const point& other) const { return {x+other.x, y+other.y}; }
  point operator-(const point& other) const { return {x-other.x, y-other.y}; }
  point operator-() const { return point{0, 0} - *this; }
  int operator*(const point& other) const { return x*other.x + y*other.y; }
  friend istream &operator>>(istream& input, point& p) {
    input >> p.x >> p.y;
    return input;
  }
  friend ostream &operator<<(ostream& output, const point& p) {
    output << p.x << ' ' << p.y;
    return output;
  }

  int operator^(const point& other) const {return x*other.y - other.x*y;}

  bool operator<(const point& other) const {return y < other.y || (y == other.y && x < other.x); }
  bool operator>(const point& other) const {return y > other.y || (y == other.y && x > other.x); }
};

bool ccw(point a, point b, point o) {return ((a - o) ^ (b - o)) > 0;}
bool collinear(point a, point b, point o) {return ((a - o) ^ (b - o)) == 0;}


using vp = vector<point>;
// change <= to < in line 51 to include points that lay on the convex hull
vp graham(const vp& points) {
    vp sorted(points);
    sort(sorted.begin(), sorted.end());
    point origin = sorted[0];

    auto comp = [origin](const point a, const point b) {
        auto ao = a - origin, bo = b - origin;
        if(collinear(a, b, origin)) return ao*ao < bo*bo;
        return atan2(ao.y, ao.x) < atan2(bo.y, bo.x);
    };

    sort(sorted.begin()+1, sorted.end(), comp);

    vp ch;
    for(int i = 0; i < 3; i++)
        ch.push_back(sorted[i]);

    for(int i = 3; i < sorted.size(); i++) {
        while(ch.size() > 2 && !ccw(sorted[i], ch[ch.size()-2], ch[ch.size()-1]))
            ch.pop_back();
        ch.push_back(sorted[i]);
    }
    return ch;
}

int main() {
    vp points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}, {-5, 2}, {-5, 0}};
  vp ch = graham(points);

  cout << "Result\n";
  for(auto p: ch)
    cout << p << endl;
}
