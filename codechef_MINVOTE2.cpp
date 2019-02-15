#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 1e5 + 10;
const int MAXT = (int) 1e5;

int n, s[MAXN];
long long S[MAXN];
int votes[MAXN];

void print(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		printf("%d", v[i]);
		if (i + 1 < v.size()) printf(" ");
		else printf("\n");
	}
}

vector<int> fastSolve() {
	for (int i = 0; i <= n; i++) {
		votes[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		{
			int lo = 1, hi = i - 1, where = i;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (s[i] >= S[i - 1] - S[mid]) {
					where = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			// fprintf(stderr, "backward: i = %d, where = %d\n", i, where);
			votes[where]++;
			votes[i]--;
		}
		{
			int lo = i, hi = n, where = i + 1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (s[i] >= S[mid - 1] - S[i]) {
					where = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			votes[i + 1]++;
			votes[where + 1]--;
			// fprintf(stderr, "forward: i = %d, where = %d\n", i, where);
		}
	}
	int total = 0;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		total += votes[i];
		ans.push_back(total);
	}
	return ans;
}

int main() {
	int T, sumN = 0;
	scanf("%d", &T);
	assert(T >= 1 && T <= MAXT);
	while (T--) {
		scanf("%d", &n);
		assert(n >= 1 && n <= MAXT);
		sumN += n;
		S[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &s[i]);
			assert(s[i] >= 1 && s[i] <= (int) 1e9);
			S[i] = S[i - 1] + s[i];
		}
		auto it = fastSolve();
		print(it);
	}
	assert(sumN >= 1 && sumN <= MAXT * 10);
	return 0;
}
