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

std::vector <int> arr ;
class SegmentTree{
private:
    std::vector <int> st, a ;
    int n;

    void build(int current, int l, int r){
        if(l == r){
            //std::cout << "currently at index:: " << l << " == assigning to :" << current << "\n" ;
            st[current] = a[l] ; // for assigning actual array element to the bottom of seg tree
            return ;
        }

        build(2*current + 1, l, l + (r - l)/2) ;
        build(2*current + 2, l + (r - l)/2 + 1, r) ;

        //st[current] = std::max(leastPrimeDivisor(st[left]), leastPrimeDivisor(st[right])) ; // operation required
        //std::cout << "currently at seg tree index " << current << "\n" ;
        st[current] = std::max(st[2*current + 1], st[2*current + 2]) ;
        return ;
    }

    int query(int current, int l, int r, int queryl, int queryr){
        if(queryl > r || queryr < l){
            return -1 ;
        }

        if(queryl <= l && r >= queryr){
            return st[current] ;
        }

        return std::max(query(current*2 + 2, l + (r - l)/2 + 1, r, queryl, queryr), query(current*2  + 1, l, l + (r - l)/2, queryl, queryr)) ;
    }

    int update(int current, int l, int r, int idx, int new_val){
        int queryl = idx, queryr = idx ;

        if(queryl > r || queryr < l){ // OUTSIDE
            return st[current] ;
        }

        if(queryl == l && queryr == r){ // CURRENT RANGE IS IN UPDATE RANGE
            arr[l] += new_val ;
            st[current] = arr[l] ;
            return st[current] ;
        }

        st[current] = std::max(update(2*current + 1, l, l + (r - l)/2, idx, new_val), update(2*current + 2, l + (r - l)/2 + 1, r, idx, new_val)) ;
        return st[current] ;
    }

public:
    SegmentTree(std::vector <int> v){
        a = v ;
        n = v.size() ;
        st.assign(4*n, 0) ;
        build(0, 0, n - 1) ;
    }

    void print(){
        FOR(i, 0, 4*n){
            std::cout << st[i] << " " ;
        }
        std::cout << "\n" ;
    }

    int query(int l, int r){
        return query(0, 0, n - 1, l, r) ;
    }

    int update(int l, int r, int val){
        FOR(i, l, r + 1)
            update(0, 0, n - 1, i, val) ;
    }
};

int main(){
    fast() ;

    int n, m, x, y ;

    std::cin >> n ;
    arr.resize(n) ;

    FOR(i, 0, n) std::cin >> arr[i] ;

    SegmentTree *s = new SegmentTree(arr) ;

    std::cin >> m >> x >> y ;
    m-- ;

    int l = std::min(x, y) ; int r = std::max(x, y) ;
    lld sum = s->query(l, r) ;
    print(sum) ;

    while(m--){
        x = (x + 7)%(n - 1) ; y = (y + 11)%n ;

        l = std::min(x, y) ; r = std::max(x, y) ;
        sum += s->query(l, r) ;
        print(sum) ;
    }

    print(sum) ; //CHECKING FOR PA
}

