#include <iostream>
#include <bitset>

using namespace std;

const auto BITSIZE=32;

class Node {
  public:
    Node* left;
    Node* right;
    int val;

    Node(int val) {
      this->val = val;
      left = nullptr;
      right = nullptr;
    };

    Node() {
      this->val = -1;
      left = nullptr;
      right = nullptr;
    };

    ~Node() {
      if (left != nullptr) delete left;
      if (right != nullptr) delete right;
    }
};

class Tree {
  Node* root;
  bitset<BITSIZE> total;

  public:
  Tree() {
    root = new Node();
    total = bitset<BITSIZE> {0};
  }

  ~Tree() {
    if (root != nullptr) delete root;
  }

  bool insert(bitset<BITSIZE> bits) {
    Node* curr = root;
    for (size_t i = 0; i < bits.size(); i++) {
      Node* tmp = new Node(bits[i]);

      if (tmp->val) {
        if (curr->right == nullptr) curr->right = tmp;
        curr = curr->right;
        continue;
      } else {
        if (curr->left == nullptr) curr->left = tmp;
        curr = curr->left;
        continue;
      }
    }

    return curr == nullptr;
  }

  uint32_t findBestMask(bitset<BITSIZE> bits) {
    Node* curr = root;
    bitset<BITSIZE> result(0);

    for (size_t i = 0; i < bits.size(); i++) {
      uint32_t l, r;
      l = sumSubTree(curr->left);
      r = sumSubTree(curr->right);

      if (l > r) {
        curr = curr->left;
      } else if (r > l) {
        curr = curr->right;
      } else {
        if (!bits[i] && curr->right) {
          curr = curr->right;
        } else if (curr->left != nullptr) {
          curr = curr->left;
        } else {
          curr = curr->right;
        }
      }

      if (curr != nullptr) result.set(i, curr->val);
    }

    return result.to_ulong();
  };

  uint32_t sumSubTree(Node* it) {
    if (it == nullptr) return 0;
    return it->val + sumSubTree(it->left) + sumSubTree(it->right);
  }

  uint32_t getOptimal(Node* it) {
    // O que fazer aqui?
  }
};

uint32_t solve(bitset<BITSIZE> n, uint32_t l, uint32_t u) {

  Tree t;
  // Prepare the tree
  for (auto x = l; x <= u; x++) {
    bitset<BITSIZE> bits(x);
    t.insert(bits);
  }

  return t.findBestMask(n);
}

int main() {
  uint32_t l, u, tmp;

  while(cin >> tmp >> l >> u) {
    bitset<BITSIZE> n(tmp);
    cout << solve(n,l,u) << '\n';
  };

  return 0;
}