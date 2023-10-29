class Solution {
public:
    int trap(vector<int>& height) {
        int anchor = 0;
        int area = 0;
        
        int* f = &height.front();
        int* b;
        int* last = &height.back();
        
        bool left = true;
        
        while(1) {
            
            // set left/right side bound
            anchor = *f;
            
            if(left) {
                // find right bound
                b = f + 1;
                while(b <= last && *b < anchor) b++;
                
                // bound not found, start right to left search of remaining
                if(b > last) {
                    left = false;
                    int* temp = last;
                    last = f;
                    f = temp;
                    continue;
                }
                
                // water height of bounded area
                int max = (anchor < *b)?anchor:*b;
                // add up water
                while(f < b) {
                    area += max - *f++;
                }
                
                // update new start location
                f = b;
            } else {
                // right to left search
                
                // find left bound
                b = f - 1;
                while(b >= last && *b < anchor) b--;
                
                // no bound found, search complete
                if(b < last) return area;               // only returns from here
                int max = (anchor < *b)?anchor:*b;
                
                // add up water
                while(f > b) {
                    area += max - *f--;
                }
                
                // update new start location
                f = b;
            }
        }
    }
};