#include <cmath>
#include <iostream>
#include <iterator>
#include <math.h>
#include <vector>

using namespace std;

using rn = pair<int, int>;

// Reference:
// https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/II/264%20-%20Count%20on%20Cantor.cpp

int main() {
  int N;
  while (cin >> N) {
    int q, d, total = 1, curr = 1;

    // Set curr position in the correct diagonal
    while(total < N) {
      ++curr; // Increment current diagonal;
      total += curr; // Each diagonal step adds the same amount of elements to the total;
      // After the total catches up to N, we are in the correct diagonal;
    }

    int pos = curr*(curr-1)/2 + 1; // Confused on this one, my guess is something about triangular numbers;
    int step = 1;
    // Check if we are counting from down up or up down;
    if (curr&1) { // Odd
      q = curr;
      d = 1;
      step = -1;
    } else {
      d = curr;
      q = 1;
    }

    // Count in the diagonal until we find the N-th element
    while (pos != N) {
      q += step;
      d -= step;
      pos++;
    }

    cout << "TERM " << pos << " IS " << q << '/' << d << '\n';
  }
}
