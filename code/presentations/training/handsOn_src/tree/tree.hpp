/*
 * Tree
 *
 * Rule:
 *                     root
 *              _________|__________
 *          --leaf               ++leaf
 *       ______|____          ______|_____
 *  --subleaf  ++subleaf  --subleaf  ++subleaf 
 */

#ifndef __TREE__
#define __TREE__

#pragma once

#include <memory>
#include <vector>
#include <cstdint>

class tree {
private:
  struct Node {
    std::vector<std::unique_ptr<Node>> _children;
    Node* _parent;
    uint32_t _value;
    Node(Node* parent, const uint32_t value) : _parent(parent), _value(value) {
        _children.reserve(2);
    }
    Node() _parent(nullptr), _value(0) {
      _children.reserve(2);
    }
  };
  std::unique_ptr<Node> _root;

  void release_subtree(std::unique_ptr<Node>);
  
  Node* search(const uint32_t) const;
public:
  tree(const tree&) = delete;
  tree& operator=(const tree&) = delete;



  tree();
  ~tree();

  // API
  void insert(const uint32_t);
  bool remove(const uint32_t);
  bool find(const uint32_t) const;
  void balance();
};

#endif
