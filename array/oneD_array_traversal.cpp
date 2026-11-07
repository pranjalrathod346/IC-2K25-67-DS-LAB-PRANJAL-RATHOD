
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

    void display() {
        cout << "Array elements: ";

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Array a;

    a.input();
    a.display();

    return 0;
}
