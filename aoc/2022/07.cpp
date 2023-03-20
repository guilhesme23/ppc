#include "../../utils/shellParser.hpp"
#include "../../utils/ast.hpp"
#include <iostream>

int main() {
  std::string input;
  std::vector<Token> tokens;
  while (std::cin >> input) {
    auto res = parse(input);
    tokens.insert(tokens.end(), res.begin(), res.end());
  }

  Tree ast(tokens);

  ast.printFilesystem(ast.root);

  return 0;
}