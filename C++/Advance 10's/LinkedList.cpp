#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* currentNode = head;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    void remove(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot perform remove operation." << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Element removed." << endl;
            return;
        }

        Node* prevNode = nullptr;
        Node* currentNode = head;
        while (currentNode != nullptr && currentNode->data != value) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        if (currentNode != nullptr) {
            prevNode->next = currentNode->next;
            delete currentNode;
            cout << "Element removed." << endl;
        } else {
            cout << "Element not found." << endl;
        }
    }

    bool search(int value) {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            if (currentNode->data == value) {
                return true;
            }
            currentNode = currentNode->next;
        }
        return false;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        } else {
            Node* currentNode = head;
            cout << "List: ";
            while (currentNode != nullptr) {
                cout << currentNode->data << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main() {
    LinkedList list;

    int numElements;
    cout << "Enter the number of elements to insert: ";
    cin >> numElements;

    int value;
    for (int i = 0; i < numElements; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> value;
        list.insert(value);
    }

    int numRemovals;
    cout << "Enter the number of elements to remove: ";
    cin >> numRemovals;

    for (int i = 0; i < numRemovals; i++) {
        cout << "Enter element to remove: ";
        cin >> value;
        list.remove(value);
    }

    int searchValue;
    cout << "Enter an element to search for: ";
    cin >> searchValue;

    if (list.search(searchValue)) {
        cout << "Element found in the list." << endl;
    } else {
        cout << "Element not found in the list." << endl;
    }

    list.display();

    return 0;
}
