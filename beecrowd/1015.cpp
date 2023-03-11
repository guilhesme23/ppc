#include <iostream>
#include <cmath>

using namespace std;

struct _Point {
  double x;
  double y;
} typedef Point;

int main() {
  Point p1, p2;
  cin >> p1.x >> p1.y >> p2.x >> p2.y;
  printf("%.4lf\n", sqrt(pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2)));
  return 0;
}