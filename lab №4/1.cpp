#include <iostream>


using namespace std;

int main(){

    int n;
    cin >> n;
    int mas[n + 1];
    for (int i = 1; i < n + 1; i++){
        cin >> mas[i];
    }
    bool Flug = true;
    for (int i = 1; i < n / 2 + 1; i++){
        if (Flug){
            if ((2 * i <= n) && (mas[i] > mas[2 * i])){
                Flug = false;
            }
            if ((2 * i + 1 <= n) && (mas[i] > mas[2 * i + 1])){
                Flug = false;
            }
        } else{
            break;
        }
    }
    if (Flug){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
