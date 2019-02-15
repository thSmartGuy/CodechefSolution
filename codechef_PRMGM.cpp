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

bool p[MAX] = {} ;
int arr[MAX] ;

void sieve(){
    FOR(i, 2, MAX)
        if(p[i])
            for(int j = 2*i ; j < MAX ; j += i) p[i] = 0 ;
}

int main(){
    // fast() ;

    int t, n ;

    sieve() ;
    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        FOR(i, 0, n) std::cin >> arr[i] ;

        int both = 0, a = 0, b = 0 ;

        FOR(i, 0, n){
            if(p[arr[i]]) both++ ;
            else if(arr[i]%2 == 0) b++ ;
            else a++ ;
        }

        if(a == 0 && b == 0){
            if(both) print("Alice") ;
            else print("Bob") ;
        }
        else{
            if(a > b) print("Alice") ;
            else if(b > a) print("Bob") ;
            else print("Alice") ;
        }
    }
}

