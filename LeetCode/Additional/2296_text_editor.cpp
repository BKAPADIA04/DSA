class Node {
    public:
    char val;
    Node * prev;
    Node * next;

    Node(char value) {
        val = value;
        prev = next = nullptr;
    }
};

class DLL {
    public:
    int length;
    Node * head;
    Node * tail;

    DLL() {
        head = new Node('\0');
        tail = new Node('\0');

        head->next = tail;
        tail->prev = head;
        length = 0;
    }

    void addNode(Node * curr, Node * newNode) {
        Node * temp = curr->next;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = curr;
        curr->next = newNode;
        length++;
    }

    void deleteNode(Node * node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        length--;
    }
};

class TextEditor {
public:

    DLL * editor;
    Node * curr;

    void print() {
        Node * temp = editor->head->next;
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    TextEditor() {
        editor = new DLL();
        curr = editor->head;
    }
    
    void addText(string text) {
        for(int i = 0;i < text.size();i++) {
            char ch = text[i];
            Node * newCh = new Node(ch);
            editor->addNode(curr,newCh);
            curr = curr->next;
        }
        // print();
    }
    
    int deleteText(int k) {
        int temp = k;
        while(curr != editor->head && temp > 0) {
            Node * previous = curr->prev;
            Node * tempo = curr;
            editor->deleteNode(tempo);
            curr = previous;
            temp--;
        }
        // print();
        return k - temp;
    }
    
    string cursorLeft(int k) {
        while(curr != editor->head && k > 0) {
            curr = curr->prev;
            k--;
        }
        Node * tempWrite = curr;
        int move = min(10,editor->length);
        // cout << move << endl;
        string ans = "";
        while(tempWrite != editor->head && move > 0) {
            move--;
            ans += tempWrite->val;
            tempWrite = tempWrite->prev;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string cursorRight(int k) {
        while(curr != editor->tail->prev && k > 0) {
            curr = curr->next;
            k--;
        }
        Node * tempWrite = curr;
        int move = min(10,editor->length);
        // cout << move << endl;
        string ans = "";
        while(tempWrite != editor->head && move > 0) {
            move--;
            ans += tempWrite->val;
            tempWrite = tempWrite->prev;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

 /*
 class TextEditor {
public:
    stack<char>left;
    stack<char>right;
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(int i = 0; i < text.size(); i++){
            left.push(text[i]);
        }
    }
    
    int deleteText(int k) {
        int count = 0;
        while(k -- > 0 && !left.empty()){
            count++;
            left.pop();
        }
        return count;
    }
    string getDigit10(){
        int size = left.size();
        int n = min(size, 10);

        string res;
        while(n -- > 0 && !left.empty()){
            char c = left.top();
            left.pop();
            res.push_back(c);
        }

        reverse(res.begin(),res.end());

        for(int i = 0; i < res.size(); i++){
            left.push(res[i]);
        }
        return res;
    }
    string cursorLeft(int k) {
        while(k -- > 0 && !left.empty()){
            char c = left.top();
            left.pop();

            right.push(c);
        }
        return getDigit10();
    }
    
    string cursorRight(int k) {
        while(k -- > 0 && !right.empty()){
            char c = right.top();
            right.pop();

            left.push(c);
        }
        return getDigit10();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
