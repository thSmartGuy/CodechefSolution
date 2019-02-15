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
int open[MAX] = {} ;

int main(){
    fast() ;
    int n ;

    std::cin >> n ;

    FOR(i, 1, n + 1) std::cin >> arr[i] ;

    FOR(i, 1, n + 1){
        if(arr[i] == 1){
            open[i] = open[i - 1] + 1 ;
        }
        else{
            open[i] = open[i - 1] - 1 ;
        }
    }

    //FOR(i, 1, n + 1) std::cout << open[i] << " " ; std::cout << "\n" ;

    int max_depth = 0 ;

    int lastZero = 0 ;
    int localMax = 0 ;
    int maxDepthIdx = 1 ;
    int maxInside = 1 ;
    int maxIndex = 1 ;

    FOR(i, 1, n + 1){
        localMax = std::max(localMax, open[i]) ;

        if(localMax > max_depth){
            max_depth = localMax ;
            maxDepthIdx = i ;
        }


        if(open[i] == 0){
            if(i - lastZero > maxInside){
                maxInside = i - lastZero ;
                maxIndex = lastZero + 1 ;
            }

            lastZero = i ;
            localMax = 0 ;
        }
    }

    std::cout << max_depth << " " << maxDepthIdx << " " << maxInside << " " << maxIndex << "\n" ;
}

