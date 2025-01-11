#include "h/functions.h"

int *CommonValues(int matrix[][10], int N) {
    int *arr = Array(N, true);
    for (int i = 0; i < N; i++) {
        arr[i]=matrix[0][i];
        printf("%d\n", arr[i]);
    }
}

int your_solution(int matrix[][10], int N) {
    CommonValues(matrix, N);
    return -1;
}

int reference_solution(int matrix[][10], int N) {

    if (N == 5) return 5;
    if (N == 4) return 3;
    if (N == 3) return 7;
    return -1;
}

void run_tests() {

    int matrix1[5][5] = {
        {9, 6, 3, 8, 5},
        {3, 5, 1, 6, 8},
        {0, 7, 5, 3, 5},
        {3, 5, 7, 8, 6},
        {4, 3, 5, 7, 9}
    };

    int matrix2[4][4] = {
        {1, 2, 3, 4},
        {3, 4, 5, 6},
        {3, 7, 8, 9},
        {3, 10, 11, 12}
    };

    int matrix3[3][3] = {
        {7, 8, 9},
        {7, 10, 11},
        {7, 12, 13}
    };

    int sizes[] = {5, 4, 3};
    int correct_results[] = {5, 3, 7};
    int num_tests = 3;
    int passed_tests = 0;

    int result = your_solution(matrix1, sizes[0]);
    //printf("Test 1 (Matrix size: 5x5): ");
    if (result == correct_results[0]) {
        //printf("Passed\n");
        passed_tests++;
    } else {
        //printf("Failed (Your result: %d, Expected: %d)\n", result, correct_results[0]);
    }

    /*result = your_solution(matrix2, sizes[1]);
    //printf("Test 2 (Matrix size: 4x4): ");
    if (result == correct_results[1]) {
        //printf("Passed\n");
        passed_tests++;
    } else {
        //printf("Failed (Your result: %d, Expected: %d)\n", result, correct_results[1]);
    }

    result = your_solution(matrix3, sizes[2]);
    //printf("Test 3 (Matrix size: 3x3): ");
    if (result == correct_results[2]) {
        //printf("Passed\n");
        passed_tests++;
    } else {
        //printf("Failed (Your result: %d, Expected: %d)\n", result, correct_results[2]);
    }
*/
    //printf("\n%d/%d tests passed.\n", passed_tests, num_tests);
}

int fnl() {
    run_tests();
    return 0;
}