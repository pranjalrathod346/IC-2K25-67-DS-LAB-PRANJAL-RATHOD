
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

    void deletion() {
        int pos;

        cout << "Enter position to delete: ";
        cin >> pos;

        if (pos < 1 || pos > n) {
            cout << "Invalid position";
            return;
        }

        for (int i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        cout << "After deletion: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    Array a;
    a.input();
    a.deletion();

    return 0;
}
