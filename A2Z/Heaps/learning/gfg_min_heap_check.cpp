bool check(int arr[],int n,int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (i >= n) return true;
        
        if(left < n && arr[left] > arr[i]) return false;
        
        if(right < n && arr[right] > arr[i]) return false;
        
        return check(arr,n,left) && check(arr,n,right);
    }
    
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int i = 0;
        return check(arr,n,i);
    }