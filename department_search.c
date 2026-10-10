
#include <stdio.h>
#include <string.h>

#define N 8

char departments[N][30] = {
    "Backend",
    "CEO",
    "Development",
    "Finance",
    "Frontend",
    "HR",
    "IT",
    "Testing"
};

int linearSearch(char target[], int *count) {
    *count = 0;

    for (int i = 0; i < N; i++) {
        (*count)++;

        if (strcmp(departments[i], target) == 0)
            return i;
    }

    return -1;
}

int binarySearch(char target[], int *count) {
    int low = 0, high = N - 1;
    *count = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        (*count)++;

        int result = strcmp(departments[mid], target);

        if (result == 0)
            return mid;
        else if (result < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(void) {
    char *targets[] = {"IT", "Backend", "Testing"};

    printf("Department Search Comparison\n");

    for (int i = 0; i < 3; i++) {
        int linearCount, binaryCount;

        int l = linearSearch(targets[i], &linearCount);
        int b = binarySearch(targets[i], &binaryCount);

        printf("\nTarget: %s\n", targets[i]);

        if (l != -1)
            printf("Linear Search: Found\n");
        else
            printf("Linear Search: Not found\n");

        printf("Linear comparisons: %d\n", linearCount);

        if (b != -1)
            printf("Binary Search: Found\n");
        else
            printf("Binary Search: Not found\n");

        printf("Binary comparisons: %d\n", binaryCount);
    }

    return 0;
}
