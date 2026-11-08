
#include <iostream>
using namespace std;

class PriorityQueue {
    int data[5];
    int priority[5];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }

    void enqueue(int value, int p) {
        if (count == 5) {
            cout << "Priority Queue Overflow!" << endl;
            return;
        }

        data[count] = value;
        priority[count] = p;
        count++;

        cout << value << " inserted with priority " << p << endl;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Priority Queue Underflow!" << endl;
            return;
        }

        int highest = 0;

        for (int i = 1; i < count; i++) {
            if (priority[i] < priority[highest]) {
                highest = i;
            }
        }

        cout << "Deleted element: " << data[highest] << endl;

        for (int i = highest; i < count - 1; i++) {
            data[i] = data[i + 1];
            priority[i] = priority[i + 1];
        }

        count--;
    }

    void display() {
        if (count == 0) {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        cout << "\nElement\tPriority" << endl;

        for (int i = 0; i < count; i++) {
            cout << data[i] << "\t" << priority[i] << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice, value, p;

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

                cout << "Enter priority (1 = Highest): ";
                cin >> p;

                pq.enqueue(value, p);
                break;

            case 2:
                pq.dequeue();
                break;

            case 3:
                pq.display();
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
