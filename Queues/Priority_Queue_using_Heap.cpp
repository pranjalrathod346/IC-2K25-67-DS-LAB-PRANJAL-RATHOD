
#include <iostream>
using namespace std;

class PriorityQueue {
    int heap[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void enqueue(int value) {
        if (size == 100) {
            cout << "Priority Queue Overflow!" << endl;
            return;
        }

        int i = size;
        heap[size] = value;
        size++;

        // Move the new element upward
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }

        cout << value << " inserted successfully." << endl;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Priority Queue Underflow!" << endl;
            return;
        }

        cout << "Deleted highest priority element: "
             << heap[0] << endl;

        heap[0] = heap[size - 1];
        size--;

        // Heapify downward
        int i = 0;

        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest == i) {
                break;
            }

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        cout << "Heap elements: ";

        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
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
                pq.enqueue(value);
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
