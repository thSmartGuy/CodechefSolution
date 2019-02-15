#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 2*111111 ;

// CODE FROM HERE

int arr[MAX] ;

int main(){
    //fast() ;

    int t, n, a, b ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> a >> b ;

        FOR(i, 0, n) std::cin >> arr[i]  ;

        int bob = 0, alice = 0, BothCount = 0 ;

        FOR(i, 0, n){
            if(arr[i] == 0) continue ;

            if(arr[i]%a == 0 && arr[i]%b == 0){
                BothCount++ ;
            }
            else{
                if(arr[i] % a == 0){
                    bob++ ;
                }

                if(arr[i] % b == 0){
                    alice++ ;
                }
            }
        }

        std::string ans = "ALICE" ;

        // NOW CURRENT TURN IS OF bob
        if(bob == 0 && alice == 0){ // if both are zero
            ans = "BOB" ;
        }
        else{
            if(bob > alice) ans = "BOB" ;
            else if(bob == alice && BothCount != 0) ans = "BOB" ;
        }

        print(ans) ;
    }
}

