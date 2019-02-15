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

lld arr[MAX] ;

lld profit(lld z, int n, int x, int y){
    lld sum = 0 ;

    FOR(i, 0, n){
        if(arr[i] < z){
            sum += (z - arr[i])*y ;
        }

        if(arr[i] > z){
            sum -= (arr[i] - z)*x ;
        }
    }

    return sum ;
}

int main(){
    fast() ;

    int t, n, x, y ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> x >> y ;

        lld low = 1e10 + 1, high = 1 ;
        FOR(i, 0, n){
            std::cin >> arr[i] ;
            if(arr[i] < low){
                low = arr[i] ;
            }

            if(arr[i] > high){
                high = arr[i] ;
            }
        }

        lld z = high, p ;

        while(low <= high){
            lld mid = (low + high) >> 1 ;

            p = profit(mid, n, x, y) ;

//            std::cout << "at mid: " << mid << " p = " << p << "\n" ;
            if(p >= 0){
                if(p < z)
                    z = p ;
                high = mid ;
                if(low == high) break ;
            }
            else{
                low = mid + 1 ;
                if(low == high) break ;
            }
        }

        print(z) ;
    }
}

