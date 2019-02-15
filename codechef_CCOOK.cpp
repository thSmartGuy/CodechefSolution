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

void solve(int n){
    if(n == 0){
        print("Beginner") ;
    }

    if(n == 1){
        print("Junior Developer") ;
    }

    if(n == 2){
        print("Middle Developer") ;
    }

    if(n == 3){
        print("Senior Developer") ;
    }

    if(n == 4){
        print("Hacker") ;
    }

    if(n == 5){
        print("Jeff Dean") ;
    }
}

int main(){
     fast() ;

    int n, tmp ;

    std::cin >> n ;

    FOR(i, 0, n){
        int sum = 0 ;
        FOR(j, 0, 5){
            std::cin >> tmp ;
            sum += tmp ;
        }
        solve(sum) ;
    }
}

