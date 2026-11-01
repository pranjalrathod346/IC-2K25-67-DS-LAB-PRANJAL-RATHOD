
#include <iostream>
using namespace std;

class Array {
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

    void insert() {
        int pos, value;

        cout << "Enter position: ";
        cin >> pos;

        cout << "Enter value: ";
        cin >> value;

        if (pos < 1 || pos > n + 1 || n >= 100) {
            cout << "Invalid position or array full";
            return;
        }

        for (int i = n; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos - 1] = value;
        n++;

        cout << "After insertion: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    Array a;

    a.input();
    a.insert();

    return 0;
}
5