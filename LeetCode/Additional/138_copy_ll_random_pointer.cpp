/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void print(Node * head) {
        Node *curr = head;
        while(curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node * curr = head;
        // interweave
        while(curr) {
            Node * newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // random pointer assignment
        curr = head;
        while(curr) {
            if(curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // separate original and deep copy
        curr = head;
        Node * dummy = new Node(-1);
        Node * temp = dummy;
        while(curr) {
            Node * originalNext = curr->next->next;
            temp->next = curr->next;
            temp = temp->next;
            curr->next = originalNext;
            curr = curr->next;
        }
        return dummy->next;
    }
};

/*class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*>m;
        queue<Node*>q;
        q.push(head);
        m[head] = new Node(head->val);
        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            Node* clone = m[curr];
            if(curr->next){
                if (m.find(curr->next) == m.end()) {
                    m[curr->next] = new Node(curr->next->val);
                    q.push(curr->next);
                }
                clone->next = m[curr->next];
            }
          
            if(curr->random){
                if (m.find(curr->random) == m.end()) {
                    m[curr->random] = new Node(curr->random->val);
                    q.push(curr->random);
                }
                clone->random = m[curr->random];
            }
        }

        return m[head];
    }
};*/
