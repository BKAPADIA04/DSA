#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int key;
    int val;
    int counter;
    Node * next, * prev;

    Node(int key_,int val_,int cnt_) {
        key = key_;
        val = val_;
        counter = cnt_;
        next = prev = nullptr;
    }
};

class DLL {
    public:
        int length;
        Node * head;
        Node * tail;

        DLL() {
            head = new Node(-1,-1,0);
            tail = new Node(-1,-1,0);
            head->next = tail;
            tail->prev = head;
            length = 0;
        }

        void addNode(Node * newNode) {
            Node * temp = head -> next;
            newNode->next = temp;
            newNode->prev = head;
            head->next = newNode;
            temp->prev = newNode;
            length++;
        }

        void deleteNode(Node * node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            length--;
        }
};


class LFUCache {
    map<int,Node *> key_val_map;
    map<int,DLL *> freq_map;
    int cap;
    int min_freq;
    int curr_length;
    public:
        LFUCache(int capacity) {
            cap = capacity;
            min_freq = 0;
            curr_length = 0;
        }

        void updateFreqMap(Node * node) {
            int curr_freq = node->counter;
            DLL * curr_freq_dll = freq_map[curr_freq];
            curr_freq_dll->deleteNode(node);
            key_val_map.erase(node->key);

            if(node->counter == min_freq && freq_map[node->counter]->length == 0) {
                min_freq += 1;
            }

            int updated_freq = curr_freq + 1;
            DLL * updated_freq_dll = new DLL();
            if(freq_map.find(node->counter + 1) != freq_map.end()) {
                updated_freq_dll = freq_map[updated_freq];
            }
            node->counter = updated_freq;
            updated_freq_dll->addNode(node);
            freq_map[node->counter] = updated_freq_dll;
            key_val_map[node->key] = node;
        }

        int get(int key) {
            if(key_val_map.find(key) != key_val_map.end()) {
                Node * node = key_val_map[key];
                updateFreqMap(node);
                return key_val_map[key]->val ;
            }
            return -1;
        }

        void put(int key, int value) {
            Node * newNode = new Node(key,value,1);

            if(cap == 0) return;

            if(key_val_map.find(key) != key_val_map.end()) {
                Node * existNode = key_val_map[key];
                existNode -> val = value;
                updateFreqMap(existNode);
            }
            else {
                if(key_val_map.size() == cap) {
                    DLL * min_freq_dll = freq_map[min_freq];
                    key_val_map.erase(min_freq_dll->tail->prev->key);
                    freq_map[min_freq]->deleteNode(min_freq_dll->tail->prev);
                }
                min_freq = 1;
                DLL * min_freq_dll = new DLL();
                if(freq_map.find(min_freq) != freq_map.end()) {
                    min_freq_dll = freq_map[min_freq];
                }
                min_freq_dll->addNode(newNode);
                freq_map[min_freq] = min_freq_dll;
                key_val_map[key] = newNode;
            }
        }
};
