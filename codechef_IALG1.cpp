#include <iostream>
#include <cstring>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE
int arr[105] ;

int main(){
    fast() ;

    int t ;

    std::cin >> t ;

    int a, b ;
    while(t--){
        std::cin >> a >> b ;

        memset(arr, 0, sizeof(arr)) ;

        int quo = a/b ;
        int cur = a%b ;
        FOR(i, 1, 102){
            cur *= 10 ;
            arr[i] = cur/b ;
            cur %= b ;
        }

        if(arr[101] >= 5) arr[100]++ ;

        for(int i = 101 ; i >= 1 ; i--){
            if(arr[i] >= 10){
                arr[i - 1]++ ;
                arr[i] %= 10 ;
            }
        }

        if(arr[0] > 0) quo++ ;

        std::cout << quo ;

        for(int j = 100 ; j >= 1 ; j--){
            if(arr[j] != 0){
                std::cout << "." ;
                FOR(i, 1, j + 1){
                    std::cout << arr[i] ;
                }
            }
        }
        std::cout << "\n" ;
    }
}

