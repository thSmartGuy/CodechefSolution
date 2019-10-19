#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[511111] ;

int main(){
	int n, k ;

	std::cin >> n >> k ;

	for(int i = 0 ; i < n ; i++){
		std::cin >> arr[i] ;
	}

	if(n == k){
		std::sort(arr, arr + n) ;
	}
	else{
		int idx = 0, max_ = arr[0] ;
		int minIdx = 0, min_ = arr[0] ;

		for(int i = 1 ; i < n ; ++i){
			if(max_ < arr[i]){
				max_ = arr[i] ;
				idx = i ;
			}

			if(min_ > arr[i]){
				min_ = arr[i] ;
				minIdx = i ;
			}
		}
		std::swap(arr[idx], arr[minIdx]) ;
	}

	for(int i = 0 ; i < n ; i++){
		std::cout << arr[i] << " " ;
	}
}