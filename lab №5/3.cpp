#include <iostream>

using namespace std;

struct Node{
    int elem;
    Node *left;
    Node *right;
    int right_Count;
    Node(int elem_){
        elem = elem_;
        left = nullptr;
        right = nullptr;
        right_Count = 0;
    }
};

Node *head = nullptr;

Node *insert(int elem_, Node *root){
    if (root == nullptr){
        return new Node(elem_);
    }
    if (elem_ > root->elem){
        root->right = insert(elem_,root->right);
        root->right_Count += 1;
    }
    else if(elem_ < root->elem){
        root->left = insert(elem_,root->left);
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

void show_(struct Node * root){
    if (root != nullptr){
        show_(root->left);
        show_(root->right);
    }
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
        root->right_Count -= 1;
    }
    else if(root->left != nullptr && root->right != nullptr){
        root->elem = min_value_node(root->right)->elem;
        root->right = delete_Node(root->elem, root->right);
        root->right_Count -= 1;
    }
    else{
        if (root->left != nullptr){
            root = root->left;
        }
        else if (root->right != nullptr){
            root = root->right;
            //root->right_Count -= 1;
        }
        else{
            root = nullptr;
        }
    }
    return root;
}

int kthLargestBST(Node *root, int num){
    if (root == nullptr){
        return INT_MIN;
    }
    if (num == root->right_Count + 1){
        return root->elem;
    }
    if (num < root->right_Count + 1){
        return kthLargestBST(root->right, num);
    }
    else{
        return kthLargestBST(root->left, num - root->right_Count - 1);
    }
}

int main(){
    cin.tie(nullptr);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int command, num;
        cin >> command >> num;
        if (command == 1){
            head = insert(num, head);
//            show_(head);
//            cout << "\n";
        }
        else if(command == -1){
            head = delete_Node(num, head);
//            show_(head);
//            cout << "\n";
        }
        else if(command == 0){
            cout << kthLargestBST(head, num) << "\n";
        }

    }

    return 0;
}
