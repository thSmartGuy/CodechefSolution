#include <iostream>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int arr[MAX] ;
int ans ;

bool check_for_whatever_we_want(int num[], int k, int n){
    int temp_k = 0 ;
    FOR(i, 1, n){

        if(num[i] > num[i - 1]){
            temp_k++ ;
        }
    }

    if(temp_k == k){
        return true ;
    }

    return false ;
}

void match(int num[], int n, int k){
    bool flag = 1 ;
    FOR(i, 0, n){
        if(arr[i] != num[i] && arr[i] != 0){
            flag = 0 ;
        }
    }

    if(flag){
        if(check_for_whatever_we_want(num, k, n))
            ans++ ;
    }
}

void possiblePerm(int num[], int size_, int n, int k){
    if(size_ == 1){
        match(num, n, k) ;
    }

    FOR(i, 0, size_){
        possiblePerm(num, size_ - 1, n, k) ;

        if(size_%2 == 0){
            std::swap(num[i], num[size_ - 1]) ;
        }
        else{
            std::swap(num[0], num[size_ - 1]) ;
        }
    }
}

int main(){
    fast ;

    int t, n, k ;

    std::cin >> t ;

    while(t--){
        ans = 0 ;
        int num[] = {1,2,3,4,5,6,7,8} ;
        std::cin >> n >> k ;

        FOR(i, 0, n){
            std::cin >> arr[i] ;
        }

        possiblePerm(num, n, n, k) ;

        std::cout << ans << "\n" ;
    }
}
