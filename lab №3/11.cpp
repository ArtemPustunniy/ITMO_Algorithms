#include <iostream>
using namespace std;


struct Node {
    Node *contact;
    Node() {
        contact = nullptr;
    }
};


int Has_Cycle(Node *head){
    Node *tortoise = head;
    Node *hair = head;
    while (true) {
        int count = 1;
        if (hair->contact == nullptr || tortoise->contact == nullptr) {
            return -1;
        }
        tortoise = tortoise->contact;
        hair = hair->contact->contact;

        if (hair == tortoise) {
            tortoise = tortoise->contact;
            while (hair != tortoise) {
                tortoise = tortoise->contact;
                count++;
            }
            return count;
        }
    }
}


int main() {

    int n;
    cin >> n;
    cin.ignore();

    Node *arr = new Node[n];

    for (int i = 0; i < n; i++){
        if (cin.peek() != '\n'){
            int vvod;
            cin >> vvod;
            if (i == vvod - 1){
                cout << -1;
                return 0;
            }
            arr[i].contact = &arr[vvod - 1];
        }
    }

    cout << Has_Cycle(&arr[0]);
    return 0;
}
