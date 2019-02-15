#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
//     fast() ; INTERACTION PROBLEM NO FAST IO
    int t ;

    std::cin >> t ;

    lld d00, d0e, de0, dee, x1, x2, y1, y2 ;
    lld e = 1e9 ;
    while(t--){
        std::cout << "Q 0 0\n" ;

        std::cin >> d00 ;

        std::cout << "Q 0 " << e << "\n" ;

        std::cin >> d0e ;

        std::cout << "Q " << e << " 0\n" ;

        std::cin >> de0 ;

        std::cout << "Q " << e << " " << e << "\n" ;

        std::cin >> dee ;
        lld m = (e + d00 - de0)/2 ;

        std::cout << "Q " << m << " 0\n" ;

        std::cin >> y1 ;

        x1 = d00 - y1 ;
        x2 = e - de0 + y1 ;

        y2 = 2*e - dee - x2 ;

        std::cout << "A " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n" ;

        int l ;
        std::cin >> l ;

        if(l == -1) print("GALAT HAI\n") ;
    }
}

