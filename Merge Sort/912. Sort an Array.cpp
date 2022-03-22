class Solution {
public:
    // Solve By Merge Sort
    void mergeSort(vector<int> &nums, int l, int r) {
        if(l < r) {
            int mid = (l+r)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, r);
            merge(nums, l, mid, r);
        }
    }
    
    void merge(vector<int> &nums, int l, int mid, int r) {
        int n1 = mid-l+1, n2 = r-mid;
        vector<int> a(n1), b(n2);

        for(int i = 0; i < n1; i++) {
            a[i] = nums[i + l];
        }

        for(int j = 0; j < n2; j++) {
            b[j] = nums[mid + 1 + j];
        }
        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2) {
            if(a[i] <= b[j]) nums[k++] = a[i++];
            else nums[k++] = b[j++];
            // k++;
        }
        // if a/n1 is left
        while(i < n1) 
            nums[k++] = a[i++];
        // if b/n2 is left
        while(j < n2) 
            nums[k++] = b[j++];
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        mergeSort(nums, 0, n-1);
        return nums;
    }
};