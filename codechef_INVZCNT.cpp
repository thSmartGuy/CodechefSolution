#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[1111111] ;
int copyArr[1111111] ;
int aux[1111111] ;

void copy(int n){
	for(int i = 0 ; i < n ; i++) {
		copyArr[i] = arr[i] ;
	}
}

long long k ;
long long ans ;
void mergeSort(int l, int r){
	if(l < r){
		int mid = (l + r) >> 1 ;

		mergeSort(l, mid) ;
		mergeSort(mid + 1, r) ;

		int it1 = l, it2 = mid + 1, it = l ;
		while(it1 <= mid && it2 <= r){
			if((copyArr[it1]^k) <= (copyArr[it2]^k)){
				aux[it++] = copyArr[it1++] ;
			}
			else{
				ans += mid - it1 + 1 ;
				aux[it++] = copyArr[it2++] ;
			}
		}

		while(it1 <= mid){
			aux[it++] = copyArr[it1++] ;
		}

		while(it2 <= r){
			aux[it++] = copyArr[it2++] ;	
		}

		for(int i = l ; i <= r ; i++){
			copyArr[i] = aux[i] ;
		}
	}
}


int main(){
	int t = 1 ;
	std::cin >> t ;

	int n, q ; 
	while(t--){
		std::cin >> n >> q ;

		for(int i = 0 ; i < n ; i++){
			std::cin >> arr[i] ;
		}

		while(q--){
			ans = 0 ; 
			copy(n) ; 

			std::cin >> k ;

			mergeSort(0, n - 1) ;

			std::cout << ans << '\n' ;
		}
	}
}