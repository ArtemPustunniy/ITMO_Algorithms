#include "iostream"
#include "vector"

using namespace std;

int n;
int my_length = 1000003;

int hash_1(string& this_str) {
    int new_hash = 0;

    for (int i = 0; i < this_str.size(); i++){
        new_hash += new_hash * 31 + this_str[i];
    }

    return (new_hash % my_length);
}

int hash_2(string& this_str) {
    int new_hash = 0;

    for (int i = 0; i < this_str.size(); i++){
        new_hash += new_hash * 113 + this_str[i];
    }

    return (new_hash % (my_length - 1)) + 1;
}

void insert_all(vector<string>& this_add, string& this_str){
    int hash1 = hash_1(this_str);
    int hash2 = hash_2(this_str);

    if(this_add[hash1].empty()) {
        this_add[hash1] = this_str;
    }
    else if(this_add[hash2].empty()) {
        this_add[hash2] = this_str;
    }
    else {
        string temp = this_add[hash1];
        this_add[hash1] = this_str;

        while(!this_add[hash_2(temp)].empty() && this_add[hash_2(temp)] != temp) {
            swap(this_add[hash_2(temp)], temp);
            this_add[hash_2(temp)] = temp;
        }
    }
}

bool exists(vector<string>& this_check, string& this_str) {
    return (this_check[hash_1(this_str)] == this_str) || (this_check[hash_2(this_str)] == this_str);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> first_input;
    vector<string> first(my_length);

    vector<string> second_input;
    vector<string> second(my_length);

    vector<string> third_input;
    vector<string> third(my_length);

    int ball_1 = 0;
    int ball_2 = 0;
    int ball_3 = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        string input_1;
        cin >> input_1;
        insert_all(first,input_1);
        first_input.push_back(input_1);
    }
    for(int i = 0; i < n; i++){
        string input_2;
        cin >> input_2;
        insert_all(second,input_2);
        second_input.push_back(input_2);
    }
    for(int i = 0; i < n; i++){
        string input_3;
        cin >> input_3;
        insert_all(third,input_3);
        third_input.push_back(input_3);
    }

    for (int i = 0; i < n;i++){
        if(!exists(second,first_input[i]) && !exists(third,first_input[i])){
            ball_1 += 3;
        }
        else if (!exists(second,first_input[i]) && exists(third,first_input[i]) || exists(second,first_input[i]) && !exists(third,first_input[i])) {
            ball_1 += 1;
        }
    }
    for (int i = 0; i < n; i++){
        if (!exists(first,second_input[i]) && !exists(third,second_input[i])){
            ball_2 += 3;
        }
        else if (!exists(first,second_input[i]) && exists(third,second_input[i]) || exists(first,second_input[i]) && !exists(third,second_input[i])){
            ball_2 += 1;
        }
    }
    for (int i = 0; i < n; i++){
        if (!exists(first,third_input[i]) && !exists(second,third_input[i])){
            ball_3 += 3;
        }
        else if (!exists(first,third_input[i]) && exists(second,third_input[i]) || exists(first,third_input[i]) && !exists(second,third_input[i])){
            ball_3 += 1;
        }
    }

    cout << ball_1 << " " << ball_2 << " " << ball_3;
}
