#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printList() {
        if (head == NULL) {
            throw runtime_error("Cannot print an empty list!");
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reversePrintList() {
        if (tail == NULL) {
            throw runtime_error("Cannot reverse print an empty list!");
        }

        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void deleteNodeFromHead() {
        if (head == NULL) {
            throw runtime_error("Cannot delete from an empty list!");
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
        delete temp;
    }

    bool isEmpty() const {
        return head == NULL;
    }
};

int main() {
    try {
        LinkedList list;
        list.addNode(1);
        list.addNode(2);
        list.addNode(3);
        list.addNode(4);
        list.addNode(5);

        list.printList();
        list.reversePrintList();

        list.deleteNodeFromHead();
        list.printList();

        LinkedList emptyList;
        emptyList.printList();

    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
