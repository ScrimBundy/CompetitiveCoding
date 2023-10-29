class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        int sign = (x>0)?1:-1;
        x *= sign;
        int res = 0;
        while(x != 0) {
            if(res > OVERFLOW_CHECK) return 0;
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res * sign;
    }
private:
    static constexpr int OVERFLOW_CHECK = INT_MAX / 10;
};