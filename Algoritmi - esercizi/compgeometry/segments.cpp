#include <iostream>

using namespace std;

// angle = acos(det)
int det(int x1, int y1, int x2, int y2) {
  return x1*y2 - x2*y1;
}

int main()
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int d = det(x1, y1, x2, y2);
    cout << "Segments [(0,0)-(" << x1 << "," << y1 << ")] and [(0,0)-("<<x2 << "," << y2 << ")] are " << (d == 0 ? "parallel" : "intersecting") << endl;
}
