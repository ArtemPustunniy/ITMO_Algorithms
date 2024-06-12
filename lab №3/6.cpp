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


    void pop_first_without_result() {
        if (head == nullptr) {
            return;
        }
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

    int waiting_head() {
        if (head == nullptr || head->next == nullptr){
            return -1;
        }
        else{
            Node *tmp = head;
            int count = 0;
            Node *tmp_start = head;
            while(tmp_start->next){
                if (tmp_start->next->elem > tmp->elem){
                    count++;
                    pop_first_without_result();
                    return count;
                }
                else {
                    tmp_start = tmp_start->next;
                    count++;
                }
            }
            if (count == 0){
                pop_first_without_result();
                return -1;
            }
            if (count == 1){
                pop_first_without_result();
                return -1;
            }
        }
    }

    int waiting_tail(int pos_elem, int it) {
        if (head == nullptr || head->next == nullptr){
            return -1;
        }
        else{
            Node *tmp = tail;
            int count = 0;
            int it_= it;
            Node *tmp_start;
            while (tmp->pref){
                if (pos_elem == it_){
                    tmp_start = tmp;
                    break;
                }
                else{
                    tmp = tmp->pref;
                    it_--;
                }
            }
            Node *tmp_go = tmp_start;
            while(tmp_go->next){
                if (tmp_go->next->elem > tmp_start->elem){
                    count++;
                    return count;
                }
                else{
                    tmp_go = tmp_go->next;
                    count++;
                }
            }
            if (count == 0){
                return -1;
            }
            if (count == 1){
                return -1;
            }
        }
    }
};

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    List Lst;
    std::cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++){
        std::cin >> mas[i];
        Lst.push(mas[i]);
    }
    int mas_answers[n];
    int mas_answers_2[n];
    int count = 0;
    for (int i = 0; i < n - 1; i++){
        if (mas[i] > mas[i + 1]){
            mas_answers_2[i] = -1;
            count++;
        }
    }
    if (count == n - 1){
        mas_answers_2[n - 1] = -1;
        for (int i = 0; i < n; i++){
            std::cout << mas_answers_2[i] << " ";
        }
        return 0;
    }
    mas_answers[0] = Lst.waiting_head();
    mas_answers[n - 1] = -1;
    for (int i = 1; i < n - 1; i++){
        if (mas[i + 1] - mas[i] == 1){
            mas_answers[i] = 1;
            Lst.pop_first_without_result();
            continue;
        }
        if (mas[i + 1] == mas[i] && mas[i - 1] != mas[i]){
            mas_answers[i] = Lst.waiting_head();
            continue;
        }
        if (mas[i + 1] == mas[i] && mas[i - 1] == mas[i] && mas_answers[i - 1] != -1){
            mas_answers[i] = mas_answers[i - 1] - 1;
            Lst.pop_first_without_result();
            continue;
        }
        if (mas[i + 1] == mas[i] && mas[i - 1] == mas[i] && mas_answers[i - 1] == -1){
            mas_answers[i] = -1;
            Lst.pop_first_without_result();
            continue;
        }
        mas_answers[i] = Lst.waiting_head();
    }
    for (int i = 0; i < n; i++){
        std::cout << mas_answers[i] << " ";
    }

    return 0;
}

