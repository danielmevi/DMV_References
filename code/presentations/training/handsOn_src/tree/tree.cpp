/*
 *
 */

#include "tree.hpp"

tree::tree() : _root() {}

tree::~tree() { release_subtree(std::move(_root)); }

void tree::release_subtree(std::unique_ptr<Node> pNode) {
  while (pNode->_children.size() > 0) {
    auto leaf = pNode->_children;
    while (leaf[0]->_children.size() > 0) {
      leaf = leaf[0]->_children;
    }
    leaf.pop_back();
  }
}

void tree::insert(const uint32_t value) {
  // Do not do nothing if value is found in tree
  //
  // Initialize if needed
  //
  // Set root to current node
  // Is new Node up or down current node
  // Create node in left or right if children < 2
  // Set current node left or right
  // Create node in left or right if children < 2
}

bool tree::remove(const uint32_t value) {}

bool tree::find(const uint32_t value) const {
  if (search(value)) {
    return true;
  } else {
    return false;
  }
}

tree::Node* tree::search(const uint32_t value) const {}
