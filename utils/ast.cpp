#include "ast.hpp"
#include <iterator>

Node::Node() {
  this->parent = nullptr;
  this->size = 0;
  this->name = "";
}

Node::Node(std::string name) {
  this->parent = nullptr;
  this->size = 0;
  this->name = name;
}

Node::~Node() {
  for (auto c : children) {
    delete c;
    c = nullptr;
  }
}

void Node::updateSize() {
  for (auto c : this->children) {
    c->updateSize();
  }

  size_t filesSize = 0;
  size_t dirsSize = 0;

  for (auto f : this->files) {
    filesSize += f.size;
  }

  for (auto c : this->children) {
    dirsSize += c->size;
  }

  this->size = filesSize + dirsSize;
}

Tree::Tree() {
  this->root = nullptr;
  this->curr = nullptr;
}

Tree::Tree(std::vector<Token> tokens) {
  for (auto tk = tokens.begin(); tk != tokens.end(); tk++) {
    if (tk->name == "modifier") {

      std::string dirName = std::next(tk)->value;
      Node *n = this->findDir(dirName);
      if (n == nullptr) {
        n = new Node(dirName);
        this->addNode(n);
      };
    
    } else if (tk->name == "filesize") {
    
      std::string filename = std::next(tk)->value;
      File f = this->findFile(filename);
      if (f.name != "") continue;
      size_t filesize = std::stoul(tk->value);
      this->curr->files.push_back({
        name: filename,
        size: filesize
      });
    
    } else if (tk->name == "command" && tk->value == "cd") {
    
      this->changeDir(std::next(tk)->value);
    
    }
  }

  this->root->updateSize();
}

Tree::~Tree() {
  if (this->root != nullptr) delete root;
  this->root = nullptr;
}

void Tree::addNode(Node* n) {
  if (this->root == nullptr) {
    this->root = n;
    this->curr = this->root;
  } else {
    n->parent = this->curr;
    this->curr->children.push_back(n);
  }
}

void Tree::changeDir(std::string dirname) {
  if (dirname == "..") {
    this->curr = this->curr->parent;
    return;
  }

  Node* n = this->findDir(dirname);
  if (n == nullptr) {
    n = new Node(dirname);
    this->addNode(n);
  } else {
    this->curr = n;
  }
}

Node* Tree::findDir(std::string dir) {
  if (this->curr != nullptr) {
    for (auto d : this->curr->children) {
      if (d->name == dir) return d;
    }
  }

  return nullptr;
}

File Tree::findFile(std::string filename) {
  for (auto f : this->curr->files) {
    if (f.name == filename) {
      return f;
    }
  }

  return File({
    name: "",
    size: 0
  });
}

void Tree::printFilesystem(Node* node, int ident) {
  if (node == nullptr || node == NULL) {
    return;
  }

  std::string padding = "";
  for (int x = 0; x < ident; x++) {
    padding += "-\t";
  }

  std::cout << padding << node << " [" << node->size << "]" << "\n";
  for (auto n : node->children) {
    std::cout << padding << n->name << " (dir)" << "\n";
  }

  for (auto f : node->files) {
    std::cout << padding << f << "\n";
  }

  for (auto n : node->children) {
    printFilesystem(n, ident+1);
  }
  // std::cout << node;
  // std::cout << std::endl;
}

void Tree::calculateSizeSum(Node* node, size_t& acc) {
  if (node->size <= 100000) {
    acc += node->size;
  }

  for (auto n : node->children) {
    calculateSizeSum(n, acc);
  }
}

size_t Tree::findBestOption(Node* node, size_t target, size_t& acc) {
  if (node->size >= target && (node->size < acc || acc == 0)) {
    acc = node->size;
  }

  for (auto n : node->children) {
    findBestOption(n, target, acc);
  }

  return acc;
}

std::ostream& operator<<(std::ostream& os, const Node* obj) {
  if (obj->parent != nullptr && obj->parent->name == "/") {
    os << obj->parent << obj->name;
  } else if (obj->parent != nullptr) {
    os << obj->parent << "/" << obj->name;
  } else {
    os << obj->name;
  }

  return os;
}

std::ostream& operator<<(std::ostream& os, const File& f) {
  os << f.size << " " << f.name;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Tree& obj) {
  os << obj.curr;
  return os;
}
