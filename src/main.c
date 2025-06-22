#include <stdio.h>
#include <stdlib.h>

// External assembly function declaration
extern void isPrimeAssembly(long long*, long long*, long long*, long long);

// Reference C implementation for comparison
int isPrimeC(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void primeIteratorC(long long* arrayA, long long* arrayPrime, 
                   long long* arrayComposite, int length) {
    int j = 0, k = 0;
    for (int i = 0; i < length; i++) {
        if (isPrimeC(arrayA[i])) {
            arrayPrime[j++] = arrayA[i];
        } else {
            arrayComposite[k++] = arrayA[i];
        }
    }
}

void printArray(const char* name, long long* arr, int size) {
    printf("%s: ", name);
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) printf("%lld ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test array with mixed prime and composite numbers
    long long arrayA[] = {7, 16, 23, 40, 11, 39, 37, 10, 2, 18, 44, 83, 87, 5, 6, 11};
    int length = sizeof(arrayA) / sizeof(arrayA[0]);
    
    // Initialize output arrays
    long long arrayPrime[16] = {0};
    long long arrayComposite[16] = {0};
    
    printf("=== ARM Assembly Prime Number Sorter ===\n");
    printf("Input Array: ");
    for (int i = 0; i < length; i++) {
        printf("%lld ", arrayA[i]);
    }
    printf("\n\n");
    
    // Call assembly implementation
    isPrimeAssembly(arrayA, arrayPrime, arrayComposite, length);
    
    // Display results
    printArray("Prime Array elements are", arrayPrime, 16);
    printArray("Composite Array elements are", arrayComposite, 16);
    
    printf("\n=== Verification with C Implementation ===\n");
    
    // Reset arrays for C implementation
    long long arrayPrimeC[16] = {0};
    long long arrayCompositeC[16] = {0};
    
    primeIteratorC(arrayA, arrayPrimeC, arrayCompositeC, length);
    printArray("C Prime Array", arrayPrimeC, 16);
    printArray("C Composite Array", arrayCompositeC, 16);
    
    return 0;
}
