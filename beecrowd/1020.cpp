#include <iostream>

using namespace std;

int main() {
  int days;
  cin >> days;
  int years = days/365;
  days%=365;
  int months = days/30;
  days%=30;
  cout << years << " ano(s)\n" << months << " mes(es)\n" << days << " dia(s)\n";

  return 0;
}