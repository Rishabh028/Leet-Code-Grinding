class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256,0);

        for(char c : t){
            freq[c]++;
        }

        int left = 0;
        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++){
            if(freq[s[right]] > 0){
                count --;
            }

            freq[s[right]]--;

            while(count == 0){
                if(right - left < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if(freq[s[left]] > 0){
                    count++;
                }
                left++;
            }

        }
    
        if(minLen == INT_MAX){
            return "";
        }

        return s.substr(start,minLen);
    }
};