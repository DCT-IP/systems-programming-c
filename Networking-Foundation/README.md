# Networking Foundations (/Networking-Foundation)

This module builds networking protocols and application interfaces from the transport layer up. It establishes a practical understanding of socket lifecycles, data encapsulation, and buffer management, drawing architectural paradigms from standard reference sources like Beej's Guide and Kurose & Ross.

---

# Module Repository Directory Structure

Networking-Foundations/
│
├─ dns_basics/
│  ├─ example_query.py
│  └─ capture.pcap
│
├─ socket_programming/
│  ├─ tcp_echo_server.c
│  ├─ tcp_client.c
│  └─ udp_server_client.c
│
└─ http_server/
   ├─ http_server.c
   └─ index.html

---

# Core Concepts Covered & Implemented

### 1. Socket Programming & Transport Architecture
* [X] TCP Client-Server Model: Establishing stateful, reliable byte-stream transport pipelines, handling explicit socket lifecycles, and managing network connection loops.
* [X] TCP Echo Server: Handling basic concurrent buffer cycles by reflecting inbound payload packets directly back to connected clients.
* [X] UDP Client-Server Architecture: Implementing lightweight, connectionless datagram transmission pipelines where packet boundaries are preserved without connection overhead.

### 2. Application Layer & Protocol Engineering
* [X] Native HTTP Web Server: Building a multi-stage server from scratch that directly accepts raw TCP descriptors, manually parses ASCII inbound GET lines, handles static file delivery, and returns formal status codes (like 404 Not Found) for invalid routes.
* [X] Domain Name Subsystem (DNS) Basics: Utilizing reference scripts to generate real-time domain name resolution packets and capturing the raw networking handshakes via packet analysis tools (.pcap).

---

# Primary Engineering References
* Kurose & Ross — Computer Networking: A Top-Down Approach
* Beej's Guide to Network Programming
* MDN Web Docs — HTTP Protocols
* Cloudflare Learning Docs — DNS Mechanics