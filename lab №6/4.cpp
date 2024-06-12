#include <iostream>
#include <string>

using namespace std;

struct Node{
    string elem;
    Node *left;
    Node *right;
    int height;
    int ballance;

    Node(string elem_){
        elem = elem_;
        left = nullptr;
        right = nullptr;
        height = 1;
        ballance = 0;
    }
};

Node *head = nullptr;

int get_height(Node *root){
    if (root == nullptr){
        return 0;
    }
    return root->height;
}

Node *update_height(Node *root){
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    root->ballance = get_height(root->right) - get_height(root->left);

    return root;
}

Node *left_rotate(Node *root){
    Node *temp1 = root->right;
    root->right = temp1->left;
    temp1->left = root;
    temp1 = update_height(temp1);
    root = update_height(root);
    return temp1;
}

Node *right_rotate(Node *root){
    Node *temp1 = root->left;
    root->left = temp1->right;
    temp1->right = root;
    root = update_height(root);
    temp1 = update_height(temp1);
    return temp1;
}

Node* insert(string elem_, struct Node *root, int &count){
    if (root == nullptr){
        return new Node(elem_);
    }
    if (elem_ < root->elem){
        root->left = insert(elem_, root->left, count);
    }
    else if (elem_ > root->elem){
        root->right = insert(elem_, root->right, count);
    }
    else if(elem_ == root->elem) {
        for (int i = 0; i < elem_.length(); i++) {
            bool a = true;
            for (int j = 0; j < i; j++) {
                if (elem_[i] == elem_[j]) {
                    a = false;
                    break;
                }
            }
            if (a) {
                count++;
            }
        }
        return root;
    }

    root = update_height(root);

    int balance = get_height(root->right) - get_height(root->left);
    if (balance == -2 && root->left->ballance == 1){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    else if(balance == -2 && root->left->ballance != 1){
        return right_rotate(root);
    }
    else if(balance == 2 && root->right->ballance != -1){
        return left_rotate(root);
    }
    else if(balance == 2 && root->right->ballance == -1){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }


    return root;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        string input_1;
        cin >> input_1;
        head = insert(input_1, head, count);
    }
    cout << count;
    return 0;
}
