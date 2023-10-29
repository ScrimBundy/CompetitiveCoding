class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (x == 1) return 1;

        bool is_int_min = (n == -2147483648);
        if (is_int_min) n++;
        bool is_negative = (n < 0);
        if (is_negative) n *= -1;

        double result = 1.0;
        double original_x = x;

        while (n != 0) {
            if (n & 1) {
                result *= x;
            }
            
            n >>= 1;

            x *= x;
        }

        if (is_int_min)
            result *= original_x;
        if (is_negative)
            result = 1 / result;

        return result;
    }
};