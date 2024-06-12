#include <iostream>

using namespace std;


struct Node {
    long long elem;
    Node *left;
    Node * right;
    Node *pref;

    Node(long long elem_, Node *previous){
        elem = elem_;
        left = nullptr;
        right = nullptr;
        pref = previous;
    }
};

struct check_BST_in_BT {
    long long summ;
    long long maximal;
    long long minimal;
    check_BST_in_BT(long long summ_, long long minimal_, long long maximal_) {
        summ = summ_;
        maximal = maximal_;
        minimal = minimal_;
    }
};

Node *head = nullptr;
Node *now = nullptr;
long long answer = 0;

void insert(long long elem_, char command){
    if (command == 'l'){
        now->left = new Node(elem_, now);
        now = now->left;
    }
    else{
        now->right = new Node(elem_, now);
        now = now->right;
    }
}


check_BST_in_BT helper(struct Node *root) {
    if(root == nullptr){
        return {0,LLONG_MAX,LLONG_MIN};
    }
    auto right = helper(root->right);
    auto left = helper(root->left);
    if(root->elem < right.minimal && root->elem > left.maximal){
        long long sum = root->elem + left.summ + right.summ;
        answer = max(answer, sum);
        return {sum,min(root->elem, left.minimal),max(root->elem, right.maximal)};
    }
    else{
        long long maximum = max(left.summ, right.summ);
        return {maximum,LLONG_MIN,LLONG_MAX};
    }

}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long first_cin;
    cin >> first_cin;
    head = now = new Node(first_cin, nullptr);
    char input_com;
    while(cin >> input_com && cin.peek() != '\n'){
        //cin >> input_com;
        if (input_com == 'l'){
            long long input_val;
            cin >> input_val;
            insert(input_val, 'l');
        }
        else if(input_com == 'r'){
            long long input_val;
            cin >> input_val;
            insert(input_val, 'r');
        }
        else if(input_com == 'u'){
            if (now->pref != nullptr){
                now = now->pref;
            }
            //now = now->pref;
        }
    }

    helper(head);
    cout << answer;

    return 0;
}
