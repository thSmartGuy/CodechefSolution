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

int hard[MAX] ;

int main(){
     fast() ;
    int n, k ;

    std::cin >> n >> k ;

    FOR(i, 1, n + 1) std::cin >> hard[i] ;

    std::sort(hard + 1, hard + n + 1) ;

    lld ans = 0 ;
    FOR(i, 1, n + 1){
        int low = i + 1, high = n ;
        int mid ; bool flag = 0 ;

        while(low <= high){
            mid = ((low + high) >> 1) ;

            if(hard[i] + hard[mid] < k){
                flag = 1 ;
                low = mid + 1 ;
            }
            else{
                high = mid ;
                if(high == low) break ;
            }
        }

        mid = ((low + high) >> 1) ;

        if(flag) ans += mid - i - 1 ;
    }

    print(ans) ;
}

