#include <iostream>

using namespace std;

int main() {
  string input;
  cin >> input;

  while(!input.empty()) {
    cout << input.back();
    input.pop_back();
  }

  cout << endl;
}