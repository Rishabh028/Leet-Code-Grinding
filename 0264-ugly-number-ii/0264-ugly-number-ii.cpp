class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(1);
        ugly[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;
        
        for (int i = 1; i < n; i++){
            int a = ugly[i2] * 2;
            int b = ugly[i3] * 3;
            int c = ugly[i5] * 5;

            int nextUgly = min({a, b, c});
            ugly.push_back(nextUgly);

            if (a == nextUgly) i2++;
            if (b == nextUgly) i3++;
            if (c == nextUgly) i5++;
        }
        return ugly[n-1];
    }
};