
#include <iostream>
using namespace std;

class HeapSort {
    int arr[100], n;

public:
    void input() {
        cout << "Enter size: ";
        cin >> n;

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void heapify(int n, int i) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(n, largest);
        }
    }

    void sort() {

        // Build Max Heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(n, i);
        }

        // Extract elements
        for (int i = n - 1; i > 0; i--) {

            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(i, 0);
        }
    }

    void display() {
        cout << "Sorted array: ";

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    HeapSort h;

    h.input();
    h.sort();
    h.display();

    return 0;
}
