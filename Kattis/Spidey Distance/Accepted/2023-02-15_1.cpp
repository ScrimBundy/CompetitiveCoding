#include <iostream>

#define ll long long

using namespace std;

const int MAX_INPUT = 1000000;

ll centeredSquare(ll n) {
    ll n2 = n * n;
    return 2 * n2 + 2 * n + 1;
}

ll spider(int n) {
    ll cs = centeredSquare(n);
    
    if(n < 2) return cs;
    
    ll t = n/3;
    ll u = (n-2)/3;
    ll v = (n-2)%3;
    
    ll w = 6 * u * (u + 1);
    ll x = 4 * t * v;
    
    return cs + x + w;
}

ll gcd(ll a, ll b) {
    while(b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll divThreeHalves(ll n) {
    ll r = n / 3;
    r *= 2;
    if(n % 3 == 2) r++;
    return r;
}

int main(int argc, char *argv[]) {
    ll t, s;
    cin >> t >> s;
    
    ll n, d;
    
    if(s >= t) {
        ll taxi = centeredSquare(t);
        ll spid = spider(s);
        ll g = gcd(taxi, spid);
        
        taxi /= g;
        spid /= g;
        
        n = taxi;
        d = spid;
    } else {
        ll total = 0LL;
        
        ll tDist = t;
        ll sDist = s;
        
        ll tDiag = tDist >> 1;
        ll diff = (divThreeHalves(sDist) - tDiag) * 4;
        sDist--; tDist--;
        while(diff >= 0 && sDist >= 0 && tDist >= 0) {
            total += diff;
            tDiag = tDist >> 1;
            diff = (divThreeHalves(sDist) - tDiag) * 8;
            sDist--; tDist--;
        }
        
        d = spider(s);
        n = d - total;
        ll g = gcd(n, d);
        n /= g;
        d /= g;
    }
    
    if(d == 1) {
        cout << 1 << endl;
    } else {
        cout << n << "/" << d << endl;
    }
    return 0;
}