#include <iostream>
#include <string>

using namespace std;


struct Node {
    int elem;
    Node *left;
    Node * right;

    Node(int elem_)
    : elem(elem_)
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
        //root->right = insert(elem_, root->right);
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

bool exists(int elem_, struct Node *root){
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

Node *search(int elem_, struct Node *root){
    if (root == nullptr || elem_ == root->elem){
        return root;
    }
    if (elem_ < root->elem){
        return search(elem_, root->left);
    }
    else{
        return search(elem_, root->right);
    }

}

Node *get_next(int elem_, struct Node *root){
    Node *current = root;
    Node *successor = nullptr;

    while (current != nullptr){
        if (current->elem > elem_){
            successor = current;
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return successor;
}

Node *get_prev(int elem_, struct Node *root){
    Node *current = root;
    Node *successor = nullptr;
    while (current != nullptr){
        if (current->elem < elem_){
            successor = current;
            current = current->right;
        }
        else{
            current = current->left;
        }
    }
    return successor;

}

void show_(struct Node * root){
    if (root != nullptr){
        cout << root->elem << " ";
        show_(root->left);
        show_(root->right);
    }
}

int main(){
    while (cin){
        string command;
        int elem;
        cin >> command >> elem;
        if (command == "insert"){
            head = insert(elem, head);
        }
        else if(command == "exists"){
            bool answer = exists(elem, head);
            if (answer == 0){
                cout << "false" << "\n";
            }
            if (answer == 1){
                cout << "true" << "\n";
            }
        }
        else if(command == "delete"){
            head = delete_Node(elem, head);
        }
        else if(command == "next"){
            Node *answer = get_next(elem, head);
            if (answer == nullptr){
                cout << "none" << "\n";
            }
            else{
                cout << answer->elem << "\n";
            }
        }
        else if(command == "prev"){
            Node *answer = get_prev(elem, head);
            if (answer == nullptr){
                cout << "none" << "\n";
            }
            else{
                cout << answer->elem << "\n";
            }
        }

    }

    //head = insert(2, head);
    //cout << head << "\n";
    //head = insert(5, head);
    //cout << head << "\n"
    //head = insert(3, head);
    //cout << head << "\n";
    //head = insert(6, head);
    //cout << head << "\n";
    //head = insert(4, head);
    //cout << head << "\n";
    //head = insert(9, head);
//    show_(head);
//    cout << "\n";
//    cout << exists(3, head) << "\n";
//    show_(head);
    return 0;
}
