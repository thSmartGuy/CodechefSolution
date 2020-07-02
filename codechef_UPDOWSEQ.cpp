#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[1000111] ;
int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int n ;
	while(t--){
		std::cin >> n ;

		for(int i = 0 ; i < n ; i++) std::cin >> arr[i] ;

		int upStartingLength[n + 1] ; 
		std::fill(&upStartingLength[0], &upStartingLength[0] + n + 1, 0) ;

		bool up ;

		for(int i = 0 ; i < n ; i++){
			up = 1 ;
			int l = 1 ;
			for(int j = i + 1 ; j < n ; j++){
				if(up){
					if(arr[j] >= arr[j - 1]){
						l++ ;
					}
					else break ;
				}
				else{
					if(arr[j] <= arr[j - 1]){
						l++ ;
					}
					else break ;
				}

				up = !up ;
			}
			upStartingLength[i] = l ;
		}

		int downStartingLength[n + 1] ; 
		std::fill(&downStartingLength[0], &downStartingLength[0] + n + 1, 0) ;

		for(int i = 0 ; i < n ; i++){
			up = 0 ;
			int l = 1 ;
			for(int j = i + 1 ; j < n ; j++){
				if(up){
					if(arr[j] >= arr[j - 1]){
						l++ ;
					}
					else break ;
				}
				else{
					if(arr[j] <= arr[j - 1]){
						l++ ;
					}
					else break ;
				}

				up = !up ;
			}
			downStartingLength[i] = l ;
		}

		/*
		for(int i = 0 ; i < n ; i++){
			std::cout << upStartingLength[i] << " " ;
		}
		std::cout << "\n" ;

		for(int i = 0 ; i < n ; i++){
			std::cout << downStartingLength[i] << " " ;
		}
		std::cout << "\n" ;
		//*/

		int ans = 0 ;

		for(int i = 0 ; i < n ; i++){
			int next = upStartingLength[i] + i ;

			if(next < n){
				int length = upStartingLength[i] ;

				if((length&1)){
					length += upStartingLength[next] + 1 ;
				}
				else{
					length += downStartingLength[next] + 1 ;
				}
				ans = std::max(ans, length) ;
			}
			else{
				ans = std::max(ans, upStartingLength[i] + 1) ;
			}
		}
		std::cout << ans << "\n" ;
	}
}