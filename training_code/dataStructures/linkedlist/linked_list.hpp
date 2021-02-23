/*
 * Linked list
 *
 */

#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <cstdint>
#include <memory>

// TODO: Make template class
class LinkedList {
 private:
    struct Node {
        std::unique_ptr<Node> _next;
        Node *_prev;

        uint32_t _value;

        Node(const uint32_t val, Node *prev)
            : _next(nullptr), _prev(prev), _value(val) {}
    };

    std::unique_ptr<Node> _root;
    Node *_tail;
    uint32_t _cnt_nodes;

 public:
    LinkedList();
    LinkedList(const uint32_t);
    // TODO : Add parameter pack constructor (template?)
    ~LinkedList();

    LinkedList(const LinkedList &) = delete;
    LinkedList &operator=(const LinkedList &) = delete;

    // TODO : Default move constructor could work?
    // LinkedList(const LinkedList&&);
    // LinkedList& operator=(const LinkedList&&);

    // API
 public:
    void push_front(const uint32_t);
    void push_back(const uint32_t);

    void pop_front();
    void pop_back();

    uint32_t front() const;
    uint32_t back() const;

    uint32_t size() const;
};

#endif
