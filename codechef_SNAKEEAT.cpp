#include <iostream>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE

int snake[MAX] ;

int main(){
    // fast ;

    int t, n, q, k, ans ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> q ;

        FOR(i, 0, n){
            std::cin >> snake[i] ;
        }

        std::sort(snake, snake + n) ;

        while(q--){
            std::cin >> k ;
            int doNotTouch = n - 1 ;

            int low = 0, high = n - 1 ;
            while(low <= high){
                int mid = low + (high - low)/2 ;
//                std::cout << "mid : " << snake[mid] << "\n" ;

                if(snake[mid] > k){
                    high = mid ;
                    if(low == high){
                        break ;
                    }
                }
                else{
                    low = mid + 1 ;
                    if(snake[mid] < k)
                        doNotTouch = mid ;
                }
//                std::cout << "doNotTouch:: " << doNotTouch << "\n" ;
            }

            int i = 0, j = doNotTouch ;

            while(i < j){
                int need = k - snake[j] ;
                if(need > 0){
                    if(i + need < j){
                        i += need ;
                    }
                    else{
                        break ;
                    }
                }
                j-- ;
            }

            std::cout << n - i - 1 << "\n" ;
        }
    }
}

