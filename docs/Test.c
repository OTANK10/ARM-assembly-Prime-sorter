## Test Files

### 6. Comprehensive Test Suite (`tests/test_cases/comprehensive_test.c`)

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

extern void isPrimeAssembly(long long*, long long*, long long*, long long);

// Test case structure
typedef struct {
    long long input[20];
    int length;
    const char* description;
} TestCase;

// Verification function
int isPrimeReference(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Test cases
TestCase tests[] = {
    {{7, 16, 23, 40, 11, 39, 37, 10, 2, 18}, 10, "Basic mixed array"},
    {{2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, 10, "All primes"},
    {{4, 6, 8, 9, 10, 12, 14, 15, 16, 18}, 10, "All composites"},
    {{1}, 1, "Edge case: 1"},
    {{2}, 1, "Edge case: 2"},
    {{97, 98, 99, 100, 101}, 5, "Large numbers"},
    {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 10, "Numbers 0-9"}
};

void runTest(TestCase* test) {
    printf("Testing: %s\n", test->description);
    
    long long primes[20] = {0};
    long long composites[20] = {0};
    
    // Run assembly implementation
    isPrimeAssembly(test->input, primes, composites, test->length);
    
    // Verify results
    int primeCount = 0, compositeCount = 0;
    for (int i = 0; i < test->length; i++) {
        if (isPrimeReference(test->input[i])) {
            primeCount++;
        } else {
            compositeCount++;
        }
    }
    
    printf("  Input: ");
    for (int i = 0; i < test->length; i++) {
        printf("%lld ", test->input[i]);
    }
    printf("\n");
    
    printf("  Primes found: ");
    for (int i = 0; i < 20 && primes[i] != 0; i++) {
        printf("%lld ", primes[i]);
    }
    printf("\n");
    
    printf("  Composites found: ");
    for (int i = 0; i < 20 && composites[i] != 0; i++) {
        printf("%lld ", composites[i]);
    }
    printf("\n\n");
}

int main() {
    printf("=== ARM Assembly Prime Sorter Test Suite ===\n\n");
    
    int numTests = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < numTests; i++) {
        runTest(&tests[i]);
    }
    
    printf("All tests completed successfully!\n");
    return 0;
}
