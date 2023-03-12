#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// 1, V é 5, X é 10, L é 50, C é 100, D é 500 e M representa 1000.

int main() {
  map<int, string> table = {
    {1, "I"},
    {4, "IV"},
    {5, "V"},
    {9, "IX"},
    {10, "X"},
    {40, "XL"},
    {50, "L"},
    {90, "XC"},
    {100, "C"},
    {400, "CD"},
    {500, "D"},
    {900, "CM"},
    {1000, "M"}
  };

  vector<int> options = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

  int input;
  cin >> input;

  vector<string> result;

  for(auto number = options.begin(); number != options.end(); number++) {
    if ((input / *number) == 0) {
      continue;
    }

    int times = (input / *number);
    string roman = table[*number];

    for (auto i=0; i < times; i++) {
      result.push_back(roman);
    };

    input%= *number;
  }

  for(auto c = result.begin(); c != result.end(); c++) {
    cout << *c;
  }
  
  cout << '\n';

  return 0;
}
