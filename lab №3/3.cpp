#include <iostream>


using namespace std;

struct Node {
    int elem;
    Node *next;
    Node *pref;

    Node(int elem_) {
        elem = elem_;
        next = nullptr;

    }
};

class List {
public:
    Node *head;
    Node *tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int elem) {
        Node *temp = new Node(elem);
        temp->next = nullptr;
        temp->elem = elem;
        if (head == nullptr) {
            temp->pref = nullptr;
            head = tail = temp;
        }
        else {
            temp->pref = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void show() {
        if (head == nullptr) {
            return;
        }
        Node *tmp = head;
        while (tmp->next) {
            std::cout << tmp->elem << " ";
            tmp = tmp->next;
        }
        std::cout << tmp->elem << " \n";
    }

    int pop_last() {
        if (head == nullptr) {
            return -1;
        }
        if (head->next == nullptr) {
            int result = head->elem;
            head = nullptr;
            return result;
        }
        int result = tail->elem;
        tail = tail->pref;
        tail->next = nullptr;
        return result;
    }

    int pop_first() {
        if (head == nullptr) {
            return -1;
        }
        int result = head->elem;
        head = head->next;
        return result;
    }
};
int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    List Lst;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        char sim;
        std::cin >> sim;
        if (sim == '+'){
            int znach;
            std::cin >> znach;
            Lst.push(znach);
        }
        else{
            std::cout << Lst.pop_last() << "\n";
        }
    }


    return 0;
}
