#include <iostream>
using namespace std;
int main() {
  int d;
  double gas;
  cin>>d>>gas;
  printf("%.3lf km/l\n", d/gas);
  return 0;
}