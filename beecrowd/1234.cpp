#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;

  while(getline(cin, input)) {
    bool up = true;
    for(char c : input) {
      if (c == ' ') {
        cout << c;
        continue;
      }

      if (up) {
        c = toupper(c);
      } else {
        c = tolower(c);
      }

      up = !up;
      cout << c;
    };

    cout << endl;
  }

  return 0;
}