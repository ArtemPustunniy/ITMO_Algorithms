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

Node *head = nullptr;

Node *create(vector<int> &vect, int &i, int bound){
    if (i == vect.size() || vect[i] >= bound){
        return nullptr;
    }
    Node *root = new Node(vect[i++]);
    root->left = create(vect, i, root->elem);
    root->right = create(vect, i, bound);
    return root;
}

void show_inorder(struct Node * root, vector<int> &get_inorder){
    if (root != nullptr){
        show_inorder(root->left, get_inorder);
        get_inorder.push_back(root->elem);
        show_inorder(root->right, get_inorder);
    }
}

void show_postorder(struct Node * root, vector<int> &get_postorder){
    if (root != nullptr){
        show_postorder(root->left, get_postorder);
        show_postorder(root->right, get_postorder);
        //cout << root->elem << " ";
        get_postorder.push_back(root->elem);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int input_pre;
        cin >> input_pre;
        preorder.push_back(input_pre);
    }

    for (int i = 0; i < n; i++){
        int input_in;
        cin >> input_in;
        inorder.push_back(input_in);
    }

    for (int i = 0; i < n; i++){
        int input_post;
        cin >> input_post;
        postorder.push_back(input_post);
    }

    int j = 0;
    head = create(preorder, j, INT_MAX);
    vector<int> get_inorder;
    vector <int> get_postorder;
    show_inorder(head, get_inorder);
    show_postorder(head, get_postorder);

    bool flug = true;
    if (head){
        for (int i = 0; i < n; i++){
            if (inorder[i] == get_inorder[i] && postorder[i] == get_postorder[i]){
            } else{
                flug = false;
                break;
            }
        }
        if (flug){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
    }
    else{
        cout << "NO";
    }

    return 0;
}
