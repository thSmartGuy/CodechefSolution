#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

int main(){
    fast() ;

    int t ;

    std::cin >> t ;

    int n, p ;
    while(t--){
        std::cin >> n >> p ;

        lld ans_ = 0 ;
        int max_score = -1 ;

        if(n <= p){  //  largestRemainder = c % ((c/2) + 1)
            max_score = (n%(n/2 + 1))%n ;
        }
        else{
            max_score = (n%(p/2 + 1))%n ;
        }

        int size_ ;
        if(p >= n){
            if(max_score == 0){
                size_ = p ;
            }
            else{
                size_ = 1 ;
            }
        }
        else{
            size_ = 1 ;
        }

        if(p >= max_score){
            ans_ += 1ll*(p - max_score)*(p - max_score)*size_ ;
        }
        if(p - n >= 0 && max_score != 0){
            if(p >= max_score){
                ans_ += 1ll*(p - n)*size_*(p - max_score) ;
            }
        }
        if(p - n >= 0 && max_score != 0){
            ans_ += 1ll*(p - n)*(p - n)*size_ ;
        }

        std::cout << ans_ << "\n" ;
    }
}

