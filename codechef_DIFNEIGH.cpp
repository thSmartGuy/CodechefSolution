#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111 ;

// CODE FROM HERE
std::vector <int> universal[MAX], localArr[MAX], localArrInverted[MAX] ;

bool verify(std::vector <int> arr[], int n, int m){
    // FIND SMALLEST WHICH IS NOT IN
    // (i - 2, j) // i - 2 >= 0
    // (i - 1, j - 1), (i - 1, j + 1) // i - 1 >= 0, j - 1 >= 0, j + 1 <= m - 1
    // (i, j - 2)  // j - 2 >= 0
    FOR(i, 0, n){
        FOR(j, 0, m){
            if(i - 2 >= 0){
                if(arr[i - 2][j] == arr[i][j]) return false ;
            }

            if(i - 1 >= 0){
                if(j - 1 >= 0){
                    if(arr[i - 1][j - 1] == arr[i][j]) return false ;
                }

                if(j + 1 <= m - 1){
                    if(arr[i - 1][j + 1] == arr[i][j]) return false ;
                }
            }

            if(j - 2 >= 0){
                if(arr[i][j - 2] == arr[i][j]) return false ;
            }

            if(j + 2 <= m - 1){
                if(arr[i][j + 2] == arr[i][j]) return false ;
            }

            if(i + 1 <= n - 1){
                if(j - 1 >= 0){
                    if(arr[i + 1][j - 1] == arr[i][j]) return false ;
                }

                if(j + 1 <= m - 1){
                    if(arr[i + 1][j + 1] == arr[i][j]) return false ;
                }
            }

            if(i + 2 <= n - 1){
                if(arr[i + 2][j] == arr[i][j]) return false ;
            }
        }
    }
    return true ;
}

void defineArr(std::vector <int> arr[], int n, int m){
    FOR(i, 0, n){
        arr[i].assign(m, 0) ;
    }
}

void printArr(std::vector <int> arr[], int n, int m){
    FOR(i, 0, n){
        FOR(j, 0, m){
            std::cout << arr[i][j] << " " ;
        }
        std::cout << "\n" ;
    }
}

void printArrColumnWise(std::vector <int> arr[], int n, int m){
    FOR(i, 0, n){
        FOR(j, 0, m){
            std::cout << arr[j][i] << " " ;
        }
        std::cout << "\n" ;
    }
}

void fill_(std::vector <int> arr[], int n, int m){
    int suru = 1 ;
    for(int j = 0 ; j < m ; j+=2){ // for inly first row
        arr[0][j] = suru ;
        arr[0][j + 1] = suru ;

        if(suru == 1) suru = 2 ;
        else suru = 1 ;
    }

    FOR(i, 1, n){
        FOR(j, 0, m){
            // FIND SMALLEST WHICH IS NOT IN
            // (i - 2, j) // i - 2 >= 0
            // (i - 1, j - 1), (i - 1, j + 1) // i - 1 >= 0, j - 1 >= 0, j + 1 <= m - 1
            // (i, j - 2)  // j - 2 >= 0

            int small = 1 ;

            while(arr[i][j] == 0){
                if(i - 2 >=  0){
                    if(arr[i - 2][j] == small){
                        small++ ;
                        continue ;
                    }
                }

                if(i - 1 >= 0 && j - 1 >= 0){
                    if(arr[i - 1][j - 1] == small){
                        small++ ;
                        continue ;
                    }
                }

                if(i - 1 >= 0 && j + 1 <= m - 1){
                    if(arr[i - 1][j + 1] == small){
                        small++ ;
                        continue ;
                    }
                }

                if(j - 2 >= 0){
                    if(arr[i][j - 2] == small){
                        small++ ;
                        continue ;
                    }
                }

                arr[i][j] = small ;
            }
        }
    }
}

int find_max(std::vector <int> arr[], int n, int m){
    int max_ = 0 ;
    FOR(i, 0, n){
        FOR(j, 0, m){
            max_ = std::max(max_, arr[i][j]) ;
        }
    }

    return max_ ;
}

int main(){
//    fast() ;
    int t, n, m ;

    defineArr(universal, 50, 50) ;
    fill_(universal, 50, 50) ;

    std::cin >> t ;
    while(t--){
        std::cin >> n >> m ;
        defineArr(localArr, n, m) ;

        if((n == 2 && m > 3) || (n > 3 && m == 2)){
//            print(3) ;
            if(m > 3){
//                print("n == 2") ;
                int count_ = 1 ;
                FOR(i, 0, n){
                    FOR(j, 0, m){
                        localArr[i][j] = count_++ ;
                        if(count_ > 3) count_ = 1 ;
                    }
                    count_ = 1 ; // DUE TO THIS GETTING WA FOR 15 HRS
                }
            }
            else{ // m == 2
//                print("m == 2") ;
                int count_ = 1 ;
                FOR(i, 0, n){
                    localArr[i][0] = count_ ;
                    localArr[i][1] = count_ ;

                    count_++ ;
                    if(count_ > 3) count_ = 1 ;
                }
            }

            print(find_max(localArr, n, m)) ;
            printArr(localArr, n, m) ;
        }
        else{
            fill_(localArr, n, m) ;
            if(find_max(universal, n, m) < find_max(localArr, n, m)){ // check in universal
//                print("in universal") ;
                print(find_max(universal, n, m)) ;
                printArr(universal, n, m) ;
            }
            else{ // check in local
//                print("in local") ;
                print(find_max(localArr, n, m)) ;
                printArr(localArr, n, m) ;
            }
        }
    }
}
