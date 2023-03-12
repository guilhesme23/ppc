#include <iostream>
#define A_VAL 65
#define SIZE 26

using namespace std;

int main() {
  int testCases;
  cin >> testCases;
  while(testCases--) {
    string word;
    int key;
    cin >> word >> key;
    for (char c : word) {
      c = ((c-key-A_VAL+SIZE) % SIZE) + A_VAL;
      cout << c;
    }

    cout << endl;
  }
}