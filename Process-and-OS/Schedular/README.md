# CPU Scheduling Simulations (/Process-and-OS/Scheduler)

This subdirectory contains custom algorithmic engines designed to simulate CPU task scheduling. These implementations evaluate processor efficiency, resource allocation strategies, and execution metrics, establishing the foundational logic used by Real-Time Operating System (RTOS) schedulers.

---

# Key Files & Simulation Frameworks

### 1. Core Core Scheduling Framework (`schedular.c`)
* Concept: Demonstrates a structured task parsing system that processes process workloads over multiple states.
* Implementation: Builds a processing engine that feeds off an execution ledger (`input.txt`) and flushes timing diagnostics directly to disk (`output.txt`). It calculates individual process turnaround bounds, total waiting penalties, and overall CPU throughput.

### 2. Simultaneous Arrival Profiler (`fcfs_sametime.c`)
* Concept: Focuses on non-preemptive execution behaviors when multiple tasks claim execution context at the exact same physical timestamp.
* Implementation: Implements a strict First-Come, First-Served (FCFS) evaluation pipeline. It handles simultaneous arrival edge cases, ordering execution sequencing deterministically to profile total waiting times across identical scheduling weights.