#include <iostream>
using namespace std;

struct Node {
    int elem;
    Node* left;
    Node* right;

    Node(int elem_)
    {
        elem = elem_;
        left = nullptr;
        right = nullptr;
    }
};


Node *head = nullptr;

Node* insert(int elem_, struct Node *root){
    if (root == nullptr){
        return new Node(elem_);
    }
    if (elem_ < root->elem){
        root->left = insert(elem_, root->left);
    }
    else{
        if (elem_ > root->elem){
            root->right = insert(elem_, root->right);
        }
    }
    return root;
}


void get_all_rights(Node* root, int *top_Level, int level) {
    if (root == nullptr) {
        return;
    }

    if (*top_Level < level) {
        cout << root->elem << " ";
        *top_Level = level;
    }

    get_all_rights(root->right, top_Level, level + 1);
    get_all_rights(root->left, top_Level, level + 1);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int enter;
        cin >> enter;
        head = insert(enter, head);
    }
//    head = insert(3, head);
//    //cout << head << "\n";
//    head = insert(2, head);
//    //cout << head << "\n";
//    head = insert(5, head);
//    //cout << head << "\n";
//    head = insert(4, head);
//    //cout << head << "\n";
//    head = insert(6, head);
//    //cout << head << "\n";
//    head = insert(9, head);


    int maxLevel = 0;
    get_all_rights(head, &maxLevel, 1);

    return 0;
}
