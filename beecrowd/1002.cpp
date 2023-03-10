// area = π . raio2. Considerando para este problema que π = 3.14159
#include <iostream>
#define PI 3.14159

using namespace std;

int main(int argc, char const *argv[])
{
  double r;
  cin >> r;
  double area = r*r * PI;
  printf("A=%.4lf\n", area);
  return 0;
}
