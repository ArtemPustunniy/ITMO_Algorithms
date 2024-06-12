#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int elem;
    Node *left;
    Node * right;

    Node(int elem_){
        elem = elem_;
        left = nullptr;
        right = nullptr;
    }
};

Node *account_1 = nullptr;
Node *account_2 = nullptr;


Node* insert(int elem_, struct Node *root){
    if (root == nullptr){
        return new Node(elem_);
    }
    if (elem_ < root->elem){
        root->left = insert(elem_, root->left);
    }
    else{
//        if (elem_ > root->elem){
//            root->right = insert(elem_, root->right);
//        }
        root->right = insert(elem_, root->right);
    }
    return root;
}

Node* min_value_node(struct Node *root){
    Node *temp = root;
    while (temp && temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}

void add_by_inorder(struct Node * root, vector<int> &vvod){
    if (root != nullptr){
        add_by_inorder(root->left, vvod);
        vvod.push_back(root->elem);
        add_by_inorder(root->right, vvod);
    }
}

void show_preorder(struct Node * root){
    if (root != nullptr){
        show_preorder(root->left);
        show_preorder(root->right);
        cout << root->elem << " ";
    }
}

Node *merge(struct Node *main_root, struct Node *second_root){
    if (second_root != nullptr){
        merge(main_root, second_root->left);
        main_root = insert(second_root->elem, main_root);
        merge(main_root, second_root->right);
    }
    return main_root;
}

Node *delete_Node(int elem_, struct Node *root){
    if (root == nullptr){
        return root;
    }
    if (elem_ < root->elem){
        root->left = delete_Node(elem_, root->left);
    }
    else if(elem_ > root->elem){
        root->right = delete_Node(elem_, root->right);
    }
    else if(root->left != nullptr && root->right != nullptr){
        root->elem = min_value_node(root->right)->elem;
        root->right = delete_Node(root->elem, root->right);
    }
    else{
        if (root->left != nullptr){
            root = root->left;
        }
        else if (root->right != nullptr){
            root = root->right;
        }
        else{
            root = nullptr;
        }
    }
    return root;
}

int main(){
    int n;
    cin >> n;
    vector <int> output;
    for (int i = 0; i < n; i++){
        string command;
        int account, id;
        cin >> command;
        if (command == "buy"){
            cin >> account >> id;
            if (account == 1){
                account_1 = insert(id, account_1);
//                show_preorder(account_1);
//                cout << "\n";
            }
            else{
                account_2 = insert(id, account_2);
//                show_preorder(account_2);
//                cout << "\n";
            }
        }
        else if (command == "sell"){
            cin >> account >> id;
            if (account == 1){
                account_1 = delete_Node(id, account_1);
//                show_preorder(account_1);
//                cout << "\n";
            }
            else{
                account_2 = delete_Node(id, account_2);
//                show_preorder(account_2);
//                cout << "\n";
            }
        }
        else if (command == "merge"){
            account_1 = merge(account_1, account_2);
            add_by_inorder(account_1, output);
            if (output.empty()){
                continue;
            }
            for (int j = 0; j < output.size() - 1; j++){
                cout << output[j] <<" ";
            }
            cout << output[output.size() - 1] <<"\n";
            account_2 = nullptr;
            output.clear();
        }
    }
    return 0;
}
