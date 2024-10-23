#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 10000 + 1; // Generates a random number between 1 and 10
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the arrays: ";
    std::cin >> n;

    // Seed the random number generator with current time
    srand(time(0));

    int arr1[n], arr2[n];

    // Generate two random arrays
    generateRandomArray(arr1, n);
    generateRandomArray(arr2, n);

    // Print the first array
    std::cout << "Array 1: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // Print the second array
    // std::cout << "Array 2: ";
    // for (int i = 0; i < n; ++i) {
    //     std::cout << arr2[i] << " ";
    // }
    // std::cout << std::endl;

    return 0;
}
