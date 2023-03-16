#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::string input;
  size_t total = 0, max = 0;
  std::vector<int> calories;
  while (getline(std::cin, input)) {
    if (input != "") {
      total += std::stoi(input);
    } else {
      if (total > max) max = total;
      calories.push_back(total);
      total = 0;
    }
  }

  std::sort(calories.rbegin(), calories.rend());
  std::cout << calories[0] + calories[1] + calories[2] << std::endl;

  return 0;
}