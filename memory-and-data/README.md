# Memory, Pointers & Primitives (/memory-and-data)

This module serves as the foundational exploration of hardware memory layout, pointer mechanics, and low-level bit manipulation in C, forming the baseline requirements for secure runtime environments and embedded systems architecture.

---

# Core Concepts Covered & Implemented

### 1. Architectural Memory Foundations
* [X] Pointer Arithmetic & Arrays: Working with direct raw memory address boundaries, indexing offsets, and computing reference strides.
* [X] Function Stack Frames: Tracing localized stack allocations, calling conventions, variable lifetimes, and function frame boundaries.
* [X] Dynamic Memory Allocation: Realizing runtime storage lifecycles on the heap using manual block layout controls to instantiate dynamic, row-contiguous 2D arrays.

### 2. Low-Level Bitwise Manipulation
* [X] Bitwise Primitives: Performing explicit masking operations utilizing AND, OR, XOR, and NOT logic alongside dynamic bit-shifting.
* [X] Optimization Primitives: Implementing high-performance variable tracking mechanisms like XOR-based swapping, power-of-two state evaluations, and optimized set-bit counting filters.

### 3. Firmware Infrastructure Simulations
* [X] Bitmask Flag Subsystem (Project): A standalone logic validation framework configured entirely around compact bitmasks to govern strict access privileges and system execution pipelines.
* [X] Embedded Hardware Integration: Enforcing precise memory coherence protocols using `volatile` optimizations and structured Memory-Mapped I/O register definitions.