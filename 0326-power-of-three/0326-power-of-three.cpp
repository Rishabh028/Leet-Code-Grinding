class Solution {
public:
    bool isPowerOfThree(int n) {
    if (n == 0) return 0;

    while (n > 0){
        if (n == 1) return true;
        if (n % 3 != 0) break;
        n /= 3;
    }  return false;  
    }
};