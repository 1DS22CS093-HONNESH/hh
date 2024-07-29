#include <stdio.h>

#define MAX_SIZE 10

int s[MAX_SIZE], d, n;

// Recursive function to find and print subsets
void findSubsets(int index, int currentSum, int subset[], int subsetSize) {
    if (currentSum == d) {
        printf("{");
        for (int i = 0; i < subsetSize; i++) {
            printf(" %d", subset[i]);
        }
        printf(" }\n");
        return;
    }
    if (index >= n || currentSum > d) return;

    // Include s[index]
    subset[subsetSize] = s[index];
    findSubsets(index + 1, currentSum + s[index], subset, subsetSize + 1);

    // Exclude s[index]
    findSubsets(index + 1, currentSum, subset, subsetSize);
}

int main() { 
    int subset[MAX_SIZE] = {0};

    printf("Enter number of elements (max %d):\n", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    printf("Enter the target sum:\n");
    scanf("%d", &d);

    findSubsets(0, 0, subset, 0);

    return 0;
}
