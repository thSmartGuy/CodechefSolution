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
std::vector <int> blocks ;

bool solve(int mid, int k){
    int cost = 0 ;
    FOR(i, 0, blocks.size()){
        cost += blocks[i]/(mid + 1) ;
    }

    return cost <= k ;
}

int main(){
    // fast() ;

    int t ;
    std::string arr ;

    std::cin >> t ;

    int n, k ;
    while(t--){
        blocks.clear() ;
        std::cin >> n >> k ;

        std::cin >> arr ;
        // CHECK FOR SIZE OF BLOCK 1

        int c1 = 0, c2 = 0 ;
        FOR(i, 0, n){
            if(i%2 == 0){ // even
                if(arr[i] == '0') c1++ ;
                else c2++ ;
            }
            else{
                if(arr[i] == '0') c2++ ;
                else c1++ ;
            }
        }

        if (c1 <= k || c2 <= k) {
            std::cout << "1\n" ;
            continue;
        }

        // CHECK FOR MAX SIZE BLOCK >= 2
        int lagataar = 1 ;
        FOR(i, 1, n){
            if(arr[i] != arr[i - 1]){
                blocks.push_back(lagataar) ;
                lagataar = 1 ;
            }
            else lagataar++ ;
        }
        blocks.push_back(lagataar) ;

        int ans = n/(k + 1) ;

        int low = 2, high = n ;
        while(low <= high){
            int mid = (low + high) >> 1 ;
            if(solve(mid, k)){
                ans = mid ;
                high = mid ;
                if(low == high) break ;
            }
            else{
                low = mid + 1 ;
            }
        }

        print(ans) ;
    }
}
