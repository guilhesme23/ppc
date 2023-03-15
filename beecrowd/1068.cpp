#include <iostream>
#include <stack>

int main() {
  std::string input;
  while(std::cin >> input) {
    std::stack<char> st;
    bool result = true;
    for (auto c : input) {
      if (c == '(') {
        st.push(c);
      }

      if (c == ')') {
        if (st.empty()) {
          result = false;
          break;
        } else {
          st.pop();
        }
      }
    }

    if (result && !st.empty()) {
      result = false;
    }

    if (result) {
      std::cout << "correct" << std::endl;
    } else {
      std::cout << "incorrect" << std::endl;
    }
  }
}