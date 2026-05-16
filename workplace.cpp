// #include <iostream>

// // Global methods-----------------------------------------------------------------------------------------------------------------------
// int sumOfInt(int a, int b) {
//     while(b != 0){
//         int carry = a & b;
//         a = a ^ b;
//         b = carry << 1;
//     }
//     return a;
// }

// int subOfInt(int a, int b) {
//     b = ~b + 1;
//     int result = sumOfInt(a, b);
//     return result;
// }

// //--------------------------------------------------------------------------------------------------------------------------------------
// // Task 1: İki massiv üçün pointers vasitəsilə kalkulyator yazın və if-else istifadə etmədən, məntiq qapıları ilə ədədləri müqayisə edin.
// int compareTwoInt(int a, int b) {
//     int equal = !(a ^ b);
//     int less = subOfInt(a, b) >> 31 & 1;
//     int greater = !(equal | less);
//     std::cout << "Equal: " << (bool)equal << std::endl << "Less: " << (bool)less << std::endl << "Greater: " << (bool)greater << std::endl;
//     return 0;
// }

// int compareArrays(int* arr1, int* arr2){
//     // Qəbul edirik ki, uzunluqlar eynidir → məsələn 5 element
//     int n = 5; // burada uzunluğu ayrıca ötürmək daha düzgündür, amma sənin şərtinlə sabit qəbul edirik

//     for (int i = 0; i < n; i++) {
//         std::cout << "Comparing arr1[" << i << "]=" << arr1[i]
//                   << " and arr2[" << i << "]=" << arr2[i] << std::endl;
//         compareTwoInt(arr1[i], arr2[i]); // mövcud metoddan istifadə
//     }

//     return 0;
// }

// int main() {
//     int arr1[5] = {1, 2, 3, 4, 5};
//     int arr2[5] = {2, 1, 3, 4, 5};
//     compareArrays(arr1, arr2);
// }
#include <iostream>

struct Calculator {

    // Global methods-------------------------------------------------------------------------------------------------------------------
    int sumOfInt(int a, int b) {
        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }

    int subOfInt(int a, int b) {
        b = ~b + 1;
        int result = sumOfInt(a, b);
        return result;
    }

    // Ədədin tam hissə kökünü tapır (Newton's method ilə, float işlətmədən)
    // Mənfi ədəd üçün -1 qaytarır (xəta kimi)
    int sqrtOfInt(int n) {
        if (n < 0) {
            std::cout << "Xeta: Menfi ededin koku yoxdur." << std::endl;
            return -1;
        }
        if (n == 0 || n == 1) return n;

        int x = n;
        int result = 0;

        // Newton's method: x_new = (x + n/x) / 2 — tam ədədlərlə
        int x_new = (x + n / x) >> 1;
        while (x_new < x) {
            x = x_new;
            x_new = (x + n / x) >> 1;
        }
        result = x;

        return result;
    }

    //---------------------------------------------------------------------------------------------------------------------------------
    // Task 1: İki massiv üçün pointers vasitəsilə kalkulyator yazın və if-else istifadə etmədən, məntiq qapıları ilə ədədləri müqayisə edin.
    int compareTwoInt(int a, int b) {
        int equal   = !(a ^ b);
        int less    = subOfInt(a, b) >> 31 & 1;
        int greater = !(equal | less);
        std::cout << "Equal: "   << (bool)equal
                  << "  Less: "  << (bool)less
                  << "  Greater: " << (bool)greater << std::endl;
        return 0;
    }

    int compareArrays(int* arr1, int* arr2) {
        int n = 5;

        for (int i = 0; i < n; i++) {
            std::cout << "Comparing arr1[" << i << "]=" << arr1[i]
                      << " and arr2[" << i << "]=" << arr2[i] << std::endl;
            compareTwoInt(arr1[i], arr2[i]);
        }

        return 0;
    }

    // Massivin hər elementinin tam hissə kökünü çap edir
    void sqrtOfArray(int* arr, int n) {
        for (int i = 0; i < n; i++) {
            int root = sqrtOfInt(arr[i]);
            std::cout << "sqrt(" << arr[i] << ") = " << root << std::endl;
        }
    }
};

int main() {
    Calculator calc;

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {2, 1, 3, 4, 5};

    calc.compareArrays(arr1, arr2);

    std::cout << "\n--- Kokler (arr1) ---" << std::endl;
    calc.sqrtOfArray(arr1, 5);

    std::cout << "\n--- Kokler (arr2) ---" << std::endl;
    calc.sqrtOfArray(arr2, 5);

    return 0;
}