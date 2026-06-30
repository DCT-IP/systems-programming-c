# Hardware Interface Simulations (/Process-and-OS/hardware-interface)

This subdirectory provides low-level software emulations of micro-architectural hardware behaviors. By mimicking Memory-Mapped I/O (MMIO), register flags, and device-driver communication pipelines, these files bridge the gap between pure software logic and bare-metal firmware design.

---

# Key Files & Emulation Modules

### 1. MMIO Register Modeling (`mock_register.c` / `register_flags.c`)
* Concept: Simulates hardware control, status, and data bitfields without physical silicon.
* Implementation: Uses structural layouts and exact bitwise masks to manipulate mock registers, allowing the software to read state updates and write configurations just like an embedded processor.

### 2. General Purpose Input/Output Emulator (`gpio_simulator.c`)
* Concept: Models the pin-level electrical state transitions of a microcontroller.
* Implementation: Emulates hardware input and output pins in software, tracking input state updates and simulating output configurations.

### 3. Synchronous Status Tracking (`polling_simulator.c`)
* Concept: Demonstrates a classic block-and-check interface routine where the CPU manually queries a device status loop.
* Implementation: Implements a synchronous execution loop that continuously queries mock status registers until a specific hardware state condition is met.

### 4. Asynchronous Interrupt Line Handler (`interrupt_simulation.c`)
* Concept: Models hardware-driven, non-blocking asynchronous events that bypass standard sequential code execution.
* Implementation: Simulates a physical interrupt line triggering an Interrupt Service Routine (ISR) to handle immediate event updates asynchronously.