#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111 ;

// CODE FROM HERE
int arr[MAX], brr[MAX] ;

int main(){
     fast() ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        FOR(i, 0, n) std::cin >> arr[i] ;
        FOR(i, 0, n) std::cin >> brr[i] ;

        lld a_sum = 0, b_sum = 0 ;

        std::sort(arr, arr + n) ; std::sort(brr, brr + n) ;

        FOR(i, 0, n){
            a_sum += arr[i] ;
            b_sum += brr[i] ;
        }

        {
            a_sum -= arr[n - 1] ;
            b_sum -= brr[n - 1] ;
        }

        if(a_sum == b_sum){
            print("Draw") ;
        }
        else{
            print(a_sum < b_sum ? "Alice" : "Bob") ;
        }
    }
}

