class Solution {
public:
    int getSum(int a, int b) {
        // store the carry bits
        unsigned int carry = (a & b);
        // store the sum without carry
        unsigned int psum = a ^ b;
        while(carry != 0) {
            // shift the carry bits
            carry <<= 1;
            // add together carry bits and previous sum
            unsigned int x = psum ^ carry;
            // get new carry bits
            carry &= psum;
            // store new sum
            psum = x;
        }
        return (int)psum;
    }
};