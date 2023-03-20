#include <iostream>

#include "../../utils/ast.hpp"
#include "../../utils/shellParser.hpp"

int main() {
  std::string input;
  std::vector<Token> tokens;
  while (std::cin >> input) {
    auto res = parse(input);
    tokens.insert(tokens.end(), res.begin(), res.end());
  }

  Tree ast(tokens);

  ast.printFilesystem(ast.root, 0);

  size_t res = 0;
  size_t freeSpace = abs(ast.maxSize - ast.root->size);
  size_t target = abs(30000000 - freeSpace);

  // ast.calculateSizeSum(ast.root, res);
  ast.findBestOption(ast.root, target, res);

  std::cout << res << std::endl;
  return 0;
}