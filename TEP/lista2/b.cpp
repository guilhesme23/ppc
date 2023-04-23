#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void print_vec(vector<int> v) {
  cout << "[";
  for (auto el = v.begin(); el != v.end(); ++el) {
    string sep = ",";
    if (el == v.begin()) sep = ";";
    if (next(el) == v.end()) sep = "]\n";
    cout << *el << sep; 
  }
}
int main() {
  int v1, v2;
  while(cin >> v1 >> v2) {
    vector<int> rational = {v1, v2};
    vector<int> result;

    for (auto i = 1UL; i < rational.size(); ++i) {
      int q = rational[i-1] / rational[i];
      int rem = rational[i-1] % rational[i];
      if (!q && rational.size() > 2) break;
      if (!rem) {
        result.push_back(rational[i-1]);
        break;
      } 

      rational.push_back(rem);
      result.push_back(q);
    }

    print_vec(result);
  }
}
