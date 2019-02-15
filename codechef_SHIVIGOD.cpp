#include <iostream>
#include <iomanip>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1111 ;

// CODE FROM HERE

lld arr[MAX] ;

int main(){
     fast() ;

    int t ;

    std::cin >> t ;

    int n, a, b ;
    while(t--){
        std::cin >> n >> b >> a ;

        FOR(i, 0, n) std::cin >> arr[i] ;

//        std::sort(arr, arr + n) ; // NEED CONTINUOUS ELEMENTSs

        lld sum = 0 ;
        int count_ = 0 ;
        long double mx = 0.000000 ;

        FOR(i, 0, n){
            count_ = 0 ;
            sum = 0 ;
            FOR(j, i, n){
                sum += arr[j] ;
                count_++ ;
                if(count_ >= a){
                    if(count_ <= b){
                        mx = std::max(mx, (long double) sum/count_) ;
                    }
                    else break ;
                }
            }
        }

        std::cout << std::fixed << std::setprecision(6) << mx << "\n" ;
    }
}

