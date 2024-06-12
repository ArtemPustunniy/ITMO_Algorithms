#include <iostream>
#include <string>
#include <queue>

using namespace std;


struct Node {
    int elem;
    Node *left;
    Node * right;
    int height;
    int ballance;

    Node(int elem_)
    {
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
    if (root->right != nullptr && root->left != nullptr){
        root->ballance = get_height(root->right) - get_height(root->left);
    }
    else if(root->right != nullptr && root->left == nullptr){
        root->ballance = get_height(root->right);
    }
    else if(root->right == nullptr && root->left != nullptr){
        root->ballance = 0 - get_height(root->left);
    }

    return root;
}

Node *left_rotate(Node *root){
    Node *temp1 = root->right;
    Node *temp2 = temp1->left;
    root->right = temp2;
    temp1->left = root;
    temp1 = update_height(temp1);
    root = update_height(root);
    return temp1;
}

Node *right_rotate(Node *root){
    Node *temp1 = root->left;
    Node *temp2 = temp1->right;
    root->left = temp2;
    temp1->right = root;
    root = update_height(root);
    temp1 = update_height(temp1);
    return temp1;
}

Node* insert(int elem_, struct Node *root, int i){
    if (root == nullptr){
        return new Node(elem_);
    }
    if (elem_ < root->elem){
        root->left = insert(elem_, root->left, i);
    }
    else{
        if (elem_ > root->elem){
            root->right = insert(elem_, root->right, i);
        }
    }
    root = update_height(root);
//
//    int balance = get_height(root->right) - get_height(root->left);
//    if (balance < - 1 && root->left->elem < elem_){
//        root->left = left_rotate(root->left);
//        return right_rotate(root);
//    }
//    else if(balance < -1 && root->left->elem > elem_){
//        return right_rotate(root);
//    }
//    else if(balance > 1 && root->right->elem < elem_){
//        return left_rotate(root);
//    }
//    else if(balance > 1 && root->right->elem > elem_){
//        root->right = right_rotate(root->right);
//        return left_rotate(root);
//    }

    return root;
}



void levelOrderTraversal(Node* root, int max_) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    int i = 2;
    int n = 1;
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->left != nullptr && current->right != nullptr){
            cout << current->elem << " " << i++ << " " << i++ << "\n";
        }
        else if (current->left == nullptr && current->right == nullptr){
            if (n == max_){
                cout << current->elem << " " << 0 << " " << 0;
            }
            else{
                cout << current->elem << " " << 0 << " " << 0 << "\n";
            }
        }
        else if (current->left != nullptr && current->right == nullptr){
            cout << current->elem << " " << i++ << " " << 0 << "\n";
        }
        else if (current->left == nullptr && current->right != nullptr){
            cout << current->elem << " " << 0 << " " << i++ << "\n";
        }

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
        n++;
    }
}


int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int key, left_child, right_child;
        cin >> key >> left_child >> right_child;
        head = insert(key, head, i);
    }
    //cout << head->right->height << "\n";
    if (head->right->ballance != -1){
        head = left_rotate(head);
    }
    else{
        head->right = right_rotate(head->right);
        head = left_rotate(head);
    }
    cout << n << "\n";
    levelOrderTraversal(head, n);

    return 0;
}

