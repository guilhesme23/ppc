#include <iostream>
#define COST 12.0

using namespace std;

int main() {
  int t, v;
  cin >> t >> v;
  printf("%.3lf\n", (t*v)/COST);
  return 0;
}