#pragma once
#include <iostream>
#include <vector>

#include "shellParser.hpp"

struct File {
  std::string name;
  size_t size;
} typedef File;

std::ostream& operator<<(std::ostream& os, const File& f);

class Node {
 public:
  Node* parent;
  size_t size;
  std::string name;
  std::vector<Node*> children;
  std::vector<File> files;

  Node();
  Node(std::string name);
  ~Node();
  void updateSize();

  friend std::ostream& operator<<(std::ostream& os, const Node* obj);
};

class Tree {
 public:
  Node* root;
  Node* curr;
  size_t maxSize = 70'000'000;

  Tree();
  Tree(std::vector<Token> tokens);
  ~Tree();
  void addNode(Node* n);
  void changeDir(std::string dirname);
  Node* findDir(std::string dir);
  File findFile(std::string filename);
  void printFilesystem(Node* node, int ident);
  void calculateSizeSum(Node* node, size_t& acc);
  size_t findBestOption(Node* node, size_t target, size_t& acc);

  friend std::ostream& operator<<(std::ostream& os, const Tree& obj);
};
