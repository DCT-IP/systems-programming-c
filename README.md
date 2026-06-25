# C Systems Programming Journey

This repository documents my journey through C and systems programming, focusing on the foundations required for backend engineering, networking, cybersecurity, operating systems, and embedded firmware development.

The objective is to build a strong understanding of how software interacts with memory, the operating system, hardware abstractions, and networks before progressing to larger systems and firmware projects.

---

# Learning Progression

```text
Memory & Data
      ↓
File Systems
      ↓
Processes & OS
      ↓
Networking
      ↓
Embedded Foundations
```

---

# Content:

## Memory and Data

### Memory and Pointers

* Memory addresses
* Pointers and dereferencing
* Pointer arithmetic
* Arrays and pointers
* Function stack frames
* Stack vs Heap
* Dynamic memory allocation
* 2D arrays (heap-based)

### Bitwise Operations

* AND, OR, XOR, NOT
* Left and Right Shift
* Set, clear, toggle bits
* XOR swap
* Power-of-two checks
* Counting set bits
* Bitmask-based flag system (project)

### Embedded C Foundations

* volatile keyword
* stdint.h
* Structures
* Register modelling

---

## File Systems

* File I/O basics
* Binary file handling
* Structs with file storage
* Arrays and serialization
* Command-line arguments

### Projects

* Struct-based mini database system
* Sensor logger storing data in `.bin`

---

## Process and OS

* File descriptors
* Low-level system calls (`open`, `read`, `write`)
* Process creation and management

### CPU Scheduling Simulations

* First Come First Serve (FCFS)
* Round Robin

### Shell Programming

* Command parsing
* Process spawning (`fork`)
* Program execution (`exec`)
* Process synchronization (`wait`)
* Basic shell implementation

### Hardware Interface Foundations

* Register simulation
* Register flag manipulation
* Memory-Mapped I/O concepts
* GPIO simulation
* Polling simulation
* Interrupt simulation

---

## Networking Foundations

### TCP Sockets

* TCP sockets
* Client-server model
* Connection lifecycle

### HTTP Server

* Accept TCP connections
* Parse HTTP requests (GET)
* Construct valid HTTP responses
* Serve basic routes

---

# Repository Projects

### Systems Projects

* Bitmask Flag System
* Mini Database
* Sensor Logger
* FCFS Scheduler
* Round Robin Scheduler
* Mini Shell
* HTTP Server

### Embedded Foundation Projects

* Mock Register Simulation
* Register Flag Simulation
* GPIO Simulator
* Polling Simulator
* Interrupt Simulator

---

# Goal

By the completion of this repository, I aim to understand:

* Memory management
* Dynamic allocation
* Bitwise manipulation
* File systems and persistence
* Operating system interfaces
* Process creation and scheduling
* Shell fundamentals
* Network programming
* Hardware abstractions
* Embedded systems fundamentals

These concepts form the foundation for future backend, networking, security, operating systems, and embedded firmware projects.
