class Solution {
    public boolean isNumber(String s) {
        boolean isFirst = true;
        boolean isDigitFound = false;
        boolean isDecimal = false;
        boolean isExponent = false;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '-' || c == '+') {
                if (!isFirst) {
                    return false;
                }
            } else if (c == 'e' || c == 'E') {
                if (isFirst || isExponent || !isDigitFound) {
                    return false;
                }
                isFirst = true;
                isDigitFound = false;
                isExponent = true;
                continue;
            } else if (c == '.') {
                if (isDecimal || isExponent) {
                    return false;
                }
                isDecimal = true;
            } else if (!Character.isDigit(c)) {
                return false;
            } else {
                isDigitFound = true;
            }
            isFirst = false;
        }
        return isDigitFound;
    }
}