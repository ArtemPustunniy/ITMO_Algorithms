#include "iostream"
#include "vector"

using namespace std;

struct students{
    long long group;
    long long ISU;
    long long points;
};

vector<long long> answer;

void get_a(vector<vector<students>> &hash, long long groups, long long M){
    long long result = 0;
    long long number_of_students = 0;

    auto &this_part = hash[groups % M];

    for (long long j = 0; j < this_part.size(); j++) {
        if (this_part[j].group == groups) {
            result += this_part[j].points;
            number_of_students++;
        }
    }
    answer.push_back(result / number_of_students);
//    cout << result / number_of_students;
}

void delete_one(vector<vector<students>> &hash, long long groups, long long ISU, long long M){
    auto &this_part = hash[groups % M];
    for (auto &j : this_part) {
        if (j.ISU == ISU) {
            j = {};
            break;
        }
    }
}

void get_highest_ball(vector<vector<students>> &hash, long long groups, long long M){
    long long max = -1000000000;
    auto &this_part = hash[groups % M];

    for (long long j = 0; j < this_part.size(); j++) {
        if (this_part[j].group == groups) {
            if (max < this_part[j].points) {
                max = this_part[j].points;

            }
        }
    }
    answer.push_back(max);
//    cout << max;
}


int main(){

    long long M, Q, groups, ISU, points;
    char commands;

    cin >> M >> Q;

    vector<vector<students>> hash(M);

    for(long long i = 0; i < Q; i++) {
        cin >> commands;
        if (commands == 'a') {
            cin >> groups;
            get_a(hash, groups, M);
        }

        else if (commands == '-') {
            cin >> groups >> ISU;
            delete_one(hash, groups, ISU, M);
        }

        else if (commands == '+') {
            cin >> groups >> ISU >> points;
            hash[groups % M].push_back({groups, ISU, points});
        }

        else if (commands == 'm') {
            cin >> groups;
            get_highest_ball(hash, groups, M);
        }
    }

    for (long long i = 0; i < answer.size(); i++){
        cout << answer[i] << "\n";
    }
}
