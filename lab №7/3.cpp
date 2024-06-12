#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct MinHeapNode{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq){
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode* root, string str, map<char, int> dict, int &n){
    if (!root)
        return;
    if (root->data != '$'){
        n += dict[root->data] * str.length();
    }
    printCodes(root->left, str + "0", dict, n);
    printCodes(root->right, str + "1", dict, n);
}

void HuffmanCodes(vector<char> data, vector<int> freq, int size, map<char, int> dict, int &n)
{
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>,
            compare>
            minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$',left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "", dict, n);
}

int main(){
    string input;
    cin >> input;
    map<char, int> dict;
    int answer = 0;
    for (char a: input){
        dict[a]++;
    }
    vector<char> litterals;
    vector<int> frequences;
    for (const auto &[a, b]: dict){
        litterals.push_back(a);
        frequences.push_back(b);
    }
    HuffmanCodes(litterals, frequences, litterals.size(), dict, answer);
    cout << answer;

    return 0;
}


