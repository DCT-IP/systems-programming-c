# Embedded C Foundations (/memory-and-data/embedded_C)

This subdirectory contains structural simulations bridging bare-metal hardware behaviors with low-level C programming paradigms. The exercises focus on Memory-Mapped I/O (MMIO) modeling and hardware state optimization safeguards.

---

# Key Files & Conceptual Simulations

### 1. Memory-Mapped UART Peripheral Simulation (`register_struct.c`)
* Concept: Demonstrates how microcontrollers map hardware register blocks into memory using specialized C structures.
* Implementation: Simulates a standard Universal Asynchronous Receiver/Transmitter (UART) communication channel lifecycle. It leverages explicit bitwise masks over three dedicated 32-bit registers (`CTRL`, `STATUS`, `DATA`) to track state transitions—from initialization and setting busy transmission flags to clearing bits upon packet completion.

### 2. Hardware Interrupt State Flag Safeguard (`volatile_demo.c`)
* Concept: Demonstrates the critical role of the `volatile` qualifier when working with data updated outside the normal program execution flow (such as Hardware Interrupts or DMA controllers).
* Implementation: Simulates an asynchronous sensor data event handler (`sensor_interrupt`). Tagging the monitoring state flag as `volatile` informs the compiler that this variable can change unexpectedly, explicitly preventing optimization loops from caching obsolete memory values.