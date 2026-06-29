# C Systems & Firmware Foundations

This repository documents my engineering journey through low-level C and systems programming. It serves as the foundational bedrock required for operating systems, networking, and bare-metal embedded firmware development.

The core objective is to master how software interfaces directly with memory, hardware abstractions, and network stacks before moving on to complex microcontroller architectures, real-time operating systems (RTOS), and device drivers.

---

# Learning Progression

Memory & Bit-Manipulation ➔ File Subsystems & Serialization ➔ OS Kernel Mechanics ➔ Network Protocols ➔ Embedded Foundations

---

# Separate Engineering Projects

These are self-contained projects built to apply the modules' foundations into structural subsystems, mimicking embedded logging, flash storage mechanics, and core OS tasks.

### 1. Bitmask-Based Flag System (/memory-and-data)
* Implements precise software configuration state tracking and conditional access controls using bitwise primitives, mimicking hardware status registers.

### 2. Struct-Based Mini Database System (/File-Systems)
* Implements custom binary file parsing, relational CRUD logic, and direct record positioning via byte-offset calculations. This project simulates structured data persistence on raw flash storage media without a database engine.

### 3. Continuous Sensor Telemetry Logger (/File-Systems)
* A telemetry ingestion subsystem designed to continuously read, parse, and pack simulated real-time data from hardware sensors directly into a serialized binary format (.bin).

### 4. Deterministic CPU Schedulers (/Process-and-OS)
* Implements custom simulations for First-Come First-Served (FCFS) and Round Robin task scheduling algorithms to evaluate execution waiting and turnaround time metrics.

### 5. Custom Shell Architecture (/Process-and-OS)
* A lightweight command-line interpreter that handles raw string parsing, process isolation via fork and exec system calls, and synchronous child-state tracking via wait.

### 6. Hardware Interface Foundations (/Process-and-OS)
* A simulation suite modeling memory-mapped I/O (MMIO), register flags, GPIO pins, synchronous polling loop behavior, and asynchronous hardware interrupt service routines.

### 7. Native HTTP Web Server (/Networking-Foundation)
* A multi-stage C web server that manages network socket lifecycles, manually parses raw inbound ASCII GET requests, and delivers static landing pages.

---

# Repository Directory Structure & Broad Topics

## 1. Memory, Bitwise Architecture & Embedded Primitives (/memory-and-data)
Focuses on manual memory layout, stack behavior, and hardware register modeling using direct C primitives.

* Pointers & Stack Frames: Analyzing stack frame allocations, pointer arithmetic, dereferencing, safe heap management, and dynamic multi-dimensional array structures.
* Bitwise Manipulation: Working at the bit level using logic gates (AND, OR, XOR, NOT), bit-shifts, power-of-two checks, set-bit counting, and XOR register swapping.
* Embedded C Foundations: Enforcing hardware-state integrity using the volatile keyword, optimizing space with C structures, and utilizing explicit type-widths via stdint.h.

## 2. Storage Engineering & Serialization (/File-Systems)
Covers raw data processing, stream vs. binary file operations, and building robust host-side command-line utilities.

* Stream and Character I/O: Handling standard text inputs, character arrays, string processing, and basic file system streams.
* Binary Handling & Serialization: Writing raw data structures cleanly to disk to achieve compact, fast-loading, and predictable storage layouts.
* Command-Line Tooling: Parsing runtime parameters (argc, argv) to build functional, configurable system utilities.

## 3. Process Architecture & Hardware Simulation (/Process-and-OS)
Explores kernel interfaces, task scheduling, and software models of micro-architectural hardware behaviors.

* Kernel API Basics: Making direct system calls to the operating system kernel for core resource actions using low-level file descriptors (open, read, write).
* Shell Mechanics: Understanding low-level execution separation, environment loading, and tracking process lifecycles.
* CPU Scheduling: Simulating task scheduling algorithms to track resource efficiency, mirroring the foundational logic of Real-Time Operating System (RTOS) schedulers.
* Hardware Interface Emulation: Mimicking physical board components including memory-mapped I/O registers, GPIO pins, status loops, and interrupt service routines (ISRs).

## 4. Networking Foundations & Sockets (/Networking-Foundation)
Covers protocol stacks, socket lifecycles, and network I/O buffering from the transport layer up.

* Socket Programming: Building raw network pipelines using stateful TCP streams, connection lifecycles, and the classic client-server model.
* Application Layer Protocols: Parsing inbound HTTP stream segments and manually constructing standard HTTP-compliant payload headers.

---

# Firmware Roadmap Focus

Every module in this repository is designed to build the specific mental models required for bare-metal firmware development. Bitwise tracking translates directly to writing peripheral configuration registers, binary serialization mirrors flash memory allocation maps, hardware simulations map directly to microcontroller interrupts, and socket pipelines lay the foundation for custom industrial network protocol stacks.