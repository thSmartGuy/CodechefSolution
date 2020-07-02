#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

std::map <int, long long> mp ;
std::vector<int> arr ;
const int mod = 1e9 + 7 ;

std::map <std::pair<int, int>, long long> memo ;

long long recur(int idx, int k){
	if(k == 0 || idx == arr.size()) return 1 ;

	if(memo.count({idx, k})) return memo[{idx, k}] ;

	long long ans = 0 ;
	// take this element 
	ans = (mp[arr[idx]] * recur(idx + 1, k - 1))%mod ;

	// not take this element
	ans = (ans + recur(idx + 1, k))%mod ;

	return memo[{idx, k}] = ans ;
}

int main(){
	//fast();
	// freopen("input.txt", "r", stdin) ;
	// freopen("output.txt", "w", stdout) ;

	int n, k ;

	std::cin >> n >> k ;

	arr.resize(n) ;

	for(int i = 0 ; i < n ; i++){
		std::cin >> arr[i] ;
		mp[arr[i]]++ ;
	}

	std::sort(arr.begin(), arr.end()) ;
	arr.erase(std::unique(arr.begin(), arr.end()), arr.end()) ;

	// for(int a:arr)std::cout <<a<<" " ; 
	// std::cout << "\n" ;
	// for(int i = 0 ; i <= k ; i++){
	// 	ans = ans + recur(0, i) ;
	// }

	std::cout << recur(0, k) << "\n" ;
}

// 2 2 3 3 5
// 2 * 2 * 1 || 5
// 2 * 2 + 2 * 1 || 6
// 2 * 1 || 2
// 2 + 2 + 1 || 5