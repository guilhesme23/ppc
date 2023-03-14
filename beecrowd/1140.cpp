#include <iostream>

using namespace std;

int main() {
  while(true) {
    string phrase;
    getline(cin, phrase);

    if(phrase[0] == '*') return 0;

    char first = tolower(phrase[0]);
    bool correct = true;
    for (size_t i = 0; i < phrase.size()-1; i++) {
      if (phrase[i] == ' ' && tolower(phrase[i + 1]) != first) {
        correct = false;
        break;
      } 
    }

    if (correct) {
      cout << 'Y' << endl;
    } else {
      cout << 'N' << endl;
    }
  }
}