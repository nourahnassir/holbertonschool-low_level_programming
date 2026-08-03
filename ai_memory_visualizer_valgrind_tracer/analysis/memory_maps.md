# Memory Maps & Behavioral Analysis

This document provides a detailed step-by-step memory analysis for the programs provided in the `programs/` directory, distinguishing between stack and heap memory, tracking variable lifetimes, and evaluating pointer aliasing.

---

## 1. Stack Memory Analysis (`stack_example.c`)

### Overview
* **Memory Region:** Stack
* **Behavior:** Local variables and stack frames are created sequentially upon function entry and automatically destroyed upon function exit (Last-In, First-Out).

### Step-by-Step Execution
1. **`main` Function Entry:** A stack frame for `main` is allocated. Local variables declared inside `main` reside here.
2. **Nested Function Call:** When a helper function is called, a new stack frame is pushed on top of `main`'s frame. 
3. **Variable Lifetime:** Once the helper function returns, its stack frame is popped, and its local variables become invalid (dangling references if pointers point to them).

---

## 2. Pointer Aliasing & Lifetime (`aliasing_example.c`)

### Overview
* **Memory Region:** Stack & Heap
* **Behavior:** Pointer aliasing occurs when multiple pointers reference the identical memory location.

### Step-by-Step Execution
1. **Pointer Assignment:** When `ptr2 = ptr1;` is executed, both pointers point to the exact same address.
2. **Modification Effect:** Any modification via `ptr2` is immediately reflected when accessed through `ptr1`.
3. **Ownership and Deallocation:** Care must be taken with dynamic memory to ensure `free()` is called exactly once to avoid double-free errors or memory leaks.

---

## 3. AI Explanation Correction Case Study

During the analysis of memory behaviors using an AI assistant, the following inaccuracy was identified and manually corrected:

* **AI Claim:** The AI incorrectly suggested that returning the address of a local automatic variable from a stack frame is safe as long as the memory hasn't been overwritten yet.
* **Why it was wrong:** This represents a classic **undefined behavior / dangling pointer** vulnerability. Once a function returns, its stack frame is invalid and subject to being overwritten by subsequent function calls. Relying on "un-overwritten" stack memory violates C safety standards.
* **Correction:** Corrected the model by explicitly stating that references to local stack variables must never escape their enclosing scope, and dynamic allocation on the Heap must be used if data needs to persist beyond function boundaries.
