# Storage Engineering & Serialization (/File-Systems)

This module explores low-level data persistence, streaming mechanisms, and binary serialization techniques in C, laying the groundwork for resource-conscious firmware storage structures and lightweight database architectures.

---

# Core Concepts Covered & Implemented

### 1. File Handling & Stream Infrastructure
* [X] File Basics & Stream I/O: Navigating file pointer streams, managing standard descriptors, and handling text-based processing fields.
* [X] Binary Files & Raw Streams: Reading and writing bit-exact raw data blocks directly to storage media using precise element block boundaries.
* [X] Structure & Array Serialization: Persisting composite C structures and multi-record arrays to disk while preserving exact internal memory layout configurations.
* [X] Command-Line Tooling Interface: Interfacing with operating system runtime environments via argument vectors (argc, argv) to drive runtime persistence flags.

### 2. Standalone Storage Engineering Projects
* [X] Struct-Based Mini-Database Subsystem (Project): A compact binary data manager implementing memory-offset structural CRUD actions to emulate transactional records without external database dependency.
* [X] Continuous Sensor Telemetry Logger (Project): A continuous data ingestion pipeline parsing mock sensor arrays directly into a packed binary stream (.bin) format to mimic bare-metal storage media allocation.