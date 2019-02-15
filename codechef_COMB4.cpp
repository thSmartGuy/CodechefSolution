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
    fast() ;
    lld h, w, x, y ;

    std::cin >> h >> w >> x >> y ;

    lld d = gcd(x, y) ;
    x /= d ; y /= d ;

    h /= x ; w /= y ;

    if(h%x == 0 && w%y == 0){
        std::cout << h << " " << w ;
    }
    else{
        if(x > h || y > w) print("0 0") ;
        else{
            if(1ll*x*y > 1ll*h*w) print("0 0") ;
            else{
                lld mul = 1 ;
                lld xans = x, yans = y ;
                lld low = 1, high = 2*1e9 ;

                while(low <= high){
//                    std::cout << low << " " << high << "\n" ;
                    mul = (1ll*(low + high) >> 1) ;
                    x *= mul ; y *= mul ;
                    if(x <= h && y <= w){
                        xans = x ; yans = y ;
                        low = mul + 1;
                    }
                    else{
                        high = mul ;
                        if(low == high) break ;
                    }
                    x /= mul ; y /= mul ;
                }

                std::cout << xans << " " << yans ;
            }
        }
    }
}

