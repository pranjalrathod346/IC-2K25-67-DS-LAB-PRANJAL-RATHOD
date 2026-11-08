
#include <iostream>
using namespace std;

class CircularQueue {
    int arr[5];
    int front, rear;
    int size;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 5;
    }

    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;

        cout << value << " inserted successfully." << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << "Deleted element: " << arr[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";

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
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}
