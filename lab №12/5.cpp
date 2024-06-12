#include "iostream"
#include "vector"

using namespace std;

int my_max = 10000000;

int get_factorial(int summa) {
    int chislo = 1;
    while(summa != 0){
        chislo *= summa;
        summa--;
    }
    return chislo;
}

int my_hash(int key, int n){
    return (key + my_max) % (4 * n);
}

int main(){
    int n;
    int x;
    cin >> n;
    vector<vector<int>> S(4 * n);
    vector<int> support;

    for(int i = 0; i < n; i++) {
        cin >> x;
        S[my_hash(x - i, n)].push_back(x);
    }

    int result = 0;

    for(const auto& i: S) {
        int f = i.size();
        int first_factorial = get_factorial(i.size());
        int second_factorial = 2 * get_factorial(abs(f - 2));
        result += first_factorial / second_factorial;
    }

    cout << result;

}
