
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

    void search() {
        int key, found = 0;

        cout << "Enter element to search: ";
        cin >> key;

        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                cout << "Element found at position " << i + 1;
                found = 1;
                break;
            }
        }

        if (found == 0) {
            cout << "Element not found";
        }
    }
};

int main() {
    Array a;
    a.input();
    a.search();

    return 0;
}

