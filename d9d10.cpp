/// D9

// #include <iostream>

// int main() {
//     int a0[10], a1[10], a2[10], a3[10], a4[10], a5[10], a6[10], a7[10], a8[10], a9[10];

//     int* ap[10] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};

//     for (int j = 0; j < 10; j++) {
//         for (int k = 0; k < 10; k++) {
//             ap[j][k] = (j * 10 + k) * 10;
//         }
//     }

//     for (int j = 0; j < 10; k++) {
//         for (int k = 0; k < 10; k++) {
//             std::cout << ap[j][k] << " ";
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }

/// D10

#include <iostream>

int main() {
    const int NUMARRAYS = 10;
    const int MAXSIZE = 10;

    int* ap[NUMARRAYS];

    for (int j = 0; j < NUMARRAYS; j++) {
        *(ap + j) = new int[MAXSIZE];
    }

    for (int j = 0; j < MAXSIZE; j++) {
        for (int k = 0; k < NUMARRAYS; k++) {
            *(*(ap + j) + k) = (j * NUMARRAYS + k) * 10;
        }
    }

    for (int j = 0; j < MAXSIZE; j++) {
        for (int k = 0; k < NUMARRAYS; k++) {
            std::cout << *(*(ap + j) + k) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
