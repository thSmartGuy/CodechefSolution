#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[111111] ;
std::map <int, int> levelOf, parentOf ;

int main(){
	// fast();
	int n, k, p ;
	std::cin >> n >> k >> p ;

	// int dist ;
	for(int i = 0 ; i < n ; i++){
		std::cin >> arr[i] ;
		levelOf[arr[i]] = i + 1 ;
	}

	std::sort(arr, arr + n) ;


	for(int i = 1 ; i < n ; i++){
		if(arr[i] - arr[i - 1] <= k){
			parentOf[levelOf[arr[i]]] = parentOf[levelOf[arr[i - 1]]] ;
		}
		else{
			parentOf[levelOf[arr[i]]] = levelOf[arr[i]] ;
		}
	}

	int u, v ;
	for(int i = 0 ; i < p ; i++){
		std::cin >> u >> v ;

		if(parentOf[u] == parentOf[v]){
			std::cout << "Yes\n" ;
		}
		else{
			std::cout << "No\n" ;
		}
	}
}