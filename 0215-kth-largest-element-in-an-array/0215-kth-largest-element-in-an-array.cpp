class Solution {
private:
    pair<int,int> partition(vector<int>& nums, int l, int r){
        int idx = rand()%(r-l+1) + l;
        int val = nums[idx];
        int cur = l;
        while(cur<=r){
            if(nums[cur]==val){
                cur++;
            }
            else if(nums[cur]>val){ // in reverse order as we need kth largets ele
                swap(nums[l], nums[cur]);
                cur++; l++;
            }
            else{
                swap(nums[r], nums[cur]);
                r--;
            }
        }
        return {l,cur-1};
    }

    void quickSelect(vector<int>& nums, int k, int l, int r){
        auto [idx1, idx2] = partition(nums, l, r);
        if(k>=idx1 && k<=idx2)return;
        if(idx1>k)quickSelect(nums,k,l,idx1-1);
        else quickSelect(nums,k,idx2+1,r);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0)); 
        int n = nums.size();
        k--; 
        quickSelect(nums, k, 0, n-1);
        return nums[k];
    }
};