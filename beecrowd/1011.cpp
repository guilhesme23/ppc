#include <iostream>
#include <cmath>
#define PI 3.14159

using namespace std;

int main()
{
  double radius;
  cin >> radius;
  printf("VOLUME = %.3lf\n", ((4.0 / 3.0) * PI * pow(radius, 3)));
  return 0;
}