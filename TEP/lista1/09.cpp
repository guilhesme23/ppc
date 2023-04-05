#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long;

int main() {
  ll sets, n_val, n_query, tmp;
  cin >> sets;
  while (sets--) {
    cin >> n_val >> n_query;
    vector<ll> box, q;
    queue<ll> raw;
    box.reserve(n_val);
    
    for(auto v = 0; v < n_val; v++) {
      cin >> tmp;
      raw.push(tmp);
    }

    ll prev = 0;
    for(auto i = 0; i < n_query; i++) {
      cin >> tmp;
      for (auto j = 0; j < tmp-prev; j++) {
        // If have elements to insert in the box, insert them.
        if (!raw.empty()) {
          // Ordered insert of first element of raw queue
          box.insert(lower_bound(box.begin(), box.end(), raw.front()), raw.front());
          // Remove used element from queue
          raw.pop();
        }
      }
      prev = tmp;
      cout << box[i] << '\n';
    }

    if (sets) cout << "\n";
  }

  return 0;
}