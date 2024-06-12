#include <iostream>

using namespace std;

struct Node {
    long long int elem;
    Node* next;
    Node* pref;

    Node(long long int value) {
        elem = value;
        next = nullptr;
        pref = nullptr;
    }
};

class List {
public:
    Node* head;
    List() {
        head = nullptr;
    }

    void push(long long int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->pref = newNode;
            head = newNode;
        }
    }

    long long int get_high() {
        if (head == nullptr) {
            return -1;
        }
        return head->elem;
    }

    void pop_first_without_result() {
        if (head == nullptr) {
            return;
        }
        head = head->next;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

long long int Max_area(long long int *arr, long long int n) {
    List Lst;
    auto *left = new long long int[n];
    auto *right = new long long int[n];

    for (long long int i = 0; i < n; i++) {
        while (!Lst.isEmpty() && arr[Lst.get_high()] >= arr[i]) {
            Lst.pop_first_without_result();
        }

        if (Lst.isEmpty()) {
            left[i] = 0;
        } else {
            left[i] = Lst.get_high() + 1;
        }

        Lst.push(i);
    }

    while (!Lst.isEmpty()) {
        Lst.pop_first_without_result();
    }

    for (long long int i = n - 1; i >= 0; i--) {
        while (!Lst.isEmpty() && arr[Lst.get_high()] >= arr[i]) {
            Lst.pop_first_without_result();
        }

        if (Lst.isEmpty()) {
            right[i] = n - 1;
        } else {
            right[i] = Lst.get_high() - 1;
        }

        Lst.push(i);
    }

    long long int maximum = 0;
    for (long long int i = 0; i < n; i++) {
        maximum = max<long long int>(maximum, arr[i] * (right[i] - left[i] + 1));
    }

    delete []left;
    delete []right;

    return maximum;
}

int main() {
    long long int n;
    std::cin >> n;
    auto *mas = new long long int[n];
    for (long long int i = 0; i < n; i++){
        std::cin >> mas[i];
    }

    long long int answer = Max_area(mas, n);

    std::cout << answer;
    return 0;
}
