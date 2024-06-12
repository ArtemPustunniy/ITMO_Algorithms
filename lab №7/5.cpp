#include <iostream>
#include <vector>

using namespace std;

struct chars{
    float count = 0;
    float left_gr;
    float right_gr;
    char simv;
    int is_last;
};


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int alpabet_base = 26;
    vector<char> input;
    chars litters[alpabet_base];
    for (int i = 0; i < alpabet_base; i++) {
        litters[i].simv = (char) ('a' + i);
    }
    char simbol;
    int count = 0;
    char checker;
    while (cin >> simbol){
        count++;
        litters[simbol - 'a'].count++;
        input.push_back(simbol);
        checker = simbol;
    }
    litters[checker - 'a'].is_last = 1;

    vector<chars>intervals;
    for (auto & litter : litters) {
        if (litter.count != 0) {
            litter.count = litter.count / float(count);
            intervals.push_back(litter);
        }
    }

    intervals[0].left_gr = 0;
    intervals[0].right_gr = intervals[0].count;
    intervals[intervals.size() - 1].left_gr = 1 - intervals[intervals.size() - 1].count;
    intervals[intervals.size() - 1].right_gr = 1;
    for (int i = 1; i < intervals.size() - 1; i++) {
        intervals[i].left_gr = intervals[i - 1].right_gr;
        intervals[i].right_gr = intervals[i].left_gr + intervals[i].count;
    }
    float left = 0;
    float right = 1;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < intervals.size(); j++) {
            if (intervals[j].simv == input[i]) {
                left = intervals[j].left_gr;
                right = intervals[j].right_gr;
                break;
            }
        }
        for (int j = 0; j < intervals.size(); j++) {
            if (j != 0)
                intervals[j].left_gr = intervals[j - 1].right_gr;
            else
                intervals[j].left_gr = left;
            intervals[j].right_gr = (intervals[j].count * (right - left)) + intervals[j].left_gr;
        }
    }

    cout << intervals[0].left_gr;
//    for (int i = 0; i < intervals.size(); i++){
//        if (intervals[i].is_last == 1){
//            cout << intervals[i].left_gr;
//        }
//    }
    return 0;
}
