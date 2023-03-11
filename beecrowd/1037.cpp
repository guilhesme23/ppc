#include <iostream>
#include <vector>

using namespace std;

struct Interval {
  double value;
  string repr;
} typedef Interval;

int main() {
  double input;
  cin >> input;

  vector<Interval> intervals = {
    {25.0000000, "[0,25]"},
    {50.0000000, "(25,50]"},
    {75.0000000, "(50,75]"},
    {100.0000000, "(75,100]"}
  };

  for (auto i = intervals.begin(); i != intervals.end(); i++) {
    if (0 <= input && input <= i->value) {
      cout << "Intervalo " << i->repr << endl;
      return 0;
    }
  }

  cout << "Fora de intervalo\n";
  return 0;
}