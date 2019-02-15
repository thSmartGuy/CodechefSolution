#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 111111

typedef long long int lld  ;

int arr[MAX] ;
int lastBitofMAX1s, lastOne ;

int shiftResult(int d, int n){
    int cur = n - d ;
    cur = cur%n ;

    int max_1Size = 0, temp1Size = 0 ;
    for(int j = 0 ; j < n ; j++){
        if(arr[cur] == 0){
            if(max_1Size < temp1Size){
                max_1Size = temp1Size ;
                lastBitofMAX1s = cur - 1 ;
            }
            temp1Size = 0 ;
        }
        else if(arr[cur] == 1){
            temp1Size++ ;
            if(max_1Size < temp1Size){
                max_1Size = temp1Size ;
                lastBitofMAX1s = cur ;
            }
        }
        cur++ ;
        cur = cur%n ;
    }

//    std::cout << "shifting by " << d << " ::: max:: " << max_1Size << " :: lastBitofMAX1s :: " << lastBitofMAX1s << "\n" ;

    return max_1Size ;
}

void calLastOne(int n){
    int i = n - 1 ;

    lastOne = n ;
    while(i >= 0 && arr[i]){
        lastOne = i ;
        i-- ;
    }
}

int ans[MAX] ;

void pre(int n){
    ans[0] = shiftResult(0, n) ;
    int cur ;


    calLastOne(n) ;
    FOR(i, 1, n){
        cur = n - i ;
        if(cur <= lastBitofMAX1s){ // || cur >= lastOne
            ans[i] = shiftResult(i, n) ;
        }
        else if(cur >= lastOne){
            int temp = 0 ;
            while(arr[cur] && temp <= n){
                temp++ ;
                cur++;
                cur %= n ;
            }
            ans[i] = std::max(ans[i - 1], temp) ;
        }
        else{
            ans[i] = std::max(ans[i - 1], arr[0]) ;
            //ans[i] = std::max(0, -1) ; // JUST CHECKING
        }
    }

//    FOR(i, 0, n)
//        std::cout << ans[i] << " " ;
//    std::cout << "\n" ;
//    for(int i = 1 ; < n ; i++){
//
//    }
}

int main(){
    //fast ;

    std::string str ;
    int n, q, k ;


    std::cin >> n  >> q >> k ;

    for(int i = 0 ; i < n ; i++){
        std::cin >> arr[i] ;
    }

    pre(n) ;

    std::cin >> str ;

    int shift = 0 ;
    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] == '!'){
            shift++ ;
        }
        else{
            if(ans[shift%n] > k){
                std::cout << k << "\n" ;
            }
            else{
                std::cout << ans[shift%n] << "\n" ;
            }
        }
    }
}
