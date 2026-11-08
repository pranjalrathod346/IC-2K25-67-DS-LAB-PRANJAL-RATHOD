
#include <iostream>
using namespace std;

class Deque {
    int arr[5];
    int front, rear;
    int size;

public:
    Deque() {
        front = -1;
        rear = -1;
        size = 5;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) ||
               (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque Overflow!" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (front == 0) {
            front = size - 1;
        }
        else {
            front--;
        }

        arr[front] = value;

        cout << value << " inserted at front." << endl;
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque Overflow!" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = value;

        cout << value << " inserted at rear." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow!" << endl;
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow!" << endl;
            return;
        }

        cout << "Deleted: " << arr[rear] << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear) {
                break;
            }

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main() {
    Deque d;
    int choice, value;

    do {
        cout << "\n1. Insert Front";
        cout << "\n2. Insert Rear";
        cout << "\n3. Delete Front";
        cout << "\n4. Delete Rear";
        cout << "\n5. Display";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                d.insertFront(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                d.insertRear(value);
                break;

            case 3:
                d.deleteFront();
                break;

            case 4:
                d.deleteRear();
                break;

            case 5:
                d.display();
                break;

            case 6:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 6);

    return 0;
}
