#include <iostream>

using namespace std;

int op(int a, int b, int idx) {
    if(idx == 0)
        return a - b;
    if(idx == 1)
        return a + b;
    if(idx == 2) {
        return a / b;
    } else {
        return a * b;
    }
}

int main(int argc, char *argv[]) {
    int l, m, n;
    cin >> l >> m >> n;
    
    int smallest = 0x7fffffff;
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == 2 && l % m != 0) continue;
            
            int firstOp = op(l, m, i);
            if(j == 2 && firstOp % n != 0) continue;
            
            int r = op(firstOp, n, j);
            if(r < 0) continue;
            
            smallest = min(smallest, r);
        }
    }
    
    cout << smallest << endl;
    
    return 0;
}