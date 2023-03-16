#include <iostream>
#include <stack>
#include <sstream>

int main()
{
  int n;
  std::cin >> n;
  std::cin.ignore();
  while(n--) {
    std::string input;
    getline(std::cin, input);
    int total = 0;
    std::stack<char> st;
    for (char c : input) {
      if (c == '<') {
        st.push(c);
      }

      if (c == '>' && !st.empty()) {
        st.pop();
        total++;
      }
    }

    std::cout << total << std::endl;
  }
  
  return 0;
}