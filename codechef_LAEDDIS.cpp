#include <iostream>
#include <set>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE
int arr[MAX] ;
int dp[MAX] ;

int main(){
     fast() ;

    // STANDARD LIS PROB
    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        FOR(i, 0, n) std::cin >> arr[i] ;

        std::set <int> lis ;
        FOR(i, 0, n){
            if (lis.insert(arr[i]).second){
                auto k = lis.find(arr[i]);

                k++;
                if (k!=lis.end()) lis.erase(k);
            }
        }

        int ans = lis.size();
        print(ans) ;
    }
}

