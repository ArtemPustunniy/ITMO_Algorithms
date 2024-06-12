#include <iostream>
#include <string>

using namespace std;

struct Node {
    long long elem;
    char char_elem;
    Node *next;
    Node *pref;

    Node(char char_elem_) {
        elem = 0;
        char_elem = char_elem_;
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

    void push(char char_elem_) {
        Node *temp = new Node(char_elem_);
        temp->next = nullptr;
        temp->char_elem = char_elem_;
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

    void add_to(char letter, long long value){
        Node *temp = head;
        while (temp->next){
            if (temp->char_elem == letter){
                temp->elem+= value;
            }
            temp = temp->next;
        }
        if (letter == 'Z'){
            temp->elem+= value;
        }


    }

    void show() {
        if (head == nullptr) {
            return;
        }
        Node *tmp = head;
        while (tmp->next) {
            if (tmp->elem > 1){
                std::cout << tmp->char_elem << tmp->elem;
            }
            if (tmp->elem == 1){
                std::cout << tmp->char_elem;
            }
            tmp = tmp->next;
        }
        if (tmp->elem > 1){
            std::cout << tmp->char_elem << tmp->elem;
        }
        if (tmp->elem == 1){
            std::cout << tmp->char_elem;
        }
    }


    
};

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    string mas;
    List Lst;
    getline(cin, mas);
    char alphas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (int i = 0; i < sizeof (alphas) / sizeof (char); i++){
        Lst.push(alphas[i]);
    }
//    //Lst.show();
    int Flag = 1;
    while (Flag == 1) {
        int i = 0;
        int pos_otkr = 0;
        int pos_zakr = 0;
        long long koef = 1;
        string koef_str;
        while (i < mas.length()) {
            if (mas[i] == '(')
                pos_otkr = i;
            if (mas[i] == ')') {
                pos_zakr = i;
                if (pos_zakr - pos_otkr != 1){
                    if (isdigit(mas[i + 1])) {
                        long long koef_count = i + 1;
                        while (true) {
                            if (isdigit(mas[koef_count]) && koef_count < mas.length()) {
                                koef_str += mas.substr(koef_count, 1);
                                koef_count++;
                            } else {
                                koef = stoll(koef_str);
                                break;
                            }
                        }
                    }
                    else{
                        koef = 1;
                    }
                }
                break;
            }
            i++;
        }
        if (pos_otkr == 0 && pos_zakr == 0) {
            Flag = 0;
            break;
        } else {
            if (pos_zakr - pos_otkr == 1) {
                string low_skob_after_str;
                long long low_skob_after_count = pos_zakr + 1;
                long long counter = 0;
                while (true) {
                    if (isdigit(mas[low_skob_after_count])) {
                        low_skob_after_str += mas.substr(low_skob_after_count, 1);
                        low_skob_after_count++;
                        counter++;
                    } else {
                        break;
                    }
                }
                mas = mas.substr(0, pos_otkr) + mas.substr(pos_zakr + counter + 1, mas.length() - low_skob_after_count);
                continue;
            } else {
                string per_stroka;
                for (int j = pos_otkr + 1; j < pos_zakr; j++) {
                    if (isalpha(mas[j]) && isdigit(mas[j + 1])) {
                        string local_koef_str;
                        long long local_koef_count = j + 1;
                        while (true){
                            if (isdigit(mas[local_koef_count])){
                                local_koef_str+= mas.substr(local_koef_count, 1);
                                local_koef_count++;
                            }
                            else{
                                break;
                            }
                        }
                        string new_koef = to_string(stoll(local_koef_str) * koef);
                        per_stroka += mas[j] + new_koef;
                        continue;
                    }
                    if (isalpha(mas[j]) && isalpha(mas[j + 1])) {
                        per_stroka += mas[j] + to_string(koef);
                        continue;
                    }
                    if (isalpha(mas[j]) && mas[j + 1] == ')') {
                        per_stroka += mas[j] + to_string(koef);
                        continue;
                    }
                }
                mas = mas.substr(0, pos_otkr) + per_stroka + mas.substr(pos_zakr + koef_str.length() + 1, mas.length() - 1 - pos_zakr);
            }
        }
    }
    
    //cout <<"\n";
    for (int i = 0; i < mas.length(); i++){
        if (isalpha(mas[i]) && isdigit(mas[i + 1])){
            string output_koef_str;
            long long output_koef_count = i + 1;
            while (true){
                if (isdigit(mas[output_koef_count])){
                    output_koef_str+= mas.substr(output_koef_count, 1);
                    output_koef_count++;
                }
                else{
                    Lst.add_to(mas[i], stoll(output_koef_str));
                    break;
                }
            }
            continue;
        }
        if (isalpha(mas[i]) && isalpha(mas[i + 1])){
            Lst.add_to(mas[i], 1);
            continue;
        }
        if (isdigit(mas[i]) == false){
            Lst.add_to(mas[i], 1);
            continue;
        }
    }
    Lst.show();
    return 0;
}
