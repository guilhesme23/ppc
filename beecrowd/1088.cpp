#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

size_t merge(vector<int> left, vector<int> right, vector<int>& target) {
  size_t l = 0, r = 0, i = 0;
  size_t swaps = 0;
  
  while(l < left.size() && r < right.size()) {
    if (left[l] <= right[r])
    {
      target[i] = left[l];
      l++;
      i++;
    }
    else
    {
      target[i] = right[r];
      r++;
      i++;
      swaps += ( left.size() - l );
    }
  }

  while(l < left.size()) {
    target[i] = left[l];
    l++;
    i++;
  }
  
  while(r < right.size()) {
    target[i] = right[r];
    r++;
    i++;
  }

  return swaps;
}

// return number of swaps
size_t merge_sort(vector<int>& array) {
  size_t len = array.size();
  if (len <= 1) return 0;

  size_t half = ceil(len / 2);

  vector<int> left;
  vector<int> right;

  left.assign(array.begin(), array.begin() + half);
  right.assign(array.begin() + half, array.end());

  auto swaps1 = merge_sort(left);
  auto swaps2 = merge_sort(right);
  auto swaps3 = merge(left, right, array);

  return swaps1+swaps2+swaps3;
}

int main() {
  int qtd;
  size_t s;

  while(cin >> qtd) {
    if (!qtd) break;

    vector<int> nums;
    for (auto i = 0; i < qtd; ++i) {
      int tmp;
      cin >> tmp;
      nums.push_back(tmp);
    }
    
    s = merge_sort(nums);

    if(s%2==0) {
      cout << "Carlos\n";
    } else {
      cout << "Marcelo\n";
    }
  }

  return 0;
}