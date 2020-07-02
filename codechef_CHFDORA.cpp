#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

std::vector <std::vector <int>> arr, check ;

int main(){
	freopen("output.txt", "r", stdin);

	int t = 1 ;
	std::cin >> t ;

	 fast();
	int n, m ;
	while(t--){
		std::cin >> n >> m ;
		
		arr = std::vector <std::vector <int>> (n, std::vector <int> (m)) ;
		check = std::vector <std::vector <int>> (n, std::vector <int> (m, 1)) ;

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				std::cin >> arr[i][j] ;
			}
		}

		long long ans = n*m ;

		for(int len = 1 ; len <= n/2 ; len++){
			for(int i = 1 ; i < n - 1; i++){
				for(int j = 1 ; j < m - 1 ; j++){

					if(!check[i][j]) continue ;

					int up = i - len, down = i + len, left = j - len, right = j + len ;

					if(up >= 0 && down < n && left >= 0 && right < m &&
						arr[up][j] == arr[down][j] && arr[i][left] == arr[i][right]){
						
						ans++ ;
					}
					else{
						check[i][j] = 0 ;
					}
				}
			}
		}

		std::cout << ans << "\n" ;
	}
}