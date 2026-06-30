# Mini Database System

A lightweight binary-file database implemented entirely in C as part of my systems programming roadmap.

Rather than relying on an existing database engine, this project implements the fundamental operations required to manage persistent records using binary files and standard C file I/O.

The objective is to understand how structured data is serialized, stored, retrieved, modified, and deleted directly from disk.

---

# Objectives

- Understand binary file storage
- Work with structure serialization
- Learn sequential file processing
- Perform random-access updates using `fseek()`
- Implement CRUD operations without external libraries
- Gain intuition for how simple database engines manage persistent data

---

# Features

## Version 1

- Add Student Record
- View All Records
- Search Student by ID
- Update Student Information
- Delete Student Record

---

## Version 1.1 (Planned)

- Duplicate ID Detection
- Empty Database Handling
- Database Statistics
  - Total Students
  - Average Age
  - Youngest Student
  - Oldest Student
- Improved Error Handling
- Improved Command-Line Interface

---

# Data Model

```c
typedef struct
{
    int id;
    char name[50];
    int age;
} student;
```

Each record is stored directly in a binary file (`Student_DB.bin`) using fixed-size serialization.

---

# Project Structure

```text
mini_database/

├── student_db.c
├── Student_DB.bin
└── README.md
```

---

# Concepts Practiced

## File Handling

- fopen()
- fclose()
- fread()
- fwrite()
- fseek()
- remove()
- rename()

## Data Storage

- Binary Serialization
- Structures
- Fixed-size Records
- Sequential Search
- Random Access
- Temporary File Reconstruction

---

# CRUD Workflow

```text
User
   │
   ▼

Main Menu

   │

───────────────

Add
View
Search
Update
Delete

   │

Binary File

(Student_DB.bin)
```

---

# Learning Outcomes

This project strengthened my understanding of:

- Binary file management
- Persistent storage
- Structure serialization
- File traversal
- Random-access file updates
- Temporary-file based deletion
- Modular C program design

The techniques implemented here closely resemble the underlying principles used in simple storage engines, embedded systems, and low-level data management software.

---

# Future Improvements

- Record indexing
- Sorting and filtering
- CSV import/export
- Generic database engine
- SQL-like command parser