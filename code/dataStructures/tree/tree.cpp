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

bool tree::insert(const uint32_t value) {
  if (_root) {
    Node* current = _root.get();
    bool inserted = false;
    while (not inserted) {
      if (current->_value == value) {
        return true;
      }

      switch (current->_children.size()) {
        case 0: {
          current->_children.emplace_back(
              std::make_unique<Node>(current->_parent, value));
          inserted = true;
          break;
        }
        case 1: {
          if (current->_children[0]->_value < value) {
            current->_children.emplace_back(
                std::make_unique<Node>(current->_parent, value));
          } else {
            current->_children.emplace(
                current->_children.begin(),
                std::make_unique<Node>(current->_parent, value));
          }
          inserted = true;
          break;
        }
        case 2: {
          const uint32_t leftVal = current->_children[0]->_value;
          const uint32_t rightVal = current->_children[1]->_value;
          if (value < leftVal) {
            current = current->_children[0].get();
            break;
          } else if (rightVal < value) {
            current = current->_children[1].get();
            break;
          }
        }
        default: {
          throw std::runtime_error("Tree internal corruption");
          return true;
        }
      };
    };
  } else {
    _root = std::make_unique<Node>(nullptr, value);
  }
  return false;
}

bool tree::remove(const uint32_t value) {
  Node* toRemove = search(value);
  if (not toRemove) {
    return true;
  } else {
    // TODO
  }
  return false;
}

bool tree::find(const uint32_t value) const {
  if (search(value)) {
    return true;
  } else {
    return false;
  }
}

tree::Node* tree::search(const uint32_t value) const {
  Node* current = _root.get();

  while (true) {
    if (current->_value == value) {
      return current;
    } else {
      switch (current->_children.size()) {
        case 0: {
          return nullptr;
          break;
        }
        case 1: {
          current = current->_children[0].get();
          break;
        }
        case 2: {
          if (value < current->_value) {
            current = current->_children[0].get();
            break;
          } else if (current->_value < value) {
            current = current->_children[1].get();
            break;
          }
        }
        default: { throw std::runtime_error("Tree internal corruption"); }
      };
    }
  }
}
