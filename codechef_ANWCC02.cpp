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

int arr[MAX], key[MAX] ;

int main(){
     fast() ;

    int n, m ;

    std::cin >> n >> m ;

    FOR(i, 0, n){
        std::cin >> arr[i] ;
    }

    FOR(i, 0, m) std::cin >> key[i] ;

    lld max_ = 0 ;

    FOR(i, 0, m){
        max_ += 1ll*arr[i]*key[i] ;
    }

    if(m == 1){
        FOR(i, 0, n){
            max_ = std::max(1ll*key[0]*arr[i], max_) ;
        }
        print(max_) ; return 0 ;
    }

    FOR(i, 1, n - m + 1){
        lld temp = 0 ;
        FOR(j, i, i + m){
            temp += 1ll*arr[j]*key[j - i] ;
        }

        max_ = std::max(max_, temp) ;
    }

    print(max_) ;
}

