#include <iostream>

using namespace std;

int main()
{
  string name;
  double salary, sold;
  cin >> name >> salary >> sold;
  printf("TOTAL = R$ %.2lf\n", salary + sold * 0.15);
  return 0;
}