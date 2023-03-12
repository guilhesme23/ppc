#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, double> prices = {
    {1001, 1.50},
    {1002, 2.50},
    {1003, 3.50},
    {1004, 4.50},
    {1005, 5.50}
  };

  int entries;
  cin >> entries;

  double total = 0;
  while (entries--) {
    int code, qtd;
    cin >> code >> qtd;

    total += prices[code] * qtd;
  }

  printf("%.2lf\n", total);
  return 0;
}