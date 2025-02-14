class ProductOfNumbers {
public:

    vector<int>pre; int length = 0;

    ProductOfNumbers() {
        pre.push_back(1); length++;
    }
    
    void add(int num) {
        if(num != 0) {
            pre.push_back(num * pre[length-1]); length++;
        }
        else {
            pre.clear(); length = 0;
            pre.push_back(1); length++;
        }
    }
    
    int getProduct(int k) {
        if(length - 1 < k) return 0;
        return pre[length-1] / pre[length-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
