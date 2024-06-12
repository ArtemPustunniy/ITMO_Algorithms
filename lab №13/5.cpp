#include "iostream"
#include "string"

using namespace std;

struct Node {
    string elem;
    Node *left;
    Node *right;
    int left_Count;
    Node(string elem_) {
        elem = elem_;
        left = nullptr;
        right = nullptr;
        left_Count = 0;
    }
};

Node *head = nullptr;

Node *insert(string elem_, Node *root) {
    if (root == nullptr) {
        return new Node(elem_);
    }
    if (elem_ >= root->elem) {
        root->right = insert(elem_, root->right);
    } else if (elem_ < root->elem) {
        root->left = insert(elem_, root->left);
        root->left_Count += 1;
    }
    return root;
}

Node* min_value_node(Node *root) {
    Node *temp = root;
    while (temp && temp->left != nullptr) {
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

string kthSmallestBST(Node *root, int num) {
    if (root == nullptr) {
        return "";
    }
    if (num == root->left_Count + 1) {
        return root->elem;
    }
    if (num < root->left_Count + 1) {
        return kthSmallestBST(root->left, num);
    } else {
        return kthSmallestBST(root->right, num - root->left_Count - 1);
    }
}

int main() {
    cin.tie(nullptr);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] >= 'a' and s[0] <= 'z') {
            head = insert(s, head);
        } else {
            int k = stoi(s);

            cout << kthSmallestBST(head, k) << "\n";
        }
    }

    return 0;
}
