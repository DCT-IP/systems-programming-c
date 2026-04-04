# Minimal HTTP Server (Stage 0 – Networking Foundations)

## Objective
Build a minimal HTTP server in C to understand:
- TCP socket programming
- HTTP request parsing
- Serving static content
- Basic error handling (404 Not Found)

This project forms the foundation for understanding client-server interactions and networking protocols.

---

## Features
- Accept TCP connections on a specified port (default: 8080)
- Parse HTTP GET requests
- Serve a static HTML page (`index.html`)
- Return a `404 Not Found` for unknown routes
- Sequential handling of client requests (single-client at a time)
- Optional: Multi-client handling using `fork()` or `select()`

---

## Tech Stack
- **Language:** C  
- **Networking:** TCP sockets (`sys/socket.h`)  
- **OS:** Linux / WSL / Unix-like systems  

---

## How it Works

1. **Socket Creation:** Create a TCP socket using `socket()`
2. **Binding:** Bind the socket to a port with `bind()`
3. **Listening:** Listen for incoming connections using `listen()`
4. **Accept Connection:** Accept client connections using `accept()`
5. **Parse HTTP Request:** Read the request and extract the requested path
6. **Serve Content:**  
   - Serve `index.html` if the path is `/`  
   - Return 404 page for unknown paths
7. **Close Connection:** Close the socket after serving the request

**HTTP Request Example:**
GET / HTTP/1.1
Host: localhost:8080

---

## How to Run
1. Compile the server:
```bash
gcc main.c -o http_server

```

---