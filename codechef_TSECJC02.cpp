#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 700000 ;

// CODE FROM HERE

std::vector <bool> p(MAX, 1) ;

void sieve(){
    FOR(i, 2, MAX){
        if(p[i]){
            for(int j = 2*i ; j < MAX ; j += i) p[j] = 0 ;
        }
    }
}

lld ans = 0 ;

void fib(int a, int b, int count_){
    if(count_ == 21) return ;
    int c = a + b ;
    count_++ ;
    if(p[c]) ans++ ;
    fib(b, c, count_) ;
}

int main(){
     fast() ;

    int t ;

    std::cin >> t ;

    sieve() ;
    while(t--){
        int a, b ;
        ans = 0  ;
        std::cin >> a >> b ;
        if(p[a]) ans++ ; if(p[b]) ans++ ;

        fib(a, b, 3) ;

        print(ans) ;
    }
}
