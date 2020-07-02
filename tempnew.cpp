#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

bool isPalindrome(std::string &str){
	int st = 0, en = str.size() - 1 ;

	while(st < en){
		if(str[st] != str[en]) return 0 ;
		st++ ; en-- ;
	}
	return 1 ;
}

std::map <int, int> mp ;
long long recur(std::string &str, int *allowed, int st){
	int en = str.size() - 1 - st ;

	if(st >= en){
		if(isPalindrome(str)){
			return 0 ;
		}
		else return INT_MAX ;
	}

	if(mp.count(st)) return mp[st] ;

	if(str[en] == str[st]){
		return mp[st] = recur(str, allowed, st + 1) ;
	}
	else{

		long long minCost = INT_MAX ;
		if(st + 1 < en && str[st + 1] == str[en] && allowed[st] && allowed[st + 1]){
			std::swap(str[st + 1], str[st]) ;
			allowed[st + 1] = allowed[st] = 0 ;
			minCost = recur(str, allowed, st + 1) ;
		}
		else if(en - 1 > st 	&& str[en - 1] == str[st] && allowed[en - 1] && allowed[en]){
			std::swap(str[en - 1], str[en]) ;
			allowed[en - 1] = allowed[en] = 0 ;
			minCost = recur(str, allowed, st + 1) ;
		}
		return  mp[st] = minCost == INT_MAX ? INT_MAX : minCost + 1 ;
	}
}

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int n ; std::string str ;
	while(t--){
		mp.clear() ;
		std::cin >> n >> str ;

		int *allowed = new int[n] ;
		for(int i = 0 ; i < n ; i++) allowed[i] = 1 ;

		long long ans = recur(str, allowed, 0) ;
		if(ans != INT_MAX){
			std::cout << "YES\n" << ans << "\n" ;
		}
		else std::cout << "NO\n" ;
	}
}