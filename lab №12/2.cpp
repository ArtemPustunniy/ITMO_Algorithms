#include "iostream"
#include "vector"
#include "algorithm"
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<pair<int, long long>> hash_table;
vector<long long> Big_hashes;
vector<int> word_1;
vector<int> word_2;

long long create_a_big_random() {
    random_device a;
    mt19937 gen(a());
    uniform_int_distribution<long long> prom(100001, 10000000000000);

    return prom(gen);
//    srand(time(0));
//    long long randomNumber = rand() % 9999999999999 + 100001;
//    cout << randomNumber << "\n";
//    return randomNumber;
}

void insert(int key, long long value) {
    int index = key % 100000;

    while (hash_table[index].first != -1 && hash_table[index].second != -1) {
        index = (index + 1) % 100000;
    }

    hash_table[index].first = key;
    hash_table[index].second = value;

}

long long get(int key) {
    int index = key % 100000;

    while (hash_table[index].first != -1 && hash_table[index].second != -1) {
        if (hash_table[index].first == key) {
            return hash_table[index].second;
        }

        index = (index + 1) % 100000;
    }

    return 0;
}

bool BS(vector<long long>&mas, long long target) {
    long long left = 0;
    long long right = mas.size() - 1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mas[mid] == target) {
            return true;
        }
        else if (mas[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    hash_table.resize(100000, make_pair(-1, -1));
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        word_1.push_back(a);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++){
        int b;
        cin >> b;
        word_2.push_back(b);
    }

    for (int i = 0; i < word_1.size(); i++) {
        long long sum = 0;
        for (int j = i; j < word_1.size(); j++) {
            long long get_hash = get(word_1[j]);
            if (get_hash == 0) {
                long long get_big_hash = create_a_big_random();
//                cout << get_big_hash << "\n";
                insert(word_1[j], get_big_hash);
                sum += get_big_hash;
            }
            else{
                sum += get_hash;
            }
            Big_hashes.push_back(sum + (j - i + 1));
        }
    }

    sort(Big_hashes.begin(), Big_hashes.end());
    long long common_digits = 0;

    for (int i = 0; i < M; i++) {
        long long s = 0;
        for (int j = i; j < M; j++) {
            long long res = get(word_2[j]);
            if (res == 0 || j - i + 1 > word_1.size()) {
                break;
            }
            s += res;
            if (j - i + 1 > common_digits && BS(Big_hashes, s + (j - i + 1))) {
                common_digits = j - i + 1;
            }
        }
    }

    cout << common_digits;

    return 0;
}
