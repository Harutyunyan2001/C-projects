#include <iostream>
using namespace std;

class A {
    int size;
    int* arr;
public:
    A(int size, int* arr) :size(size), arr(arr) {}

    void Bubble() {
        while (size--) {
            bool swapped = false;
            for (int i = 0; i < size; ++i) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
                if (swapped == false) {
                    break;
                }
            }
        }
    }

    void Insertion() {
        for (int i = 0; i < size; ++i) {
            int J = i - 1;
            while (J >= 0 && arr[J] > arr[J + 1]) {
                swap(arr[J], arr[J + 1]);
                J--;
            }
        }
    }

    int Min() {
        int min = arr[0];
        int minindex{};
        for (int i = 0; i < size; ++i) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    void Selection() {
        int min;
        for (int i = 0; i < size - 1; i++) {
            min = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            swap(arr[min], arr[i]);
        }
    }

};
int main()
{
    int arr[5]{ 5,4,3,2,1 };
    A a(5, arr);
    a.Selection();
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << std::endl;
    }
    

    return 0;
}
