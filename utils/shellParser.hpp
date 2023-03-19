#pragma once
#include <vector>
#include <iostream>

struct Token {
  std::string name;
  std::string value;
} typedef Token;

std::ostream& operator<<(std::ostream& os, Token& tk);

std::vector<Token> parse(std::string input);

bool is_number(const std::string& s);
