#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * constructLL(vector<int>& arr) {
    // code here
    int n = arr.size();
    if (n == 0) {
        return nullptr; // Handle empty input vector
    }
    ListNode * head = new ListNode (arr[0]);
    head -> next = nullptr;

    ListNode * temp =  head;
    for(int i = 1;i < n;i++) {
        ListNode  * curr = new ListNode (arr[i]);
        temp->next = curr;
        temp = temp->next;
    }
    return head;
}

void print(ListNode * head) {
    ListNode * temp =  head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

vector<int>DutchNationalFlagAlgo(vector<int>nums) {
    int n = nums.size();
    int low = 0; int mid = 0; int high = n - 1;
    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[mid],nums[low]);
            low++; mid++;
        }
        else if(nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid],nums[high]);
            high--;
        }
    }
    return nums;
}


ListNode* segregate(ListNode *head) {
    ListNode * curr = head;
    vector<int>nums;
    while(curr) {
        nums.push_back(curr->val);
        curr = curr -> next;
    }
    nums = DutchNationalFlagAlgo(nums);
    curr = head;
    int i = 0;
    while(curr) {
        curr->val = nums[i++];
        curr = curr->next;
    }
    return head;
}

int main() {
    vector<int>nums = {2,2,0,1};
    ListNode * head = constructLL(nums);
    print(head);
    head = segregate(head);
    print(head);
}