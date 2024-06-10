#include <iostream>

void addarrays(float* array1, float* array2, float* result, int array_size) {
    for (int i = 0; i < array_size; i++) {
        *(result + i) = *(array1 + i) + *(array2 + i);
    }
}

int main() {
    const int array_size = 5;
    float array1[array_size] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float array2[array_size] = {6.6, 7.7, 8.8, 9.9, 10.10};
    float result[array_size];

    addarrays(array1, array2, result, array_size);

    for (int i = 0; i < array_size; i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}
