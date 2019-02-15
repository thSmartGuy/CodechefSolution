#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1e6 + 5 ;

// CODE FROM HERE

struct a{
    int dis ;
    int idx ;
};

a arr[MAX], brr[MAX] ;
int res[MAX] ;

bool comp(a p, a q){
    return p.dis < q.dis ;
}

int main(){
    // fast() ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        FOR(i, 0, n){
            std::cin >> arr[i].dis ;
            arr[i].idx = i ;
        }

        FOR(i, 0, n){
            std::cin >> brr[i].dis ;
            brr[i].idx = i ;
        }

        if(arr[0].dis != 0 || brr[n].dis != 0){
            print("No") ;
            continue ;
        }

        std::sort(arr, arr + n, comp) ; std::sort(brr, brr + n, comp) ;

        int nthidx = n - 1 ;

        FOR(i, 0, n){
            if(arr[i].idx == n - 1){
                nthidx = i ;
                break ;
            }
        }

        FOR(i, 0, n){
            res[arr[i].idx] = std::abs(arr[nthidx].dis - arr[i].dis) ;
        }

        FOR(i, 0, n){
            std::cout << res[i] << " " ;
        }

        std::cout << "\n" ;
    }
}

