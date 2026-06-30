# Pointers & Stack Frames (/memory-and-data/memory_and_pointer)

This subdirectory covers concrete visualizations of the runtime stack layout, demonstrating memory cell isolation, local execution frames, and the mechanical growth of the call stack.

---

# Key Files & Conceptual Simulations

### 1. Function Stack Frame Separation & Local Isolation (`function_stack.c`)
* Concept: Highlights how the operating system and CPU architecture allocate dedicated, isolated memory cells for every active function call.
* Implementation: Compares the precise byte memory addresses of parameters and variables declared across different scopes (`main` vs. `foo`). The output proves that arguments are passed by value via copy allocation into entirely unique memory addresses on the active stack layer.

### 2. Runtime Call Stack Growth Mechanics (`recursive_stack.c`)
* Concept: Visualizes the automatic allocation of successive stack frames moving downwards (or upwards, depending on the target processor architecture) in memory upon nested execution tracks.
* Implementation: Traces a counting recursion sequence (`recursive`) to log how the local variable frame address offsets shift dynamically with each execution depth tier. This serves as an foundational reference for tracking memory limits and recognizing stack overflow conditions in memory-constrained firmware.