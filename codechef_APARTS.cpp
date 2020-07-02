#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int n, m ;
int arr[1111][1111], brr[1111][1111] ;

int recur(int x, int y){
	if(x == 0){
		brr[x][y] = arr[x][y] ;

		return arr[x][y] ;
	}

	if(brr[x][y] != -1) return brr[x][y] ;

	int max = arr[x][y] ;

	max = std::max(max, (x-1>=0 ? recur(x-1, y) : 0)) ;
	max = std::max(max, (x-1>=0 && y-1>=0? recur(x-1, y-1) : 0)) ;
	max = std::max(max, (x-1>=0 && y+1<m ? recur(x-1, y+1) : 0)) ;

	return brr[x][y] = max ;
}

int main(){
	//fast();
	// freopen("input.txt", "r", stdin) ;
	// freopen("output.txt", "w", stdout) ;

	int t = 1 ;
	std::cin >> t ;

	while(t--){
		std::cin >> n >> m ;

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				std::cin >> arr[i][j] ;
				brr[i][j] = -1 ;
			}
		}

		for(int j = 0 ; j < m ; j++){
			recur(n - 1, j) ;
		}

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(arr[i][j] == brr[i][j]){
					arr[i][j] = 1 ;
				}
				else{
					arr[i][j] = 0 ;
				}
			}
		}

		// for(int i = 0 ; i < n ; i++){
		// 	for(int j = 0 ; j < m ; j++){
		// 		std::cout <<  brr[i][j] << " " ;
		// 	}
		// 	std::cout << "\n" ;
		// }

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				std::cout <<  arr[i][j] ;
				// brr[i][j] = -1 ;
			}
			std::cout << "\n" ;
		}
	}
}