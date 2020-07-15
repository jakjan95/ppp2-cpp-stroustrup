/* 
Programming: Principles and Practice Using C++
Chapter 27 Exercise 14:
    Write a function that takes an array of ints as its input and finds the smallest and the largest elements. 
    It should also compute the median and mean. Use a struct holding the results as the return value.
*/
#include <stdio.h>
#include <stdlib.h>

int my_compare(const void* a, const void* b) {
    int _a = *(int*)a;
    int _b = *(int*)b;
    if (_a < _b) {
        return -1;
    } else if (_a == _b) {
        return 0;
    } else {
        return 1;
    }
}

struct Result {
    int maximal_element;
    int minimal_element;
    double median;
    double mean;
};

int calculate_median(int arr[], int sz) {
    qsort(arr, sz, sizeof(int), my_compare);

    double median = 0;
    if (sz % 2 == 0) {
        median = (double)(arr[((sz - 1) / 2)] + arr[((sz - 1) / 2) + 1]) / 2;
    } else {
        median = (double)arr[((sz - 1) / 2)];
    }
    return median;
}

struct Result* calculations(int arr[], int sz) {
    int loc_max = arr[0];
    int loc_min = arr[0];
    int total = 0;

    for (int i = 0; i < sz; i++) {
        if (loc_max < arr[i]) {
            loc_max = arr[i];
        }

        if (loc_min > arr[i]) {
            loc_min = arr[i];
        }

        total += arr[i];
    }

    struct Result* rsl = (struct Result*)valloc(sizeof(struct Result));
    rsl->maximal_element = loc_max;
    rsl->minimal_element = loc_min;
    rsl->mean = (double)total / sz;
    rsl->median = calculate_median(arr, sz);
    return rsl;
}

void print_result(struct Result* rsl) {
    printf("Min: %d  \tMax:%d \tMedian:%g \tMean:%lg \n",
           rsl->minimal_element, rsl->maximal_element, rsl->median, rsl->mean);
}

int main() {
    int array[] = {5, 4, 3, 2, 1};
    int array_size = 5;
    struct Result* calculations_result = (struct Result*)calculations(array, array_size);
    print_result(calculations_result);

    return 0;
}