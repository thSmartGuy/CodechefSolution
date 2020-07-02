#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

bool bothEqual(int *arr, int *brr, int n) {
	std::map <int, int>  freq; 

	for(int i = 0 ; i < n ; i++){
		freq[brr[i]]++ ;
	}

	for(int i = 0 ; i < n ; i++){
		if(!freq.count(arr[i]) || freq[arr[i]] == 0){
			return 0 ;		
		}
		freq[arr[i]]-- ;
	}
	return 1 ;
}

int arr[111111], brr[111111] ;
int main(){
	//fast();
	int t = 1 ;
	std::cin >> t ;

	int n ;
	while(t--){
		std::cin >> n ;
		long x = 0 ;
		for(int i = 0 ; i < n ; i++){ 
			std::cin >> arr[i] ;
			x ^= arr[i] ;
		}

		for(int i = 0 ; i < n ; i++) {
			std::cin >> brr[i] ;
			x ^= brr[i] ;
		}

		for(int i = 0 ; i < n ; i++){ 
			arr[i] ^= x ;
		}		

		if(bothEqual(arr, brr, n)){
			for(int i = 0 ; i < n ; i++) {
				std::cout << arr[i] << " " ;
			}			
			std::cout << "\n" ;
		}
		else std::cout << "-1\n" ;
	}
}