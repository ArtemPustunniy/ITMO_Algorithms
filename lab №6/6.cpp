#include <iostream>
#include <vector>
#include <string>


enum Side {right=0, left=1};

struct Node
{
    int key;
    int height;
    Node* children[2];

    Node(int key, Node * left, Node * right) : key(key), height(1)
    {
        children[0] = left;
        children[1] = right;
    }
};

struct AVL_Tree
{
    Node * root = nullptr;

    int count_balance(Node * v)
    {
        if (v == nullptr)
        {
            return 0;
        }
        return (v->children[1] != nullptr ? v->children[1]->height : 0) -
               (v->children[0] != nullptr ? v->children[0]->height : 0);
    }

    void fix_height(Node * v)
    {
        v->height = std::max(height_left(v), height_right(v)) + 1;
    }

    int height_right(Node * v)
    {
        return v->children[1] == nullptr ? 0 : v->children[1]->height;
    }

    int height_left(Node * v)
    {
        return v->children[0] == nullptr ? 0 : v->children[0]->height;
    }

    Node * rotate(Node * v, int side)
    {
        Node * u = v->children[side == Side::left ? 1 : 0];
        v->children[side == Side::left ? 1 : 0] = u->children[side == Side::left ? 0 : 1];
        u->children[side == Side::left ? 0 : 1] = v;
        fix_height(v);
        fix_height(u);
        return u;
    }

    Node * balance(Node * v)
    {
        fix_height(v);
        if (count_balance(v) > 1)
        {

            if (count_balance(v->children[1]) < 0)
            {
                v->children[1] = rotate(v->children[1], Side::right);
            }
            return rotate(v, Side::left);
        }
        if (count_balance(v) < -1)
        {
            if (count_balance(v->children[0]) > 0)
            {
                v->children[0] = rotate(v->children[0], Side::left);
            }
            return rotate(v, Side::right);
        }
        return v;
    }

    Node * insert(Node * root, int key)
    {
        if (root == nullptr)
        {
            return new Node(key, nullptr, nullptr);
        }
        root->children[key < root->key ? 0 : 1] = insert(root->children[key < root->key ? 0 : 1], key);
        return balance(root);
    }

    Node * find_max(Node * root)
    {
        return root->children[1] == nullptr ? root : find_max(root->children[1]);
    }

    Node * remove(Node * root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (key != root->key)
        {
            root->children[key < root->key ? 0 : 1] = remove(root->children[key < root->key ? 0 : 1], key);
        }
        else
        {
            if (root->children[0] == nullptr && root->children[1] == nullptr)
            {
                return nullptr;
            }
            if (root->children[0] == nullptr)
            {
                root = root->children[1];
                return balance(root);
            }
            Node * r = find_max(root->children[0]);
            root->key = r->key;
            root->children[0] = remove(root->children[0],r->key);
        }
        return balance(root);
    }

    Node * search(Node * root, int key)
    {
        if (root == nullptr || key == root->key)
        {
            return root;
        }
        return search(root->children[key < root->key ? 0 : 1], key);
    }
};

int main(){
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    auto avl = new AVL_Tree();

    for (int i = 0; i < n; i++)
    {
        std::string cmd;
        int key;
        std::cin >> cmd >> key;
        if (cmd == "A")
        {
            if (avl->search(avl->root, key) == nullptr)
            {
                avl->root = avl->insert(avl->root, key);
            }
            std::cout << avl->count_balance(avl->root) << "\n";
        }
        if (cmd == "D")
        {
            if (avl->search(avl->root, key) != nullptr)
            {
                avl->root = avl->remove(avl->root, key);
            }
            std::cout << avl->count_balance(avl->root) << "\n";
        }
        if (cmd == "C")
        {
            std::cout << ((avl->search(avl->root, key) != nullptr) ? "Y" : "N") << "\n";
        }
    }

    return 0;
}
