#include <iostream>
#include <algorithm>
#include <cstring>

bool compare(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

int main() {
    const char* days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int size = sizeof(days) / sizeof(days[0]);

    std::sort(days, days + size, compare);

    for (int i = 0; i < size; i++) {
        std::cout << days[i] << std::endl;
    }

    return 0;
}
