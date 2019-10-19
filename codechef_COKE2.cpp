#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

void update(int, int, int, int, int, int) ;
int query(int, int, int, int) ;
std::vector <int> st ;

int c[111111], p[111111] ;
int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	while(t--){
		st.assign(4*111111, INT_MAX) ;

		int n, q, k, l, r ;
		std::cin >> n >> q >> k >> l >> r ;

		for(int i = 0 ; i < n ; i++){
			std::cin >> c[i] >> p[i] ;

			int ll = 1e9, rr = -1 ;
			if(k < l){
				if(c[i] < l){
					// not possible 
					// pass
				}
				else if(c[i] > r){
					ll = c[i] - r ;
					rr = c[i] - l ;
				}
				else if(l <= c[i] && c[i] <= r){
					ll = 1 ;
					rr = c[i] - l ;
				}
				else{
					// pass
				}
			}
			else if(k > r){
				if(c[i] > r){
					// pass 
					// not possible
				}
				else if(c[i] < l){
					ll = l - c[i] ;
					rr = r - c[i] ;
				}
				else if(l <= c[i] && c[i] <= r){
					ll = 1 ;
					rr = r - c[i] ; 
				}
				else{
					// pass 
				}
			}
			else if(l <= k && k <= r){
				if(c[i] > r){
					ll = c[i] - r;
					rr = q ;
				}
				else if(c[i] < l){
					ll = l - c[i] ;
					rr = q ;
				}
				else if(l <= c[i] && c[i] <= r){
					ll = 1 ;
					rr = q ;
				}
				else{
					// pass
				}
			}
			else{
				// pass 
			}

			ll = std::max(1, ll) ;
			rr = std::min(q, rr) ;

			//std::cout << "ll: " << ll << " rr: " << rr << "\n" ;
			if(ll != 1e9 && rr != -1 && ll <= rr){
				update(1, ll, rr, 1, q, p[i]) ;
			}
		}

		for(int i = 1 ; i <= q ; i++){
			int kk = query(1, i, 1, q) ;
			std::cout << (kk == INT_MAX ? -1 : kk) << " " ;
		}
		std::cout << "\n" ;
	}
}

int query(int cur, int idx, int l, int r){
	if(l > r || l > idx || r < idx) return INT_MAX ;

	if(l == r){
		return st[cur] ;
	}

	int mid = (l + r) / 2 ;

	int ll = INT_MAX ; 
	int rr = INT_MAX ;

	if(idx >= l && idx <= mid){
		ll = query(2*cur, idx, l, mid) ;
	}

	if(idx >= mid + 1 && idx <= r){
		rr = query(2*cur + 1, idx, mid + 1, r) ;
	}

	return std::min(st[cur], std::min(ll, rr)) ;
}

void update(int cur, int ql, int qr, int l, int r, int val){
	//std::cout << cur << ", " << ql << ", " << qr << ", " << l << ", " << r << ", " << val << "\n" ;
	if(l > r || l > qr || r < ql){
		return ;
	}

	if(l >= ql && r <= qr){
		st[cur] = std::min(st[cur], val) ;
		return ;
	}

	int mid = (l + r) / 2 ;

	if(l <= mid){
		update(2*cur, ql, qr, l, mid, std::min(val, st[cur])) ;
	}
	if(r >= mid + 1){
		update(2*cur + 1, ql, qr, mid + 1, r, std::min(val, st[cur])) ;	
	}
}