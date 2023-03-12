#include <iostream>

using namespace std;

int main() {
  string tweet;
  getline(cin, tweet);
  if (tweet.length() > 140) {
    cout << "MUTE" << endl;
  } else {
    cout << "TWEET" << endl;
  }

  return 0;
}