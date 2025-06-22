// isPrimeAssembly.s - ARM Assembly Implementation
// Author: Om Tank

.data
    // Global data section (if needed)

.text
.globl isPrimeAssembly

// Main function to split array into primes and composites
// Parameters: X0 = arrayA base, X1 = arrayPrime base, 
//           X2 = arrayComposite base, X3 = array length
isPrimeAssembly:
    // Save link register and set up stack frame
    SUB SP, SP, #16         // Allocate stack space
    STUR X30, [SP, #0]      // Save return address
    
    // Initialize counters and indices
    SUB X10, XZR, XZR       // i = 0 (main loop counter)
    SUB X11, XZR, XZR       // j = 0 (prime array index)
    SUB X12, XZR, XZR       // k = 0 (composite array index)
    SUB X13, XZR, XZR       // d = 0 (temp result storage)
    SUB X14, XZR, XZR       // temp = 0 (temporary storage)
    
    // Main iteration loop
    for_loop:
        SUBS X9, X3, X10    // Compare length with current index
        B.LT EXIT           // Branch if i >= length
        
        // Calculate memory address for current element
        LSL X15, X10, #3    // Multiply index by 8 (64-bit integers)
        ADD X15, X15, X0    // Add to base address
        LDUR X16, [X15, #0] // Load current array element
        
        // Prepare parameter for isPrime function
        ADD X4, X16, XZR    // Move current number to X4
        BL isPrime          // Call prime checking function
        
        // Check result and branch accordingly
        CBNZ X13, store_prime
        B store_composite
        
    store_prime:
        // Store in prime array
        LSL X15, X11, #3        // Calculate prime array offset
        ADD X15, X15, X1        // Add to prime array base
        STUR X16, [X15, #0]     // Store prime number
        ADD X11, X11, #1        // Increment prime index
        ADD X10, X10, #1        // Increment main index
        B for_loop              // Continue loop
        
    store_composite:
        // Store in composite array
        LSL X15, X12, #3        // Calculate composite array offset
        ADD X15, X15, X2        // Add to composite array base
        STUR X16, [X15, #0]     // Store composite number
        ADD X12, X12, #1        // Increment composite index
        ADD X10, X10, #1        // Increment main index
        B for_loop              // Continue loop
        
    EXIT:
        LDUR X30, [SP, #0]      // Restore return address
        ADD SP, SP, #16         // Deallocate stack space
        BR X30                  // Return to caller

// Prime checking function
// Parameter: X4 = number to check
// Returns: X13 = 1 if prime, 0 if composite
isPrime:
    // Handle edge cases (numbers < 2 are not prime)
    SUB X17, XZR, XZR       // Initialize divisor i = 0
    LSR X18, X4, #1         // Calculate n/2 for upper bound
    ADD X17, X17, #2        // Start checking from i = 2
    
    // Special case: if number is 2, it's prime
    SUBS X9, X4, #2
    B.EQ prime_found
    
    // Special case: if number < 2, it's not prime  
    SUBS X9, X4, #2
    B.LT composite_found
    
    prime_check_loop:
        SUBS X9, X17, X18   // Compare i with n/2
        B.GT prime_found    // If i > n/2, number is prime
        
        // Calculate n % i using division
        SDIV X9, X4, X17    // X9 = n / i
        MUL X9, X9, X17     // X9 = (n/i) * i  
        SUB X9, X4, X9      // X9 = n - ((n/i)*i) = n % i
        ADD X17, X17, #1    // Increment divisor
        
        CBNZ X9, prime_check_loop  // Continue if remainder != 0
        
    composite_found:
        ADD X13, XZR, XZR   // Set result to 0 (composite)
        BR X30              // Return
        
    prime_found:
        ADD X13, XZR, XZR   // Clear register
        ADD X13, X13, #1    // Set result to 1 (prime)
        BR X30              // Return
