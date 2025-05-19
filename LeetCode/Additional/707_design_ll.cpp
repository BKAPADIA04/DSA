class Node {
    public:

        Node * next; 
        // Node * prev; 
        int val;

        Node(int data) {
            next = nullptr;
            // prev = nullptr;
            val = data;
        }
};

class MyLinkedList {

private:
    Node * head;

public:

    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        Node * temp = head;
        int count = 0;
        while(temp) {
            if(count == index) {
                return temp->val;
            }
            count++;
            temp = temp->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node * node = new Node(val);
        if(head == nullptr) {
            head = node;
            return;
        }
        node->next = head;
        head = node;
        return;
    }
    
    void addAtTail(int val) {
        Node * node = new Node(val);
        if(head == nullptr) {
            head = node;
            return;
        }
        Node * temp = head;
        while(temp && temp->next) {
            temp = temp->next;
        }
        temp->next = node;
        return;
    }
    
    void addAtIndex(int index, int val) {
        Node * node = new Node(val);
        if(index == 0) {
            addAtHead(val);
        }
        Node * temp = head;
        int count = 0;
        while(temp) {
            if((index - 1) == count) {
                Node * nextNode = temp->next;
                temp->next = node;
                node->next = nextNode;
                return;
            }
            count++;
            temp = temp->next;
        }
        if(index == count) addAtTail(val);
    }
    
    void deleteAtIndex(int index) {
        if(index == 0) {
            if(head) head = head->next;
            return;
        }
        Node * prev = nullptr;
        Node * curr = head;
        int count = 0;
        while(curr) {
            if(count == index) {
                if(curr->next) {
                    prev->next = curr->next;
                }
                else {
                    prev->next = nullptr;
                }
            }
            count++;
            prev = curr;
            curr = curr->next;
        }
    }
};

class Node {
    public:

        Node * next; 
        Node * prev; 
        int val;

        Node(int data) {
            next = nullptr;
            prev = nullptr;
            val = data;
        }
};

class MyLinkedList {

private:
    Node * head;

public:

    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        Node * temp = head;
        int count = 0;
        while(temp) {
            if(count == index) {
                return temp->val;
            }
            count++;
            temp = temp->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node * node = new Node(val);
        if(head == nullptr) {
            head = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
        return;
    }
    
    void addAtTail(int val) {
        Node * node = new Node(val);
        if(head == nullptr) {
            head = node;
            return;
        }
        Node * temp = head;
        while(temp && temp->next) {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
        return;
    }
    
    void addAtIndex(int index, int val) {
        Node * node = new Node(val);
        if(index == 0) {
            addAtHead(val);
        }
        Node * temp = head;
        int count = 0;
        while(temp) {
            if((index - 1) == count) {
                Node * nextNode = temp->next;
                temp->next = node;
                node->prev = temp;
                node->next = nextNode;
                if(nextNode) nextNode->prev = node;
                return;
            }
            count++;
            temp = temp->next;
        }
        if(index == count) addAtTail(val);
    }
    
    void deleteAtIndex(int index) {
        if(index == 0) {
            if(head) head = head->next;
            return;
        }
        Node * prev = nullptr;
        Node * curr = head;
        int count = 0;
        while(curr) {
            if(count == index) {
                if(curr->next) {
                    prev->next = curr->next;
                    curr->next->prev = prev;
                }
                else {
                    prev->next = nullptr;
                }
            }
            count++;
            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
