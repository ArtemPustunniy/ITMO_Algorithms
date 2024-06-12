#include <iostream>
#include <queue>
#include <vector>

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

struct insertion_Node {
    int elem;
    int left;
    int right;

    insertion_Node(int elem_, int left_, int right_)
    {
        elem = elem_;
        left = left_;
        right = right_;
    }
};


Node *head = nullptr;
insertion_Node *mas[200001];

int get_height(Node *root){
    if (root == nullptr){
        return 0;
    }
    return root->height;
}

void update_height(Node *root){
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
    //root->ballance = get_height(root->right) - get_height(root->left);

    //return root;
}

Node *left_rotate(Node *root){
    Node *temp1 = root->right;
    root->right = temp1->left;
    temp1->left = root;
    update_height(root);
    update_height(temp1);
    return temp1;
}

Node *right_rotate(Node *root){
    Node *temp1 = root->left;
    root->left = temp1->right;
    temp1->right = root;
    update_height(root);
    update_height(temp1);
    return temp1;
}

Node* insert(int elem_, struct Node *root){
    if (root == nullptr){
        return new Node(elem_);
    }
    if (elem_ < root->elem){
        root->left = insert(elem_, root->left);
    }
    else if (elem_ > root->elem){
        root->right = insert(elem_, root->right);
    }
    update_height(root);

    return root;
}

Node* insert_into_AVL(int elem_, struct Node *root){
    if (root == nullptr){
        return new Node(elem_);
    }
    if (elem_ < root->elem){
        root->left = insert_into_AVL(elem_, root->left);
    }
    else if (elem_ > root->elem){
        root->right = insert_into_AVL(elem_, root->right);
    }
    update_height(root);

    int balance = get_height(root->right) - get_height(root->left);
    if (balance == -2 && root->left->ballance > 0){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    else if(balance == -2 && root->left->ballance <= 0){
        return right_rotate(root);
    }
    else if(balance == 2 && root->right->ballance >= 0){
        return left_rotate(root);
    }
    else if(balance == 2 && root->right->ballance < 0){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    int i = 2;
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->left != nullptr && current->right != nullptr){
            cout << current->elem << " " << i++ << " " << i++ << "\n";
        }
        else if (current->left == nullptr && current->right == nullptr){
            cout << current->elem << " " << 0 << " " << 0 << "\n";
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
    }
}

void insert_levelOrderTraversal() {
    if (mas[0] == nullptr){
        return;
    }
    queue<insertion_Node*> q;
    q.push(mas[0]);

    while (!q.empty()) {
        insertion_Node* current = q.front();
        q.pop();
        head = insert(current->elem, head);

        if (current->left != 0) {
            q.push(mas[current->left - 1]);
        }
        if (current->right != 0) {
            q.push(mas[current->right - 1]);
        }
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
        auto *temp = new insertion_Node(key, left_child, right_child);
        mas[i] = temp;
    }
    insert_levelOrderTraversal();

    int value;
    cin >> value;
    head = insert_into_AVL(value, head);

    cout << n + 1 << "\n";
    levelOrderTraversal(head);

    return 0;
}


