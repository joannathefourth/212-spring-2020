#include <iostream>
#include <cstring>
#include <random>
#include <chrono>
#include <algorithm>

int* gen_list_unsorted(int, int, int);

void merge(int* A, int n, int mid) {

    /* Implement merge here */
    
}

void merge_sort(int* A, int n) {

    /* Implement merge sort here */

}

void merge_sort_plus(int* A, int n) {

    /* Implement improved merge sort here */

}

std::pair<int, int> partition(int* A, int lo, int hi) {

    /* Implement partition here */
    return std::make_pair(-1, -1);

}

void quicksort(int* A, int lo, int hi) {

    /* Implement quicksort here */

}

/* AUXILIARY FUNCTIONS */

/* Compares int arrays of similar length n for equality */
bool compare_arrays(int* A, int* B, int n) {
    bool success = true;
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            success = false;
            break;
        }
    }
    return success;
}


/* TEST FUNCTIONS */

void custom_test(int n) {

    /* You can write your own additional tests here if you would like */

}

bool test_merge(int n, int t) {

    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(n/20, n - (n/20));

    int mid = distribution(generator);

    int* A = gen_list_unsorted(n, -n, n);
    std::sort(A, A + mid);
    std::sort(A + mid, A + n);

    int* B = new int[n];
    std::memcpy(B, A, sizeof(int)*n);
    std::sort(B, B + n);

    merge(A, n, mid);

    bool success = compare_arrays(A, B, n);

    std::cout << "Merge ";
    std::cout << ((success) ? "successful" : "failed");
    std::cout << " on trial " << t << std::endl;

    delete [] A;
    delete [] B;

    return success;

}

bool test_merge_sort(int n, int t) {

    int* A = gen_list_unsorted(n, -n, n);
    int* B = new int[n];
    std::memcpy(B, A, sizeof(int)*n);
    std::sort(B, B + n);

    merge_sort(A, n);

    bool success = compare_arrays(A, B, n);

    std::cout << "Merge sort ";
    std::cout << ((success) ? "successful" : "failed");
    std::cout << " on trial " << t << std::endl;

    delete [] A;
    delete [] B;

    return success;

}

bool test_merge_sort_plus(int n, int t) {

    int* A = gen_list_unsorted(n, -n, n);
    int* B = new int[n];
    std::memcpy(B, A, sizeof(int)*n);
    std::sort(B, B + n);

    merge_sort_plus(A, n);

    bool success = compare_arrays(A, B, n);

    std::cout << "Merge sort plus ";
    std::cout << ((success) ? "successful" : "failed");
    std::cout << " on trial " << t << std::endl;

    delete [] A;
    delete [] B;

    return success;

}

bool test_quicksort(int n, int t) {

    int* A = gen_list_unsorted(n, -n / 4, n / 4);
    int* B = new int[n];
    std::memcpy(B, A, sizeof(int)*n);
    std::sort(B, B + n);

    quicksort(A, 0, n);

    bool success = compare_arrays(A, B, n);

    std::cout << "Quicksort ";
    std::cout << ((success) ? "successful" : "failed");
    std::cout << " on trial " << t << std::endl;

    delete [] A;
    delete [] B;

    return success;
}

// Generate a random, unsorted list
int* gen_list_unsorted(int size, int low, int high) {

    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(low, high);
    int* nlist = new int[size];
    for (int i = 0; i < size; i++) {
        nlist[i] = distribution(generator);
    }
    return nlist;
}

int main(int argc, char** argv) {

    /* Input validation */
    if (argc != 3) {
        std::cerr << "Invalid Arguments. Usage: test_type(str) input_size(int)" << std::endl;
        return 1;
    }
    int num_ttypes = 5;
    char test_types[5][16] = {"merge", "merge_sort", "merge_sort_plus", "quicksort", "custom"};
    int test_idx = -1;
    for (int i = 0; i < num_ttypes; i++) {
        if (!strcmp(argv[1], test_types[i])) {
            test_idx = i;
            break;
        }
    }
    if (test_idx == -1) {
        std::cerr << "Invalid Arguments. Possibilities for test_type are:" << std::endl;
        for (int i = 0; i < num_ttypes; i++) {
            std::cout << test_types[i] << std::endl;
        }
        return 2;
    }
    if (atoi(argv[2]) <= 0) {
        std::cerr << "Invalid Arguments. Please enter a valid number n > 0." << std::endl;
        return 3;
    }

    /* Some initialization */
    int input_size = atoi(argv[2]);

    typedef bool (*test_fn)(int, int);
    test_fn tests[4] = {test_merge, test_merge_sort, test_merge_sort_plus, test_quicksort};

    char test_names[4][19] = {"Merge", "Merge sort", "Merge sort plus", "Quicksort"};

    /* Run the chosen test */
    switch (test_idx) {
        case 0 :
        case 1 :
        case 2 :
        case 3 : {
            bool success = true;
            for (int i = 0; i < 3; i++) {
                success = success && tests[test_idx](input_size, i+1);
            }
            std::cout << test_names[test_idx];
            std::cout << ((success) ? " successful " : " failed ");
            std::cout << "for input size " << input_size << std::endl;
            break;
        }
        case 4 : {
            custom_test(input_size);
            break;
        }
    }
    return 0;
}
