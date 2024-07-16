#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
        public:
            int key;
        int val;
        Node * next, * prev;

        Node(int key_,int val_) {
            key = key_;
            val = val_;
            next = prev = nullptr;
        }
    };

    int cap;
    unordered_map < int, Node * > u_map;
    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void addNode(Node * newNode) {
        Node * temp = head -> next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp -> prev = newNode;
    }

    void deleteNode(Node * node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if(u_map.find(key) != u_map.end()) {
            Node * map_value = u_map[key];
            int answer = map_value->val;
            u_map.erase(key);
            deleteNode(map_value);
            addNode(map_value);
            u_map[key] = head -> next;
            return answer;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node * newNode = new Node(key,value);

        if(u_map.find(key) != u_map.end()) {
            Node * existNode = u_map[key];
            u_map.erase(existNode->key);
            deleteNode(existNode);
        }

        if(u_map.size() == cap) {
            u_map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(newNode);
        u_map[key] = head->next;
    }
};