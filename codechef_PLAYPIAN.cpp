#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    string str, sta = "no/n";

    while (T--){
        cin >> str;

        for (int i = 0; i < str.size(); i += 2){
            if ((str[i] == 'A' && str[i + 1] == 'B')
                || (str[i] == 'B' && str[i + 1] == 'A')){
                    sta = "yes\n";
                }

            else{
                sta = "no\n";
                break;
            }
        }

        cout << sta;
    }
    return 0;
}
