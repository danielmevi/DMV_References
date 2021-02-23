#include "linked_list.hpp"

LinkedList::LinkedList() : _root(nullptr), _tail(nullptr), _cnt_nodes(0) {}
LinkedList::LinkedList(const uint32_t val)
    : _root(std::make_unique<Node>(val, nullptr)),
      _tail(_root.get()),
      _cnt_nodes(0) {}
LinkedList::~LinkedList() {
    while (_root) {
        pop_back();
    }
}

uint32_t LinkedList::size() const { return _cnt_nodes; }
void LinkedList::push_front(const uint32_t val) {
    auto new_first = std::make_unique<Node>(val, nullptr);
    _root->_prev = new_first.get();
    new_first->_next = std::move(_root);
    _root = std::move(new_first);
    ++_cnt_nodes;
}
void LinkedList::push_back(const uint32_t val) {
    // TODO: Optimize to initialized type instead of pointer checks
    if (_root and _tail) {
        _tail->_next = std::make_unique<Node>(val, _tail);
        _tail = _tail->_next.get();
    } else {
        _root = std::make_unique<Node>(val, nullptr);
        _tail = _root.get();
    }
    ++_cnt_nodes;
}
void LinkedList::pop_front() {
    _root = std::move(_root->_next);
    --_cnt_nodes;
}
void LinkedList::pop_back() {
    if (_tail->_prev) {
        _tail->_prev->_next.reset(nullptr);
        _tail = _tail->_prev;
    } else {
        _root.reset(nullptr);
    }
    --_cnt_nodes;
}
uint32_t LinkedList::front() const { return _root->_value; }
uint32_t LinkedList::back() const { return _tail->_value; }
