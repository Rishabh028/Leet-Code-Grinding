class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> ugly(n), pointers(k, 0);
        vector<long long> next_num(k);
        for(int i = 0; i < k; i++) {
            next_num[i] = primes[i];
        }
        ugly[0] = 1;
        for(int i = 1; i < n; i++) {
            long long next = INT_MAX;
            for(int j = 0; j < k; j++) {
                next = min(next, next_num[j]);
            }
            ugly[i] = next;
            for(int j = 0; j < k; j++) {
                if(next == next_num[j]) {
                    pointers[j]++;
                    next_num[j] = 1LL*primes[j]*ugly[pointers[j]];
                }
            }
        }
        return ugly[n-1];
    }
};
