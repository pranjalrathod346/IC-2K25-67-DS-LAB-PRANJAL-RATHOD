
#include <iostream>
using namespace std;

class RadixSort {
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

    int getMax() {
        int maximum = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] > maximum) {
                maximum = arr[i];
            }
        }

        return maximum;
    }

    void countSort(int exp) {
        int output[100];
        int count[10] = {0};

        // Count digit frequency
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        // Calculate cumulative count
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build output array
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;

            output[count[digit] - 1] = arr[i];

            count[digit]--;
        }

        // Copy output to original array
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    void sort() {
        if (n <= 0) {
            cout << "Invalid array size";
            return;
        }

        int maximum = getMax();

        for (int exp = 1; maximum / exp > 0; exp *= 10) {
            countSort(exp);
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
    RadixSort r;

    r.input();
    r.sort();
    r.display();

    return 0;
}
