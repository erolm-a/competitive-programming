#include <iostream>
#include <algorithm>

using namespace std;

// angle = acos(det)
struct point {
  int x, y;

  point operator+(const point& other) { return {x+other.x, y+other.y}; }
  point operator-(const point& other) { return {x-other.x, y-other.y}; }
  point operator*(const point& other) { return {x*other.x + y*other.y}; }
  friend istream &operator>>(istream& input, point& p) {
    input >> p.x >> p.y;
    return input;
  }

  int crossproduct(const point& other) {return x*other.y - other.x*y;}
};

bool on_segment(point p1, point p2, point p3) {
  return min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x) &&
         min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y);
}

bool segments_intersect(point p1, point p2, point p3, point p4) {
  int d1 = (p3-p4).crossproduct(p1-p4), d2 = (p3-p4).crossproduct(p2-p4),
      d3 = (p1-p2).crossproduct(p3-p2), d4 = (p1-p2).crossproduct(p4-p2);

  if (d1*d2 < 0 && d3*d4 < 0) return true;

  if ((d1 == 0 && on_segment(p3, p4, p1)) ||
      (d2 == 0 && on_segment(p3, p4, p2)) ||
      (d3 == 0 && on_segment(p1, p2, p3)) ||
      (d4 == 0 && on_segment(p1, p2, p4)))
    return true;

  return false;
}

int main()
{
  point p1, p2, p3, p4;
  cin >> p1 >> p2 >> p3 >> p4;

  cout << "Do p1-p2 and p3-p4 intersect? " << (segments_intersect(p1, p2, p3, p4) ? "Yes" : "No") << endl;
}
