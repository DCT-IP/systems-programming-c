# Process Systems, Scheduling & Hardware Emulation (/Process-and-OS)

This module explores the mechanics of operating system kernels, task scheduling algorithms, and high-fidelity software simulations of micro-architectural hardware components. It bridges the gap between hardware execution and POSIX-compliant software isolation.

---

# Core Concepts Covered & Implemented

### 1. Low-Level Kernel Interfaces & Tasks
* [X] System Calls & File Descriptors: Bypassing standard libraries to interact directly with the OS kernel using low-level integer descriptors and explicit primitives (open, read, write).
* [X] Task State Tracking: Designing programmatic scheduler entities using structured data models to manage execution metadata like Process IDs (PIDs), priorities, and operational states.

### 2. CPU Scheduling Simulations
* [X] First-Come, First-Served (FCFS): Simulating basic deterministic task queues to compute metrics like process turnaround and waiting times.
* [X] Round Robin (RR): Engineering pre-emptive time-sliced task queues to evaluate concurrent resource allocation strategies, mirroring the core mechanics of an RTOS scheduler.

### 3. Hardware Interface Simulation Subsystem
* [X] Memory-Mapped I/O Emulation: Modeling physical device behavior by manipulating structure layouts to simulate host-side command/status tracking.
* [X] GPIO & Event Handling: Simulating general purpose interface pins alongside synchronous tracking loops and asynchronous Interrupt Service Routines (ISRs).

### 4. Process Spawning & Control Systems
* [ ] Custom Mini-Shell: (In Development) Architecting a command-line interpreter that handles process spawning (fork), program execution space replacement (exec), and structural synchronization (wait).