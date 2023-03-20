#pragma once
#include <vector>
#include <iostream>
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

    friend std::ostream& operator<<(std::ostream& os, const Node* obj);
};

class Tree {
  public:
    Node* root;
    Node* curr;
    
    Tree();
    Tree(std::vector<Token> tokens);
    ~Tree();
    void addNode(Node* n);
    void changeDir(std::string dirname);
    Node* findDir(std::string dir);
    File findFile(std::string filename);
    void printFilesystem(Node* node);

    friend std::ostream& operator<<(std::ostream& os, const Tree& obj);
};
