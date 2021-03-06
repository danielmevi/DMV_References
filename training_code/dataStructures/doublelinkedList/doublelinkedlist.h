// Double Linked List with cache
// Daniel Medina
//

#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache {
    public:
        LRUCache(int const capacity) : Cache{} {
            Cache::cp = capacity;
            Cache::tail = NULL;
            Cache::head = NULL;
        }
    virtual void set(int const key, int const value){
        if (auto const it {mp.find(key)};
                it == mp.end()){
            auto new_head_node{new Node(key, value)};

            if (!Cache::head){
                Cache::tail = new_head_node;
            } else {
                new_head_node->next = Cache::head;
                new_head_node->next->prev = new_head_node;
            }
            Cache::head = new_head_node;
            Cache::mp.emplace(key, new_head_node);

            if (Cache::mp.size() == Cache::cp + 1){
                auto tmp{Cache::tail->prev};
                Cache::tail->prev->next = NULL;
                Cache::mp.erase(Cache::tail->key);
                delete Cache::tail;
                Cache::tail = tmp;
            }
        }
        else {
            it->second->value = value;
            if (Cache::head == it->second){
                return;
            } else if (Cache::tail == it->second){
                it->second->prev->next = NULL;
                Cache::tail = it->second->prev;
            } else{
                it->second->prev->next = it->second->next;
                it->second->next->prev = it->second->prev;
            }
            Cache::head->prev = it->second;
            it->second->next = Cache::head;
            it->second->prev = NULL;
            Cache::head = it->second;
        }
    }

    virtual int get(int k) {
        if (auto const it{Cache::mp.find(k)};
                    it == Cache::mp.end()){
            return -1;
        } else {
            return it->second->value;
        }
    }
};
