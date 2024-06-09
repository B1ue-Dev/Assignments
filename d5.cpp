#include <iostream>

/// Still working

void addarrays(float* array1, float* array2, float* result, int array_size) {
    int i = 10;
    std::cout << sizeof(i) << std::endl;
    std::cout << sizeof(*array1) << std::endl;
    std::cout << array1 << std::endl;
    std::cout << *(array1++) << std::endl;
    std::cout << *(array1 + 1);
    // std::cout << array2;
    // for (int i = 0; i > array_size; i++) {
    //     std::cout << array1;
    //     std::cout << array2;
    // }
}

int main() {
    const int array_size = 5;
    float array1[array_size] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float array2[array_size] = {6.6, 7.7, 8.8, 9.9, 10.10};
    float result[array_size];

    addarrays(array1, array2, result, array_size);

    return 0;
}
