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
        return 1;
    }

    void pop_first_without_result() {
        if (head == nullptr) {
            return;
        }
        //int result = head->elem;
        head = head->next;

    }

    void pop_last_without_result() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            head = nullptr;
            return;
        }
        tail = tail->pref;
        tail->next = nullptr;
    }


    void push_uniq(int elem_){
        Node *tmp_head = head;
        Node *tmp_tail = tail;
        if (tmp_head->elem >= tmp_tail->elem){
            if (tmp_head->elem >= elem_ && elem_ >= tmp_tail->elem){
                pop_first_without_result();
                pop_last_without_result();
                push(elem_);
                push(tmp_head->elem);
            }
            if (tmp_head->elem >= elem_ && elem_ < tmp_tail->elem){
                pop_first_without_result();
                pop_last_without_result();
                push(tmp_tail->elem);
                push(tmp_head->elem);
            }
            if (tmp_head->elem <= elem_){
                pop_first_without_result();
                pop_last_without_result();
                push(tmp_head->elem);
                push(elem_);
            }
//            if (tmp_head->elem > elem_){
//                pop_first_without_result();
//                pop_last_without_result();
//                push(elem_);
//                push(tmp_head->elem);
//            }
        }
        else{
            if (tmp_tail->elem >= elem_ && elem_ >= tmp_head->elem){
                pop_first_without_result();
                pop_last_without_result();
                push(elem_);
                push(tmp_tail->elem);
            }
            if (tmp_tail->elem >= elem_ && elem_ < tmp_head->elem){
                pop_first_without_result();
                pop_last_without_result();
                push(tmp_head->elem);
                push(tmp_tail->elem);
            }
            if (tmp_tail->elem <= elem_){
                pop_first_without_result();
                pop_last_without_result();
                push(tmp_tail->elem);
                push(elem_);
            }
//            if (tmp_tail->elem > elem_){
//                pop_first_without_result();
//                pop_last_without_result();
//                push(elem_);
//                push(tmp_head->elem);
//            }
        }
    }

};

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    List Lst;
    std::cin >> n >> m;
    int mas[n];
    for (int i = 0; i < n; i++){
        std::cin >> mas[i];
    }
    int count = 1;
    for (int i = 0; i < n; i++){
        if (count <= m){
            Lst.push(mas[i]);
            count++;
        }
        else{
            Lst.push_uniq(mas[i]);
        }
    }
    Lst.show();
    
    return 0;
}

