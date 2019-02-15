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
int main(){
    fast() ;

    int t ;

    std::cin >> t ;

    lld l, r ;
    while(t--){
        std::cin >> l >> r ;

        if(l == r){
            if((l & 1) == 1){
                print("Odd") ;
            }
            else print("Even") ;
            continue ;
        }

        if(r - l == 1){
            print("Odd") ;
            continue ;
        }

        lld firstOdd = l, lastOdd = r ;

        if(!(firstOdd & 1)) firstOdd++ ;
        if(!(lastOdd & 1)) lastOdd-- ;

        lld odd = (lastOdd - firstOdd)/2 ;

        if(!(odd & 1)) print("Odd") ;
        else print("Even") ;
    }
}

