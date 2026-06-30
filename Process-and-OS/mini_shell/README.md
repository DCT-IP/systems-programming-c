# Custom Shell Architecture (/Process-and-OS/mini_shell)

A functional, Unix-like command-line interpreter engineered from scratch in C. This project serves as a practical, systems-level study of how operating systems isolate environment spaces, orchestrate runtime tasks, and handle standard input/output abstractions via bare-metal kernel calls.

The core objective is to transition from abstract process theory to concrete software engineering by implementing standard low-level system call lifecycles, file descriptor duplicate mappings, and inter-process communication mechanisms.

---

# Learning Objectives

* Master Process Creation: Implement precise control over process separation, parent-child synchronization, and image space replacement.
* Manipulate Low-Level I/O: Interact directly with operating system file descriptors to reroute standard interfaces.
* Engineer Multi-Stage Tasks: Implement data pipelines via kernel-managed tracking channels to pass byte streams between disconnected processes.
* Build Structural Tokenizers: Design raw string command parsers capable of formatting character buffers into distinct execution blocks.

---

# Integrated Engineering Milestones

### Core Architecture (Version 1.0 - [X] Complete)
* Interactive REPL: A continuous prompt loop reading user strings, tracking shell scope, and capturing termination parameters.
* Tokenization Engine: A clean argument string parser transforming execution arrays into null-terminated runtime bundles (argv).
* Execution Spawning: Isolating environment workspaces via the core fork allocation mechanism.
* Process Swapping: Replacing child address images using robust system execution blocks (execvp).
* Synchronous Trapping: Enforcing parent execution halts via structural wait blocks (wait/waitpid) until child signals complete.
* Built-In Command Routines: Lightweight context execution routines avoiding fork penalties (cd, pwd, exit).

### Resource Controls & Pipelines (Version 1.1 - [ ] Planned / In-Progress)
* Background Asynchronous Processing: Enabling decoupled concurrent tracking models using background operational flags (&).
* Stream File Redirection: Routing internal file table offsets to replace standard input, standard output, and append operations (<, >, >>).
* Inter-Process Communication: Setting up direct transport networks between distinct components via system pipes (|).
* Signal Handling Hooks: Overriding standard execution terminations to manage host inputs securely (Ctrl+C, Ctrl+Z).

---

# Repository Project Architecture

mini_shell/
├── shell.c       # Main Read-Evaluate-Print-Loop (REPL) engine
├── parser.c      # Buffer tokenization and argument packaging logic
├── parser.h      
├── builtins.c    # Manual host commands (cd, pwd, exit implementations)
├── builtins.h    
├── executor.c    # Low-level process forks and exec execution switches
├── executor.h    
├── utils.c       # Custom string manipulators and system diagnostics
└── utils.h       

---

# Concept Implementation Map

### Process Isolation & Lifecycles
* [X] fork(): Splitting the parent runtime frame to construct an identical, low-privilege child duplicate.
* [X] execvp(): Replacing the active child instruction layout with an explicit external system file footprint.
* [X] wait() / waitpid(): Halting parent loops to trap execution status signals returned by ending children.

### Kernel Interface Wrappers
* [X] chdir() / getcwd(): Direct environment space mutation primitives to alter working folder path markers.
* [X] perror(): Sampling system error registers to unpack readable descriptions of low-level faults.

### File Table & I/O Mapping
* [x] pipe(): Direct allocation of an un-named kernel memory ring buffer exposed as a matched pair of file indexes.
* [x] dup() / dup2(): Forcing target slot allocations in the process file table to overwrite default channels (stdin/stdout).

---

# Execution Flow Pipeline

User Keyboard Input
        │
        ▼
Read Stream Buffer
        │
        ▼
Tokenize Input String
        │
        ▼
Is Command a Built-in?
 ├─── Yes ───► Run Context Instruction Directly ──┐
 │                                                │
 └─── No                                          │
      │                                           │
      ▼                                           │
   fork() ───► [Child Space] ───► execvp()        │
      │                               │           │
 [Parent Space]                       ▼           │
      │                        External Binary    │
      ▼                               │           │
   waitpid() ◄────────────────────────┘           │
      │                                           │
      ▼                                           │
Flush Buffer & Return to Prompt ◄───────────────────┘

---

# System Architecture Relevance

Building this subsystem bridges the gap between pure standard library utilities and true kernel operations. The structural layout here directly mirrors how init systems, terminal supervisors, and embedded Linux container routines manage task hierarchies, control system loops, and route device logs across constrained software runtime spaces.