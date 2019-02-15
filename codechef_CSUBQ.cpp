#include <iostream>
#include <vector>

const int max_ = 5*1e5*2 ;

std::vector <node> stA(max_), stB(max_) ;

updateST(std::vector <int> st, int index, int element, int start_, int end_, int current_){
    if(start_ == end_){
        st[current_] = element ;
        return element ;
    }

    int mid = start + (end_ - start_)/2 ;
    st[current_] += updateST(st, index, element, start_, mid, 2*current_ + 1) + updateST(st, index, element, mid + 1, end_, 2*current_ + 1) ;
}


void update(std::vector <int> st, int x, int y, int n){
    updateST(st, x, y, 0, n - 1, 0) ;
}

int main(){
    std::ios_base::sync_with_stdio(false) ;
    std::cin.tie(NULL) ;
    std::cout.tie(NULL) ;

    int n, q, l, r, query, x, y ;
    std::cin >> n >> q >> l >> r ;

    l-- ; r-- ;

    while(q--){
        std::cin >> query >> x >> y ;
        x-- ;
        if(query == 1){
            if(y <= r)
                update(stB, x, 1, n) ;
            else
                update(stB, x, 0, n) ;

            if(y <= l)
                update(stA, x, 1, n) ;
            else
                update(stA, x, 0, n)
        }
        else{ // query == 2 ;

        }
    }
}
