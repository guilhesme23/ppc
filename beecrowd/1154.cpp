#include <iostream>
#include <iomanip>

using namespace std;


int main() {
  cout << fixed << setprecision(2);
  
  int age, total = 0;
  int n = 0;
  while(cin >> age) {
    if (age < 0) break;
    n++;
    total += age;
  }

  cout << total / (double) n << endl;
}