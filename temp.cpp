#include <iostream>
#include <vector>

using namespace std;

#define read(arr, n) for (int i = 1; i <= n; i++) cin >> arr[i];
#define print(arr, n) for (int i = 1; i <= n; i++) cout << arr[i] << " ";
#define copy_(arr2, arr, n) for (int i = 1; i <= n; i++) arr2[i] = arr[i];

typedef long long int lld;

inline void fast (){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){
//    fast();

    lld t, n, sum, max_, tt;
    cin >> t;

    while (t--){
        cin >> n;
        lld arr[n + 1], arr2[n + 1];

        arr[0] = 0;
        max_ = 0;

        read (arr, n);

        for (lld st = n; st >= 1; st--){
            copy_(arr2, arr, n);
            arr2[0] = 0;
//            print (arr2, n);
//            cout << "\n";

            for (lld i = st; i >= 1; i--){
                if (arr2[i] < arr2[i - 1]){
                    swap(arr2[i], arr2[i - 1]);
                    i--;
                }
            }

            sum = 0;

//            print (arr2, n);
            for (lld i = 1; i <= n; i++){
                tt = (long long)(arr2[i] * i) ;
                sum += tt;
            }

//            cout << " " << sum << "\n";
            if (sum > max_) max_ = sum;
        }

        cout << max_ << "\n";
    }

    return 0;
}
