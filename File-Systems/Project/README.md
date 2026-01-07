# Sensor Logger 
 - binary files based
 - will use structs as records
 - binary file's I/O
 - CLI's usage 

---

## Overall goal
 - will read a sensor's data(id, time and temperature) via CLI,
 - data will be fed into a .bin file and read from the same too,
 - ./sensor log <sensor_id> <value>
 - ./sensor read, these two function will be utilized to read data 

---

## Architecture used 

┌──────────────┐
│ Command Line │
│  Arguments   │
└──────┬───────┘
       │
       ▼
┌──────────────────┐
│ Argument Parser  │
│ (argc / argv)    │
└──────┬───────────┘
       │
       ▼
┌──────────────────┐
│ Core Operations  │
│  log / read      │
└──────┬───────────┘
       │
       ▼
┌──────────────────┐
│ File I/O Layer   │
│ (binary read/write)
└──────┬───────────┘
       │
       ▼
┌──────────────────┐
│ sensor_log.bin   │
│ (binary records) │
└──────────────────┘

---

## Sensor Struct's structure

struct
├── sensor_id   (int)
├── value       (float)
└── timestamp   (long)

---

## Additional info

 - Append only style is used to avoid corruption risk
 - Invalid usage will be then showed with the proper usage message 
 - The binary format however is platform depenedent
 - No concurrency support 
 - no indexing and deletion