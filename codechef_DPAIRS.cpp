#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 2*111111 ;

// CODE FROM HERE

std::vector<std::pair <int, int>> arr, brr ;
std::set <std::pair <int, int>> ans ;
std::set <int> check ;

int main(){
    fast() ;

    int n, m ;

    std::cin >> n >> m ;
    arr.resize(n) ; brr.resize(m) ;

    FOR(i, 0, n){
        std::cin >> arr[i].first ;
        arr[i].second = i ;
    }

    FOR(i, 0, m){
        std::cin >> brr[i].first ;
        brr[i].second = i ;
    }

    std::sort(arr.begin(), arr.end()) ; std::sort(brr.begin(), brr.end()) ;

    for(int j = 0 ; j < m ; j++){
        if(check.find(arr[0].first + brr[j].first) == check.end()){
                check.insert(arr[0].first + brr[j].first) ;
                ans.insert({arr[0].second, brr[j].second}) ;

                if(ans.size() == n + m - 1) break ;
        }
    }


    for(int i = n - 1 ; i >= 1 ; i--){
        for(int j = 0 ; j < m ; j++){
            if(check.find(arr[i].first + brr[j].first) == check.end()){
                check.insert(arr[i].first + brr[j].first) ;
                ans.insert({arr[i].second, brr[j].second}) ;

                if(ans.size() == n + m - 1) break ;
            }
        }
        if(ans.size() == n + m - 1) break ;
    }

    for(auto itr : ans){
        std::cout << itr.first << " " << itr.second << "\n" ;
    }
}

