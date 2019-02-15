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
int arr[MAX] ;

int main(){
     fast() ;

    int n, k ;

    std::cin >> n >> k ;

    FOR(i, 0, n) std::cin >> arr[i] ;

    std::sort(arr, arr + n) ;

    lld ans = 0 ;
    int mid ;
    bool flag ;
    FOR(i, 0, n){
        int low = i + 1, high = n - 1 ;

        flag = 0 ;
        while(low <= high){
            mid = (low + high) >> 1 ;

            if(arr[mid] - arr[i] >= k){
                high = mid ;
                flag = 1 ;
                if(low == high) break ;
            }
            else{
                low = mid + 1 ;
            }
        }

        mid = mid = (low + high) >> 1 ;
        if(flag) ans += (n - mid) ;
    }

    print(ans) ;
}

