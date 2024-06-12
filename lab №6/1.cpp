#include <iostream>
#include <vector>

using namespace std;


struct Node {
    int elem;
    int left;
    int right;
    int height;
    int ballance;

    Node(int left_, int right_, int elem_){
        elem = elem_;
        left = left_;
        right = right_;
        height = 1;
        ballance = 0;
    }
};


int get_height(Node *root){
    if (root == nullptr){
        return 0;
    }
    return root->height;
}



int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<Node*> mas;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int key, left_child, right_child;
        cin >> key >> left_child >> right_child;
        Node *temp = new Node(left_child, right_child, key);
        mas.push_back(temp);
    }


    for (int i = n - 1; i >= 0; i--){
        if (mas[i]->left == 0 && mas[i]->right == 0){
            continue;
        }
        else if(mas[i]->left != 0 && mas[i]->right != 0){
            mas[i]->height = 1 + max(mas[mas[i]->left - 1]->height, mas[mas[i]->right - 1]->height);
            mas[i]->ballance = mas[mas[i]->right - 1]->height - mas[mas[i]->left - 1]->height;
        }
        else if(mas[i]->left != 0 && mas[i]->right == 0){
            mas[i]->height = 1 + mas[mas[i]->left - 1]->height;
            mas[i]->ballance = 0 - mas[mas[i]->left - 1]->height;
        }
        else if(mas[i]->left == 0 && mas[i]->right != 0){
            mas[i]->height = 1 + mas[mas[i]->right - 1]->height;
            mas[i]->ballance = mas[mas[i]->right - 1]->height;
        }
    }



    for (int i = 0; i < n; i++){
        cout << mas[i]->ballance << "\n";
    }
    return 0;
}


