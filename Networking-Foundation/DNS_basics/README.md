# DNS Basics (Stage 0 – Networking Foundations)

## Objective
Understand and capture DNS queries to explain the process of hostname → IP resolution.  
This project demonstrates networking fundamentals, packet inspection, and DNS resolution flow.

---

## Key Topics (Kurose & Ross Ch. 2.5)
1. **DNS Services**
   - Maps hostnames → IP addresses
   - Email routing (MX records)
   - Aliases (CNAME)
2. **DNS Hierarchy**
   - Root → TLD → Authoritative
   - Recursive vs Iterative queries
3. **DNS Records**
| Type | Purpose |
|------|---------|
| A    | IPv4 address |
| AAAA | IPv6 address |
| CNAME | Alias to another domain |
| MX    | Mail server for domain |
| NS    | Authoritative server |
4. **Caching**
   - TTL (Time To Live) defines validity duration
5. **DNS Lookup Flow**
   - Client → Local Resolver → Root → TLD → Authoritative → IP

---

## Project Files
dns_basics/
│
├─ README.md           # Project documentation
├─ capture.pcap        # Wireshark capture of DNS query
├─ example_query.py    # python DNS lookup script
└─ images/             #screenshots of Wireshark analysis


---

## Using Wireshark for DNS Capture

1. **Install Wireshark**
   - Linux: `sudo apt install wireshark`
   - Windows / Mac: Download from https://www.wireshark.org/

2. **Start Capture**
   - Open Wireshark → Select network interface → Click **Start Capture**

3. **Generate a DNS Query**
   - Open browser → Access `www.example.com`  
   - Or run Python script:
     ```python
     import socket
     print(socket.gethostbyname("www.example.com"))
     ```

4. **Filter DNS Packets**
   - In Wireshark filter bar: `dns`
   - You’ll see queries (Standard query) and responses (Standard query response)

5. **Save Capture**
   - File → Export → Save as `capture.pcap`

6. **Analyze**
   - Identify:
     - Query type (A, AAAA, CNAME, MX)
     - Response IP
     - TTL (time-to-live)
     - Server hierarchy (Root, TLD, Authoritative)
   - Optional: Annotate packets with comments for clarity

---

## Steps to Document in GitHub

1. Include **`capture.pcap`** → shows actual packet capture  
2. Include **Python script (`example_query.py`)** → shows programmatic DNS query  
3. In README, explain:
   - **DNS query flow**: Client → Local Resolver → Root → TLD → Authoritative → IP  
   - **Record types**  
   - **Caching / TTL concept**  
   - Screenshot of Wireshark filtered view (optional, can add `images/` folder)  

---

## Key Learning Points
- Understanding DNS resolution hierarchy  
- Difference between recursive and iterative queries  
- Recognizing common DNS record types  
- Capturing and analyzing network packets using Wireshark  
- Simple programmatic DNS lookup in Python

---





