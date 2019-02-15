#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 111111

typedef long long int lld  ;

std::vector <int> st, leastPrimeDivisorArr(1e6 + 1) ;
std::vector <bool> primes(1e6 + 1, true) ;
int arr[MAX] ;

void sieve(){
    leastPrimeDivisorArr[1] = 1 ;
    for(int i = 2 ; i < 1e6 + 1 ; i += 2){
        leastPrimeDivisorArr[i] = 2 ; // all even numbers have least prime factor 2 ;
    }

    for(int i = 3 ; i < 1e6 + 1 ; i += 2){
        if(primes[i]){
            leastPrimeDivisorArr[i] = i ; // i itself is prime so least prime divisor i
            for(int j = i ; 1ll*j*i < 1e6 + 1 ; j += 2){
                if(primes[j*i]){
                    leastPrimeDivisorArr[(j*i)] = i ;
                    primes[j*i] = false ;
                }
            }
        }
    }

//    FOR(i, 1, 100){
//        std::cout << i << " :: " << leastPrimeDivisorArr[i] << "\n" ;
//    }
}

int leastPrimeDivisor(int a){
    return leastPrimeDivisorArr[a] ;
}

void build(int n){
    for(int i = n - 1 ; i > 0 ; i--){
        st[i] = std::max(st[i << 1], st[i << 1 | 1]) ; // i << 1 == i*2, i << 1 | 1 == 2*i + 1
    }
}

void modify(int idx, int n){
//    std::cout << "st[idx + n] : " << st[idx + n] << "\n" ;
//    std::cout << "leastPrimeDivisor : " << leastPrimeDivisor(st[idx + n]) << "\n" ;
    arr[idx] /= leastPrimeDivisor(arr[idx]) ;
    st[idx + n] = leastPrimeDivisor(arr[idx]) ;
    for(idx += n ; idx > 1 ; idx >>= 1){
        st[idx >> 1] = std::max(st[idx], st[idx ^ 1]) ;
    }

////    std::cout << "ARR::\n" ;
//    FOR(i, 0, n){
//        std::cout << arr[i] << " " ;
//    }
//    std::cout << "\n" ;
}

int query(int current, int l, int r, int queryl, int queryr){ // [l, r]
        if(st[current] == 1){
            return 1 ;
        }

        if(queryl > r || queryr < l){
            return 1 ;
        }

        if(l >= queryl && r <= queryr){
            return st[current] ;
        }

        return std::max(query(2*current, l    , l + (r - l)/2, queryl, queryr),
                        query(2*current + 1, l + (r - l)/2 + 1, r, queryl, queryr)) ;
    }

int query(int l, int r, int n){  // query on [l, r) // R not INCLUDED
    int max_ = 1 ;
    l += n ; r += n ;
    for(l, r ; l < r ; l /= 2, r /= 2){
        if(l & 1){ // l is right child 2*l + ((1))
            max_ = std::max(max_, st[l]) ;
            l++ ;
        }
        if(r & 1){
            r-- ;
            max_ = std::max(max_, st[r]) ;
        }
        if(max_ = 1)
            return 1 ;
    }
    return max_ ;
}

int main(){
    fast ;

    int t, n, m, l, r, type ;

    std::cin >> t ;

    sieve() ;
    while(t--){
        std::cin >> n >> m ;

        st.clear() ;
        st.resize(2*n) ;

        int temp ;
        FOR(i, 0, n){
            std::cin >> arr[i] ; // temp ;
             st[n + i] = leastPrimeDivisor(arr[i]) ; // Taking ip directly into seg tree
        }

        build(n) ;
//        FOR(i, 0, 2*n)
//            std::cout << st[i] << " " ;
//        std::cout << "\n" ;

        FOR(i, 0, m){
            std::cin >> type >> l >> r ;

            if(type == 0){ // UPDATE
                FOR(i, l - 1, r){
                    if(st[i + n] != 1){
                        modify(i, n) ;
//                        std::cout << "modifying fr " << st[i + n] << "\n";
                    }
                }
//                FOR(i, 0, 2*n)
//                    std::cout << st[i] << " " ;
//                std::cout << "\n" ;
            }
            else{ // GET
                std::cout << query(1, 1, n - 1, l - 1, r - 1) << " " ;
            }
        }
        std::cout << "\n" ;
//        delete(s) ;
    }
}
/*
0  1  2 3 4  5 //6 7 8 9 10 11
0  5  3 5 2  3 //2 5 2 2  3  2
0  3  3 2 2  3 //2 1 2 2  3  2
0  5  5 2 5  2 //2 1 2 5  1  2
0 11 11 1 2 11 //1 1 2 1  1 11 */
