#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1e6 + 5 ;

// CODE FROM HERE

int arr[MAX] ;

int main(){
     fast() ;

    int t ;

    std::cin >> t ;

    int n ;
    while(t--){
        std::cin >> n ;
        char c ;
        FOR(i, 1, n + 1){
            std::cin >> c ;
            arr[i] = (c == '0' ? 0 : 1) ;
        }
        arr[0] = 0 ; arr[n + 1] = 0 ; arr[n + 2] = 1 ;

        int count_ = 0 ;
        int ans = 0 ;
        FOR(i, 0, n + 3){
            if(arr[i] == 1){
                ans += (count_ - 1)/2 ;
                count_ = 0 ;
            }

            if(arr[i] == 0){
                count_ ++ ;
            }
        }

        if(ans == 0){
            ans = (count_ + 1)/2 ;
        }

        print(ans) ;
    }
}

