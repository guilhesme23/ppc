#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  vector<int> notes = {100, 50, 20, 10, 5, 2, 1};
  vector<int> coins = {50, 25, 10, 5, 1};
  double value;

  cin >> value;

  double tmp;
  int decimal;
  decimal = static_cast<int>(modf(value, &tmp) * 100);
  int whole = static_cast<int>(tmp);

  cout << "NOTAS:\n";
  for (auto note = notes.begin(); note != notes.end(); note++) {
    if (*note == 1) {
      cout << "MOEDAS:\n";
      cout << whole / *note << " moeda(s) de R$ " << *note << ".00\n";
    } else {
      cout << whole / *note << " nota(s) de R$ " << *note << ".00\n";
    }
    whole = whole % (*note);
  }

  for (auto coin = coins.begin(); coin != coins.end(); coin++) {
    printf("%d moeda(s) de R$ 0.%02d\n", decimal / *coin, *coin);
    decimal %=(*coin);
  }  
  return 0;
}