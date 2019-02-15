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

    int n, h ;

    std::cin >> n >> h ;

    FOR(i, 0, n) std::cin >> arr[i] ;

    int curPos = 0 ; bool free = true ;

    int comm ;
    std::cin >> comm ;
    while(comm != 0){
        if(comm == 1){ // MOVE LEFT
            if(curPos > 0){
                curPos-- ;
            }
        }

        if(comm == 2){ // MOVE RIGHT
            if(curPos < n - 1){
                curPos++ ;
            }
        }

        if(comm == 3){ // PICKUP
            if(free && arr[curPos] != 0){
                free = 0 ;
                arr[curPos]-- ;
            }
        }

        if(comm == 4){ // DROP
            if(!free && arr[curPos] < h){
                free = 1 ;
                arr[curPos]++ ;
            }
        }

        std::cin >> comm ;
    }

    FOR(i, 0, n) std::cout << arr[i] << " " ;
}

