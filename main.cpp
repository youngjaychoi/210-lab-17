#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

Node *createNode(float value);
void addNode(Node *&head, float value);
void deleteNode(Node *&head, int entry);
void insertNode(Node *&head, float value, int entry);
void deleteList(Node *&head);
void output(Node *head);

int main() {
    Node *head = nullptr;
    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addNode(head, tmp_val);
    }
    output(head);

    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    deleteNode(head, entry);
    output(head);

    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    insertNode(head, 10000, entry);
    output(head);

    deleteList(head);
    output(head);

    return 0;
}

Node *createNode(float value) {
    Node *newVal = new Node;
    newVal->value = value;
    newVal->next = nullptr;
    return newVal;
}

void addNode(Node*& head, float value) {
    Node *newVal = createNode(value);
    newVal->next = head;
    head = newVal;
}

void deleteNode(Node*& head, int entry) {
    Node *current = head;
    Node *prev = head;

    if (entry == 1) {
        head = current->next;
        delete current;
        return;
    }

    for (int i = 0; i < (entry - 1); i++) {
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    }

    if (current) {
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}

void insertNode(Node*& head, float value, int entry) {
    Node *newnode = createNode(value);

    if (entry == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    Node *current = head;
    Node *prev = head;

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    newnode->next = current;
    prev->next = newnode;
}

void deleteList(Node*& head) {
    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}

void output(Node *head) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
