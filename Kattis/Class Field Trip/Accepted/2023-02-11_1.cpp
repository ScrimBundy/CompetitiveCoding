#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string a, b;
    cin >> a >> b;
    
    int aSz = a.length();
    int bSz = b.length();
    int rSz = aSz + bSz;
    string r;
    int idxa = 0;
    int idxb = 0;
    
    for(int i = 0; i < rSz; i++) {
        if(idxa == aSz) {
            r += b[idxb++];
        } else if(idxb == bSz) {
            r += a[idxa++];
        } else {
            if(a[idxa] > b[idxb]) {
                r += b[idxb++];
            } else {
                r += a[idxa++];
            }
        }
    }
    
    cout << r << endl;
    return 0;
}