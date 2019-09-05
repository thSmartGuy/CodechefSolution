#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[211111], brr[211111] ;

void copy(int n){
	for(int i = 0 ; i < n ; i++){
		brr[i] = arr[i] ;
	}
}

std::map <int, int> mp ;

int have(int n){
	mp.clear() ;

	int max = 0 ;
	for(int i = 0 ; i < n ; i++){
		mp[brr[i]] ++ ;
		if(mp[brr[i]] > max){
			max = mp[brr[i]] ;
		}
	}
	return max; 
}

int main(){
	int n, k ;

	std::cin >> n > k ;

	arr[0] = 0 ;
	for(int i = 1 ; i <= n ; i++){
		std::cin >> arr[i] ;
	}

	std::sort(arr, arr + n + 1) ;
	copy(n + 1) ;

	int min = INT_MAX ;

	if(have(n + 1) >= k){
		min = 0 ;
	}

	int tmp ;
	for(int i = 0 ; i <= n ; i++){
		tmp = 0 ;
		copy(n + 1) ;

		for(int i = 0 ; i < n ; i++){
			if(brr[i] > arr[i]){

				while(brr[i] >= arr[i]){
					brr[i] /= 2 ;
					tmp++ ;
				}

				if(have(n + 1) >= k){
					if(tmp < min){
						min = tmp ;
					}
					else break ;
				}
			}
		}
	}
	std::cout << min << "\n" ;
}