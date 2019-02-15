#include <iostream>
#include <iomanip>
#include <cmath>
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

    int t ;

    std::cin >> t ;

    long double ar, h ;
    while(t--){
        std::cin >> h >> ar ;

        long double b = std::sqrt(h*h/2) ;
        if(b*b/2 < ar || ar < 1){
            print(-1) ;
        }
        else{
            long double mid, ht ;
            long double low = 0.00, high = b + 1.000 ;
            while(low <= high){
                mid = (low + high)*0.5 ;

                ht = std::sqrt(h*h - mid*mid) ;

                long double area = ht*mid*0.5 ;

                if(area < ar){
                    low = mid + 0.000000000001 ;
                }
                else if (area >= ar){
                    high = mid - 0.000000000001 ;
                }
            }

            long double ans[] = {mid, ht, h} ;

            std::sort(ans, ans + 3) ;

            FOR(i, 0, 3) std::cout << std::fixed << std::setprecision(6) << ans[i] << " " ;
            std::cout << "\n" ;
        }
    }
}

