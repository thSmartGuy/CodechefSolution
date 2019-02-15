#include <iostream>
#define rep(i, k, n) for(int i = k ; i < n ; i++)

int main(){
    int n, q, l, r, temp, zero, one ;
    std::cin >> n >> q ;
    int a[n] ;
    int binary[n][31], prebinary[n][31] ;
    rep(i, 0, n){
        std::cin >> a[i] ;
    }

    rep(i, 0, n){
        temp = a[i] ;
        rep(j, 0, 31){
            binary[i][j] = temp%2 ;
            prebinary[i][j] = binary[i][j] ;
            temp /= 2 ;
            if(i!=0){
                prebinary[i][j] += prebinary[i-1][j] ;
            }
        }
    }

    while(q-->0){
        int ans[31], qans = 0, mul = 1 ;
        std::cin >> l >> r ;
        rep(j, 0, 31){
            if(binary[l-1][j]){
                one = prebinary[r-1][j] - prebinary[l-1][j] + 1 ;
            }
            else{
                one = prebinary[r-1][j] - prebinary[l-1][j] ;
            }

            zero = r - l + 1 - one ;
            if(zero > one){
                ans[j] = 1 ;
            }
            else{
                ans[j] = 0 ;
            }
        }

        rep(i, 0, 31){
            qans += mul*ans[i] ;
            mul *= 2 ;
        }

        std::cout << qans << "\n" ;
    }
}
