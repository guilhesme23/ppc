#include <iostream>
#include <map>

using namespace std;

int main() {
  int N, a, b;
  cin >> N >> a >> b;

  map<int,int> choices;
  int option;
  int i = 1;
  while(N--) {
    cin >> option;
    choices[option] = i;
    ++i;
  }
  cout << choices[a+b] << '\n';
}
