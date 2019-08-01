#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[100011] ;
std::vector <std::pair<int, int>> vv ; // val-idx

bool comp(std::pair<int, int> p, std::pair<int, int> q){
    if(p.first == q.first) return p.second < q.second ;
    return p.first < q.first ;
}

int main(){
	//fast();
	int n, k, p, a, b ;
	std::cin >> n >> k >> p ;
	vv.resize(n) ;

	for(int i = 0 ; i < n ; i++){
		std::cin >> arr[i] ;

		vv[i].first = arr[i] ;
		vv[i].second = i ;
	}

	std::sort(vv.begin(), vv.end(), comp) ;

	int idx = vv[0].second ;
	arr[idx] = idx ; // reachable from 0 or (take anything)

	for(int i = 1 ; i < n ; i++){
		idx = vv[i].second ;
		if(vv[i].first - vv[i - 1].first <= k){ // reachable
			arr[idx] = arr[vv[i - 1].second] ; // can be reached with same starting
		}
		else{
			arr[idx] = idx ;
		}

//		for(int i = 0 ; i < n ; i++) std::cout << arr[i] << " " ; std::cout << "\n" ;
	}

	std::string ans ;
	while(p--){
		ans = "No" ;

		std::cin >> a >> b ;

		a--, b-- ;
		if(arr[a] == arr[b]){
			ans = "Yes" ;
		}

		std::cout << ans << "\n" ;
	}
}
