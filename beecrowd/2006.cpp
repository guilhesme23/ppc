#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, int> choices = {
    {1, 0},
    {2, 0},
    {3, 0},
    {4, 0},
  };

  int correct, guesses[5];
  cin >> correct >> guesses[0] >> guesses[1] >> guesses[2] >> guesses[3] >> guesses[4];

  for(auto guess : guesses) {
    choices[guess] += 1;
  }

  cout << choices[correct] << endl;
  return 0;
}