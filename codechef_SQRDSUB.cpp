#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

long long arr[111111] ;

void solveBrute(long long n){
	long ans = 0 ;
	for(long long i = 0 ; i < n ; i++){
		long c = 0 ;
		for(long long j = i ; j < n ; j++){
			c += arr[j] ;
			// std::cout << "adding " << arr[j] << "\n" ;
			if(c==0){
				// std::cout << "for i: " << i << " j: " << j << " : c = " << c << " adding = " << 1 << "\n" ; 
				ans++ ;
			}
			else if(c > 1){
				ans += n - j ;
				// std::cout << "for i: " << i << " j: " << j << " : c = " << c << " : adding = " << n - j << "\n" ;
				break ;
			}
		}
	}
	std::cout << ans << "\n" ;
}

long long binarySearch(long long *arr, long lo, long long n, long long ele){
	long long ans = n ; // n

	long long tm = lo ;

	long hi = n - 1 ;
	while(lo <= hi){
		long mid = (lo+hi)/2ll ;

		if(arr[mid] < ele){
			lo = mid + 1 ;
		}
		else if(arr[mid] >= ele){
			hi = mid - 1 ;
			ans = mid ;
		}
	}
	// std::cout << "index for ele: " << ele << " starting: " << tm << " pos: " << ans << "\n" ;
	return ans ;
}

void solve(long long n){
	long long ans = 0 ;

	/// 0 1 0
	/// 0 1 1

	// for handle num not cantainig any twos || zero
	long long lagataar = 0, prev ; 
	long long i = 0 ;
	while(i < n && !arr[i]){
		lagataar++ ; i++ ;
	}

	ans += ((long long)((long long)lagataar*(lagataar + 1ll))/2ll) ;

	// first handle num not containing any twos || non zero
	lagataar = 0, prev = 0 ; 
	for(; i < n ; i++){
		if(prev && arr[i] == prev){
			lagataar++ ;
		}
		else{
			ans += ((long long)((long long)lagataar*(lagataar + 1))/2ll) ;
			lagataar = 0 ;
			prev = arr[i] ;
		}
	}

	if(lagataar){
		ans += ((long long)((long long)lagataar*(lagataar + 1))/2ll) ;
	}

	// now handle all other courses
	long long minus = 0 ;
	for(long long i = 0 ; i < n ; i++){

		// std::cout << "pre["<	<i<<"]: " <<  arr[i] << " - " << " minus: " << minus << "\n" ;
		long long cur = arr[i] - minus ;

		if(cur >= 2){
			ans += n - i ;
			// std::cout << "starting from " << i << " adding: " << n - i << "\n" ;
		}
		else{
			long long diff = 2 - cur ;
			// std::cout << "cur : " << cur << "\n" ;
			long long pos = binarySearch(arr, i, n, arr[i] + diff) ; 

			if(pos!=n){
				ans += n - pos ;
			}
			// std::cout << "starting from " << i << " idx: " << pos << "\n" ;
		}

		minus = arr[i] ;
	}

	std::cout << ans << "\n" ;
}

int main(){
	fast();
	// freopen("input.txt", "r", stdin) ;
	// freopen("output.txt", "w", stdout) ;

	long long t ;
	std::cin >> t ;

	long long n ;
	while(t--){
		std::cin >> n ;
		for(long long i = 0 ; i < n ; i++){
			long long tmp ; std::cin >> tmp ; 
			arr[i] = 0 ;

			while(tmp%2 == 0){
				arr[i]++ ;
				tmp /= 2 ;
				if(arr[i] == 2) break;
			}
		}

		// solveBrute(n) ; 

		// for(long long i = 0 ; i < n ; i++){
		// 	std::cout << arr[i] << " " ;
		// }
		// std::cout << "\n" ;

		for(long long i = 1 ; i < n ; i++){
			arr[i] += arr[i - 1] ;
		}

		// for(long long i = 0 ; i < n ; i++){
		// 	std::cout << arr[i] << " " ;
		// }
		// std::cout << "\n" ;
		
		solve(n) ;
	}

	// long long t = 1 ;
	// std::cin >> t ;

	// long long p = 0, q = 0 ; 
	// long long c = 0 ;

	// std::set <long long> st ;
	// while(c < 100000){
	// 	c++ ;
	// 	st.insert(p*p - q*q) ;
	// 	q++ ;
	// 	if(q==1000){
	// 		p++ ; q=0 ;
	// 	}
	// }

	// c = 0 ;
	// for(auto it:st){
	// 	if(it >= 0){
	// 		c++ ;
	// 		std::cout << it << " " ; 
	// 	}
	// 	if(c == 100) break ;
	// }
}

// 2  6   10  14   18   22   26   30
// 2 2*3 5*2 7*2 2*3*3 11*2 13*2 2*3*5

// gen2 
// 0 1 3 4 5 7 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 
// 31 32 33 35 36 37 39 40 41 43 44 45 47 48 49 51 52 53 55 56 57 
// 59 60 61 63 64 65 67 68 69 71 72 73 75 76 77 79 80 81 83 84 85 
// 87 88 89 91 92 93 95 96 97 99 100 101 103 104 105 107 108 109 111 
// 112 113 115 116 117 119 120 121 123 124 125 127 128 129 131 132

// 2 6 10 14 18 22 26 30 

// gen1
// 0 1 3 4 5 7 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 
// 31 32 33 35 36 37 39 40 41 43 44 45 47 48 49 51 52 53 55 56 57 
// 59 60 61 63 64 65 67 68 69 71 72 73 75 76 77 79 80 81 83 84 85 
// 87 88 89 91 92 93 95 96 97 99 100 101 103 104 105 107 108 109 111 
// 112 113 115 116 117 119 120 121 123 124 125 127 128 129 131 132 