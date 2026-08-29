class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int count = 0;
        int temp = x;
        while (temp > 0) {
            count++;
            temp >>= 1;
        }

        int result = 0;
        for (int i = (count + 1) / 2; i >= 0; --i) {
            result |= (1 << i);
            if ((long long) result * result > x) {
                result ^= (1 << i);
            }
        }

        return result;       
    }
};