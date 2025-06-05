int findMaximumBeauty(vector<int>& arr) {
    int beauty = 0;
    for (int num : arr) {
        if (num == beauty + 1) {
            beauty++;
        }
    }
    return beauty;
}
