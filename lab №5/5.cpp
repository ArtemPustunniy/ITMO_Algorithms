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
    }
};

Node *head_first = nullptr;
Node *head_second = nullptr;
Node *head_third = nullptr;

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


Node* insert(string elem_, struct Node *root){
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

bool exists(string elem_, struct Node *root){
    if (root == nullptr){
        return false;
    }
    Node *temp = root;
    //cout << temp->right->left->elem << "\n";
    while (true){
        if (elem_ == temp->elem){
            return true;
        }
        if (temp->left == nullptr && temp->right == nullptr){
            return false;
        }
        if (elem_ < temp->elem){
            if (temp->left == nullptr){
                return false;
            }
            temp = temp->left;
        }
        else if (elem_ > temp->elem){
            if (temp->right == nullptr){
                return false;
            }
            temp = temp->right;
        }
    }
}

void show_(struct Node *root){
    if (root != nullptr){
        show_(root->left);
        cout << root->elem << " ";
        show_(root->right);
    }
}

int main(){
    int n;
    cin >> n;

    auto *first = new string[n];
    auto *second = new string[n];
    auto *third = new string[n];

    for (int i = 0; i < n; i++){
        string input_1;
        cin >> input_1;
        first[i] = input_1;
        head_first = insert(input_1, head_first);
    }
    for (int i = 0; i < n; i++){
        string input_2;
        cin >> input_2;
        second[i] = input_2;
        head_second = insert(input_2, head_second);
    }
    for (int i = 0; i < n; i++){
        string input_3;
        cin >> input_3;
        third[i] = input_3;
        head_third = insert(input_3, head_third);
    }

    int ball_1 = 0;
    int ball_2 = 0;
    int ball_3 = 0;

    for (int i = 0; i < n; i++){
        if (exists(first[i], head_second) == 0 && exists(first[i], head_third) == 0){
            ball_1 += 3;
        }
        else if(exists(first[i], head_second) == 0 && exists(first[i], head_third) == 1 || exists(first[i], head_second) == 1 && exists(first[i], head_third) == 0){
            ball_1 += 1;
        }
    }

    for (int i = 0; i < n; i++){
        if (exists(second[i], head_first) == 0 && exists(second[i], head_third) == 0){
            ball_2 += 3;
        }
        else if(exists(second[i], head_first) == 0 && exists(second[i], head_third) == 1 || exists(second[i], head_first) == 1 && exists(second[i], head_third) == 0){
            ball_2 += 1;
        }
    }

    for (int i = 0; i < n; i++){
        if (exists(third[i], head_first) == 0 && exists(third[i], head_second) == 0){
            ball_3 += 3;
        }
        else if(exists(third[i], head_first) == 0 && exists(third[i], head_second) == 1 || exists(third[i], head_first) == 1 && exists(third[i], head_second) == 0){
            ball_3 += 1;
        }
    }

    cout << ball_1 << " " << ball_2 << " " << ball_3;

    return 0;
}
