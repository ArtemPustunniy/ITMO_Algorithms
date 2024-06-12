#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node{
    int pos;
    char next;
};

vector<Node> encodeLZ78(string s){
    string buffer;
    map<string, int> dict;
    vector<Node> answer;
    for (int i = 0; i < s.length(); i++){
        if (dict.count(buffer + s[i]) > 0){
            buffer += s[i];
        }
        else{
            answer.push_back({dict[buffer], s[i]});
            dict[buffer + s[i]] = dict.size();
            buffer = "";
        }
    }
    if(!buffer.empty()){
        char last_ch = buffer.back();
        //buffer.pop_back();
        answer.push_back({dict[buffer], '\0'});
    }
    return answer;
}

int main(){
    string input;
    cin >> input;
    vector<Node> answer;
    answer = encodeLZ78(input);
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i].pos << " " << answer[i].next << "\n";
    }

    return 0;
}
