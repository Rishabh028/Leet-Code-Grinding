class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

            int n = nums.size();

            int id = indexDiff, vd = valueDiff;

            set<int> st;

            st.insert(nums[0]);

            for(int i=1 ; i<=min(id, n-1) ; i++){

                int l = nums[i] - vd, r = nums[i] + vd;

                auto it1 = st.lower_bound(l);

                if(it1 != st.end()){

                    if((*it1) <= r) return true;

                }

                st.insert(nums[i]);

            }

            for(int i=1, j=id+1 ; j<n ; i++, j++){

                st.erase(nums[i-1]);

                int l = nums[j] - vd, r = nums[j] + vd;

                auto it1 = st.lower_bound(l);

                if(it1 != st.end()){

                    if((*it1) <= r) return true;

                }

                st.insert(nums[j]);

            }

            return false;

        }
};