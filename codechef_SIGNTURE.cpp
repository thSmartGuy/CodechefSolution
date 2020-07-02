#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int main(){
	int t = 1 ;
	std::cin >> t ;

	fast();

	int n, m ;
	while(t--){
		std::cin >> n >> m ;

		int ori[n][m], arr[75][75] ;

		std::string tmp ;
		for(int i = 0 ; i < n ; i++){
			std::cin >> tmp ;
			for(int j = 0 ; j < m ; j++){
				ori[i][j] = tmp[j] -'0' ;
			}
		}
		
		for(int i = 0 ; i < 75 ; i++){
			for(int j = 0 ; j < 75 ; j++){
				arr[i][j] = 0 ;
			}
		}

		for(int i = 25 ; i < 25 + n ; i++){
			std::cin >> tmp ;
			for(int j = 25 ; j < 25 + m ; j++){
				arr[i][j] = tmp[j - m] - '0' ;
			}
		}

		int min_diff = INT_MAX ;
		for(int i = 0 ; i < 50 ; i++){
			for(int j = 0 ; j < 50 ; j++){
				// findDiff
				int tmp = 0 ;
				for(int ii = i ; ii < i + n ; ii++){
					for(int jj = j ; jj < j + m ; jj++){
						int curI = ii - i ;
						int curJ = jj - j ;

						if(ori[curI][curJ] != arr[ii][jj]){
							tmp++ ;
						}
					}
				}
				min_diff = std::min(min_diff, tmp) ;
			}
		}
		std::cout << min_diff << "\n" ;
	}
}