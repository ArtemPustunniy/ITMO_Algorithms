#include <iostream>


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

Node *get_Tree(int left, int right, int *mas){
    if (left > right){
        return nullptr;
    }
    int middle = (left + right) / 2;
    Node *root = new Node(mas[middle]);
    root->right = get_Tree(middle + 1, right, mas);
    root->left = get_Tree(left, middle - 1, mas);

    return root;
}


void show_(struct Node * root){
    if (root != nullptr){
        cout << root->elem << " ";
        show_(root->left);
        show_(root->right);
    }

}

int main(){
    int n;
    cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++){
        cin >> mas[i];
    }
    if (n == 1){
        cout << mas[0];
        return 0;
    }

    show_(get_Tree(0, n - 1, mas));



    return 0;
}
