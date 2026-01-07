# Bitmask-Based File Access Control System (C)

## Overview
This project demonstrates a simplified file access control system implemented in C
using bitmask-based flags. It models how operating systems internally store, manage,
and enforce file permissions using bitwise operations.

The project does not interact with the real filesystem; instead, it focuses on
understanding low-level permission representation and access enforcement.

---

## Permissions Model
Each permission is represented by a unique bit in an integer:

| Bit | Permission |
|----|-----------|
| 0 | Read |
| 1 | Write |
| 2 | Execute |
| 3 | Hidden |
| 4 | Locked |

Multiple permissions can be combined into a single integer using bitwise OR.

---

## Access Rules
Special rules are enforced on the permission set:
- Hidden files cannot be written to.
- Locked files cannot be read, written, or executed.

These rules are applied using bitwise masking before permissions are evaluated.

---

## How It Works
- Permissions are stored in a single integer variable.
- Bitwise OR (`|`) is used to grant permissions.
- Bitwise AND with inverted masks (`& ~`) is used to revoke permissions.
- Bitwise AND (`&`) is used to check permissions.
- Permission enforcement is handled by a dedicated function.

---

## Example
File: test.txt
Permissions: READ | EXECUTE | LOCKED
Result:
Read: Denied
Write: Denied
Execute: Denied

---

## Concepts Demonstrated
- Bitwise operators in C
- Bitmask-based flag systems
- Access control logic
- Low-level state representation
- Systems programming fundamentals

---

## Compilation
```bash
gcc src/file_access.c -o file_access
./file_access