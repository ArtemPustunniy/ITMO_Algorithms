#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<string> gray_codes;
    gray_codes.emplace_back("0");
    gray_codes.emplace_back("1");

    for (int i = 2; i < (1 << n); i = i << 1) {
        for (int j = i - 1; j >= 0; j--) {
            gray_codes.push_back(gray_codes[j]);
        }
        for (int j = 0; j < i; j++) {
            gray_codes[j] = "0" + gray_codes[j];
        }
        for (int j = i; j < 2 * i; j++) {
            gray_codes[j] = "1" + gray_codes[j];
        }
    }

    for (int i = 0; i < gray_codes.size(); i++){
        cout << gray_codes[i] << "\n";
    }

    return 0;
}
