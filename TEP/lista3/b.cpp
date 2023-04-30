#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main() {
  int N;
  while(cin >> N and N > 0) {
    string input;
    string guess;
    cin >> input >> guess;
    
    int chances = 7;
    istringstream is(input), gs(guess);
    
    set<char> guesses, correct, answer;

    char tmp;
    while(is >> tmp) {
      correct.insert(tmp);
    }

    while(gs >> tmp and chances and correct.size() != answer.size()) {
      if (correct.find(tmp) != correct.end()) {
        guesses.insert(tmp);
        answer.insert(tmp);
        continue;
      }

      if (guesses.find(tmp) == guesses.end()) {
        guesses.insert(tmp);
        --chances;
      }
    }

    cout << "Round " << N << '\n';

    if (answer.size() == correct.size() and chances) {
      cout << "You win.\n";
    } else if (answer.size() != correct.size() and chances) {
      cout << "You chickened out.\n";
    } else {
      cout << "You lose.\n";
    }
  }
}
