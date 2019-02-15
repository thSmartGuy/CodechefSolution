#include <iostream>
#include <cmath>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE

struct a{
    long double area ;
    int index ;
};

bool comp(a p, a q){
    if(p.area == q.area) return p.index < q.index ;
    return p.area < q.area ;
}

int main(){
    fast() ;

    int n ;

    std::cin >> n ;

    a arr[n + 1] ;

    long double ax, ay, bx, by, cx, cy ;
    FOR(i, 1, n + 1){
        std::cin >> ax >> ay >> bx >> by >> cx >> cy ;

        long double are = std::abs((long double)(ax*by - ax*cy + bx*cy - bx*ay + cx*ay - cx*by)) ; // since we are only relative area so we can drop 1/2

        arr[i].area = are ;
        arr[i].index = i ;
    }

    std::sort(arr + 1, arr + n + 1, comp) ;

    int j = 1 ;
    while(arr[j + 1].area == arr[j].area){
        j++ ;
    }
    std::cout << arr[j].index << " " << arr[n].index ;
}

