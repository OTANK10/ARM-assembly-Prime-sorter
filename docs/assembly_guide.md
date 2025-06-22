# ARM Assembly Programming Reference

## Register Conventions (AAPCS64)

### General Purpose Registers
- **X0-X7**: Parameter/result registers
- **X8**: Indirect result register  
- **X9-X15**: Temporary registers
- **X16-X17**: Intra-procedure-call registers
- **X18**: Platform register
- **X19-X28**: Callee-saved registers
- **X29**: Frame pointer
- **X30**: Link register (LR)
- **X31/SP**: Stack pointer

### Key Instructions Used

#### Memory Operations
```assembly
LDUR X1, [X0, #offset]   // Load from memory
STUR X1, [X0, #offset]   // Store to memory
