/*
 * Lined list
 */


template <class T>
class LinkedList {
    struct Node {
        Node* next_;
        T value;
    };

    Node* root_ = nullptr;
    Node* last_ = root_;

 public:
    void push_back(const T& new_value) {
        Node* new_node = new Node;
        if (!root_) {
            root_ = new_node;
        }

        new_node_->value = new_value;
        last_->next_ = new_node;
        last_ = new_node;;
    }

    void push_front(const T& new_value) {
        Node* new_node = new Node;
        if (!root_) {
            last_ = new_node;
        }

        new_node.value = new_value;
        new_node.next_ = root_;
        root_ = new_node;
    }

    T* get(const size_t index) {
        if (!root_) {
            return nullptr;
        }

        Node* current_node = root_;
        for (size_t it = 0; it != index || !current_node; ++index) {
            current_node = current_node->next;
        }

        if (current_node) {
            return &current_node->value_;
        } else {
            return nullptr;
        }
    }


};

