#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[100011] ;
long long pre[100011] ;
std::map <int, std::vector <int>> mp ;

int main(){
	int t = 1, n;
	std::cin >> t ;

	//fast();
	while(t--){
		std::cin >> n ;
		mp.clear() ;

		for(int i = 1 ; i <= n ; i++) std::cin >> arr[i] ;
		
		pre[0] = 0 ;
		mp[0] = {0} ;
		for(int i = 1 ; i <= n ; i++){
			pre[i] = pre[i - 1]^arr[i] ;
			if(mp.count(pre[i])){
				mp[pre[i]].push_back(i) ;
			}
			else{
				mp[pre[i]] = {i} ;
			}
		}

		long long ans = 0 ;

		for(auto it:mp){
			if(it.second.size() > 1){
				//std::cout << it.first << " : \n" ;
				//std::cout << "***********************************\n" ;
				for(int i = 0 ; i < it.second.size() ; i++){
					//std::cout << it.second[i] << " " ;
					pre[i] = it.second[i] ;
				}
				//std::cout << "\n" ;

				//std::cout << pre[0] << " " ;
				for(int i = 1 ; i < it.second.size() ; i++){
					pre[i] += pre[i - 1] ;
					//std::cout << pre[i] << " " ;
				}
				//std::cout << ": \n" ;

				for(long long i = 0 ; i < it.second.size() - 1 ; i++){
					ans += (long long)(pre[it.second.size() - 1] - (long long)it.second[i]*(it.second.size() - (i + 1)) 
							- (it.second.size() - (i + 1)) - pre[i]) ;
				//	std::cout << "adding " <<  (pre[it.second.size() - 1] - it.second[i]*(it.second.size() - (i + 1)) - (it.second.size() - (i + 1)) - pre[i]) <<  "\n" ;
				}
				//std::cout << "\n" ;
			}
		}
		std::cout << ans << "\n" ;
	}
}