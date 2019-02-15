#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0 ; i < n ; i++)

void moveup(int ** arr, int n, int m){
    int count_ ;
    rep(i, m) {
		count_ = 0;
		rep(j, n) {
			if(arr[j][i])
                count_++;
			arr[j][i] = 0;
		}

		for(int j = 0; j < count_; j++) {
			arr[j][i] = 1;
		}
	}
}


void movedown(int ** arr, int n, int m){
    int count_ = 0 ;
    rep(i, m) {
		count_ = 0;
		rep(j, n) {
			if(arr[j][i])
                count_++;
			arr[j][i] = 0;
		}

		for(int j = n - 1 ; count_ > 0 ; j--) {
			arr[j][i] = 1;
			count_-- ;
		}
	}
}

void moveleft(int ** arr, int n, int m){
    int count_ = 0 ;
    rep(i, n){
        count_ = 0 ;
        rep(j, m){
            if(arr[i][j] == 1){
                count_++ ;
                arr[i][j] = 0 ;
            }
        }

        for(int j = 0 ; j < count_ ; j++){
            arr[i][j] = 1 ;
        }
    }
}

void moveright(int ** arr, int n, int m){
    int count_ = 0 ;
    rep(i, n){
        count_ = 0 ;
        rep(j, m){
            if(arr[i][j] == 1){
                count_++ ;
                arr[i][j] = 0 ;
            }
        }
        for(int j = m - 1 ; count_ > 0 ; j--){
            arr[i][j] = 1 ;
            count_--;
        }
    }
}

int main(){
    int t, n, m ;
    std::cin >> t ;
    std::string str, s ;
    while(t-->0){
        std::cin >> n >> m ;
        int **arr = new int*[n] ;
        rep(i, n){
            arr[i] = new int[m] ;
        }

        rep(i, n){
            std::cin >> str ;
            rep(j, m){
                arr[i][j] = str[j] - '0' ;
            }
        }

        std::cin >> str ;

        s = "" ;

        bool lr = 0, ud = 0 ;
        for(int i = str.size() - 1 ; i > 0 ; i--){
            if(lr && ud){
                break ;
            }
            if((str[i] == 'U' || str[i] == 'D') && !ud){
                s += str[i] ;
                ud = 1 ;
            }
            else if((str[i] == 'L' || str[i] == 'R') && !lr){
                s += str[i] ;
                lr = 1 ;
            }
        }

        s.insert(s.begin(), (char)str[0]) ;

//        std::cout << s << "\n" ;

        rep(i, 3){
            if(s[i] == 'U'){
                moveup(arr, n, m) ;
            }
            else if(s[i] == 'D'){
                movedown(arr, n, m) ;
            }
            else if(s[i] == 'L'){
                moveleft(arr, n, m) ;
            }
            else if(s[i] == 'R'){
                moveright(arr, n, m) ;
            }
            else{
                    //pass
            }
        }

        rep(i, n){
            rep(j, m){
                std::cout << arr[i][j] ;
            }
            std::cout << "\n" ;
        }
    }
}
