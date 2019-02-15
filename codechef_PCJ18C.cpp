#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

lld gcd(lld a, lld b){
    if(a == 0){
        return b ;
    }

    return gcd(b%a, a) ;
}

int main(){
    fast ;

    int t, n, a, k ;

    std::cin >> t ;

    lld x, y ;
    while(t--){
        std::cin >> n >> a >> k ;

        x = a * n * (n - 1) + (k - 1) * 2 * ((n - 2) * 180 - a * n) ;
        y = n*(n - 1) ;

        lld divide = gcd(x, y) ;
        x /= divide ;
        y /= divide ;

        std::cout << x << " " << y << "\n" ;

        //int total = 180 * (n - 2);

        //int d_num = 2 * (total - a * n);
        //int d_den = n * (n - 1);
//                  a * n * (n - 1) + (k - 1) * 2 * ((n - 2) * 180 - a * n)
//        int num = a * n * (n - 1) + (k - 1) * 2 * (180 * (n - 2) - a * n) ;
//        int den = n * (n - 1) ;
//        int g = gcd(num, den);
//        num /= g;
//        den /= g;
//
//        std::cout<<num<<" "<<den<<"\n";

    }
}

