class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int* f = &height[0];        // pointer to front of height
        int* b = &height.back();    // pointer to back  of height
        while(f != b) {
            int area = (b-f);       // distance between pointers
            if(*f>*b) {             // mult by shorter num
                area *= *b;
                b--;                // b shorter, move in
            } else {
                area *= *f;
                f++;                // f shorter, move in
            }
            if(area > max) max = area;
        }
        return max;
    }
};