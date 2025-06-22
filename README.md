# ARM-assembly Prime Number Array Sorter

This project implements a prime number detection and array sorting algorithm in ARMv8 (AArch64) assembly language. The program takes an array of integers and efficiently splits them into two separate arrays: one containing prime numbers and another containing composite numbers.

* Algorithm Overview
  
The program implements two main functions:  

isPrimeAssembly: Main iterator function that processes the input array  
isPrime: Helper function that determines if a single number is prime  

* Prime Detection Algorithm    

The primality test uses a division-based approach:  

Tests divisibility from 2 to n/2  
Uses efficient ARM assembly instructions for modulo operations  
Optimized loop structure with proper branching  

* Key ARM Assembly Techniques Used  

Register Management: Efficient use of X0-X30 registers  
Stack Operations: Proper stack frame setup and teardown  
Memory Addressing: Direct memory access for array operations  
Conditional Branching: Optimized loops and decision structures  
Procedure Calls: ABI-compliant function calls and returns  



