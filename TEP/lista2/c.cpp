#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int S;
  cin >> S;
  while (S--) {
    int N;
    cin >> N;

    map<char, int> table = {{'0', 0}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0}, {'5', 0}, {'6', 0}, {'7', 0}, {'8', 0}, {'9', 0}};
    for (int i = 1; i <= N; ++i) {
      for (auto c : to_string(i)) {
        table[c] += 1;
      }
    }

    for (auto const& el : table) {
      char sep = (el.first != '9') ? ' ' : '\n';
      cout << el.second << sep;
    }
  };
}
