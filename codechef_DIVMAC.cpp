#include <cstdio>
#include <vector>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 111111

typedef long long int lld  ;

std::vector <int> a, leastPrimeDivisorArr(1e6 + 1) ;
std::vector <bool> primes(1e6 + 1, true) ;

// HAVE TO USE LAZY PROPOGATION FOR FULL AC

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
}

int leastPrimeDivisor(int a){
    return leastPrimeDivisorArr[a] ;
}

class SegmentTree{
private:
    std::vector <int> st ;
    int n;

    void build(int current, int l, int r){
        if(l == r){
            st[current] = leastPrimeDivisor(a[l]) ; // for assigning actual array element to the bottom of seg tree
            return ;
        }

        build(2*current + 1, l, l + (r - l)/2) ;
        build(2*current + 2, l + (r - l)/2 + 1, r) ;

        st[current] = std::max(st[2*current + 1], st[2*current + 2]) ;
        return ;
    }

    int query(int current, int l, int r, int queryl, int queryr){
        if(st[current] == 1){
            return 1 ;
        }

        if(queryl > r || queryr < l){
            return 1 ;
        }

        if(l >= queryl && r <= queryr){
            return st[current] ;
        }

        return std::max(query(2*current + 1, l    , l + (r - l)/2, queryl, queryr),
                        query(2*current + 2, l + (r - l)/2 + 1, r, queryl, queryr)) ;
    }

    int update(int current, int l, int r, int queryl, int queryr){ // update in range [l,r]
        if(l > r || l > queryr || r < queryl) // Current segment is not within range [i, j]
            return 1 ;

        if(st[current] == 1){
            return 1 ;
        }
        if(l == r){ // Leaf current
            int temp = a[l] ;
            if(leastPrimeDivisor(temp) != 0)
                a[l] = temp/leastPrimeDivisor(temp) ;

            if(leastPrimeDivisor(a[l]) == 0){
                st[current] = 1 ;
            }
            else{
                st[current] = leastPrimeDivisor(a[l]) ;
            }
            //	st[current] = pm[l].retlpd();
            return st[current];
        }

        update(2*current + 1, l, (l + r)/2, queryl, queryr) ; // Updating left child
        update(2*current + 2, 1 + (l + r)/2, r, queryl, queryr) ; // Updating right child

        st[current] = std::max(st[2*current + 1], st[2*current + 2]);// Updating root with max value
        return st[current] ;
//
//        if(st[current] == 1){
//            return st[current] ;
//        }
//
//        int queryl = idx, queryr = idx ;
//
//        if(queryl > r || queryr < l){ // OUTSIDE OR ALL ELEM IN RANGE ARE 1
//            return st[current] ;
//        }
//
//        if(queryl == l && queryr == r){ // CURRENT RANGE IS IN UPDATE RANGE
//            a[l] = a[l]/leastPrimeDivisor(a[l]) ;
//            st[current] = leastPrimeDivisor(a[l]) ;
//            return st[current] ;
//        }
//
//        st[current] = std::max(update(2*current + 1, l, l + (r - l)/2, idx), update(2*current + 2, l + (r - l)/2 + 1, r, idx)) ;
//        return st[current] ;
}

public:
    SegmentTree(){
        n = a.size() ;
        st.assign(4*n, 0) ;
        build(0, 0, n - 1) ;
    }

    void print(){
        FOR(i, 0, 4*n){
            printf("%d ", st[i]) ;
        }
        printf("\n") ;
    }

    int query(int l, int r){
        if(st[0] == 1){
            return 1 ;
        }
        return query(0, 0, n - 1, l, r) ;
    }

    int update(int l, int r){
        update(0, 0, n - 1, l, r) ;
    }

    void del(){
        st.clear() ;
    }
};


int main(){
    int t, n, m, l, r, type ;

    scanf("%d", &t) ;

    sieve() ;
    while(t--){
        scanf("%d%d", &n, &m) ;
        a.clear() ; a.resize(n) ;

        FOR(i, 0, n){
            scanf("%d", &a[i]) ;
        }

        SegmentTree s ;

        FOR(i, 0, m){
            scanf("%d%d%d", &type, &l, &r) ;

            if(type == 0){ // UPDATE
                s.update(l - 1, r - 1) ;
            }
            else{ // GET
                printf("%d ", s.query(l - 1, r - 1)) ;
            }
        }
        printf("\n") ;
        s.del() ;
    }
}
