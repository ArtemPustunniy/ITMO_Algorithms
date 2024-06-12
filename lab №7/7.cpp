#include <iostream>

using namespace std;

struct Base{
    int elem{};
    char char_elem{};
    int left{};
    int right{};
    int parent{};
};

void ckeck_Char(const char *mas, Base *tree, int N){
    for (int i = 1; i <= N; i++) {
        tree[i].elem = INT_MAX;
        tree[i].char_elem = mas[i];
        if(N < 2 * i){
            tree[i].left = INT_MAX;
        }
        else{
            tree[i].left = i * 2;
        }
        if(N < 2 * i + 1){
            tree[i].right = INT_MAX;
        }
        else{
            tree[i].right = i * 2 +1;
        }
        if(i == 1){
            tree[i].parent = INT_MAX;
        }
        else{
            tree[i].parent = i/2;
        }
    }
}

void check_Int(const int *mas, Base *tree, int N){
    for (int i = 1; i <= N; i++) {
        tree[i].elem = mas[i];
        tree[i].char_elem = '\0';
        if(N < 2 * i){
            tree[i].left = INT_MAX;
        }
        else{
            tree[i].left = i * 2;
        }
        if(N < 2 * i + 1){
            tree[i].right = INT_MAX;
        }
        else{
            tree[i].right = i * 2 + 1;
        }
        if(i == 1){
            tree[i].parent = INT_MAX;
        }
        else{
            tree[i].parent = i / 2;
        }
    }
}

void local_rotate(Base *tree, int index) {
    int grandParent;
    int parent;
    int VRight;
    int VLeft;
    parent  = tree[index].parent;
    if(parent == INT_MAX){
    }
    else{
        if(tree[parent].right != index){
            grandParent = tree[parent].parent;
            if(grandParent != INT_MAX && tree[grandParent].left == parent)
                tree[grandParent].left = index;
            else if(grandParent != INT_MAX && tree[grandParent].right == parent)
                tree[grandParent].right = index;
            tree[index].parent = grandParent;
            VLeft = tree[index].left;
            tree[index].left = parent;
            tree[parent].parent = index;
            tree[parent].left = VLeft;
            if(VLeft != INT_MAX)
                tree[VLeft].parent = parent;
        }
        else{
            grandParent = tree[parent].parent;
            if(grandParent != INT_MAX && tree[grandParent].left == parent)
                tree[grandParent].left = index;
            else if(grandParent != INT_MAX && tree[grandParent].right == parent)
                tree[grandParent].right = index;
            tree[index].parent = grandParent;
            VRight = tree[index].right;
            tree[index].right = parent;
            tree[parent].parent = index;
            tree[parent].right = VRight;
            if(VRight != INT_MAX)
                tree[VRight].parent = parent;
        }
    }
}

void LRVChar(Base *tree,int index, char *mas, int N, int &count_char){
    if(tree[index].left != INT_MAX)
        LRVChar(tree,tree[index].left, mas, N, count_char);
    if(tree[index].right != INT_MAX)
        LRVChar(tree,tree[index].right, mas, N, count_char);
    mas[count_char] = tree[index].char_elem;
    count_char++;
}

void LRVInt(Base *tree,int index, int *mas, int N, int &count_int){
    if(tree[index].left != INT_MAX)
        LRVInt(tree,tree[index].left, mas, N, count_int);
    if(tree[index].right != INT_MAX)
        LRVInt(tree,tree[index].right, mas, N, count_int);
    mas[count_int] = tree[index].elem;
    count_int++;
}

int main() {
    int N1;
    int Q1;
    int count_int = 1;
    int count_char = 1;
    cin >> N1 >> Q1;
    int masOfInt[N1 + 1];
    for (int i = 1; i <= N1; i++) {
        cin >> masOfInt[i];
    }

    Base treeOfInt[N1 + 1];
    check_Int(masOfInt,treeOfInt,N1);
    int q;
    for (int i = 0; i < Q1; i++) {
        cin >> q;
        local_rotate(treeOfInt, q);
    }

    int N2;
    int Q2;
    cin >> N2 >> Q2;
    char masOfChar[N2 + 1];
    for (int i = 1; i <= N2; i++) {
        cin >> masOfChar[i];
    }

    Base treeOFChar[N2 + 1];
    ckeck_Char(masOfChar,treeOFChar,N2);
    for (int i = 0; i < Q2; i++) {
        cin >> q;
        local_rotate(treeOFChar,q);
    }

    int start_char = 0;
    int start_int = 0;

    for (int i = 1; i <= N2; i++) {
        if(treeOFChar[i].parent == INT_MAX){
            start_char = i;
            break;
        }
    }

    for (int i = 1; i <= N1; i++) {
        if(treeOfInt[i].parent == INT_MAX){
            start_int = i;
            break;
        }
    }

    LRVInt(treeOfInt,start_int,masOfInt,N1, count_int);
    LRVChar(treeOFChar,start_char,masOfChar,N2, count_char);
    for (int i = 1; i <= N1; i++) {
        for (int _ = 0; _ < masOfInt[i]; _++) {
            cout << masOfChar[i];
        }
    }
    return 0;
}

