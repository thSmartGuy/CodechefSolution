#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[1111] ;

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int n, k, p ;
	while(t--){
		std::cin >> n >> k >> p ;

		for(int i = 0 ; i < n ; i++){
			std::cin >> arr[i] ;
		}

		int max_ = INT_MIN, min_ = INT_MAX ;

		for(int i = 0 ; i < n ; i++){
			max_ = std::max(max_, arr[i]) ;
			min_ = std::min(min_, arr[i]) ;
		}

		int maxl, maxr ;
		if(p == 0){ // maximize
			if(k&1 || n == 2){
				std::cout << max_ << "\n" ;
			}
			else{
				int maxl = INT_MIN, maxr = INT_MIN  ;
				for(int i = 1 ; i < n - 1 ; i++){
					if(std::min(arr[i - 1], arr[i + 1]) > std::min(maxl, maxr)){
						maxl = arr[i - 1] ;
						maxr = arr[i + 1] ;
						max_ = std::min(maxl, maxr) ;
					}
				}

				if(arr[1] > max_){
					max_ = arr[1] ;
				}

				if(arr[n - 2] > max_){
					max_ = arr[n - 2] ;
				}

				std::cout << max_ << "\n" ;
			}
		}
		else{ // minimize 
			if(k&1 || n == 2){
				std::cout << min_ << "\n" ;
			}
			else{
				int minl = INT_MAX, minr = INT_MAX  ;
				for(int i = 1 ; i < n - 1 ; i++){
					if(std::max(arr[i - 1], arr[i + 1]) < std::max(minl, minr)){
						minl = arr[i - 1] ;
						minr = arr[i + 1] ;
						max_ = std::max(minl, minr) ;
					}
				}

				if(arr[1] < max_){
					max_ = arr[1] ;
				}

				if(arr[n - 2] < max_){
					max_ = arr[n - 2] ;
				}

				std::cout << max_	 << "\n" ;
			}
		}	
	}
}