
# CrisisGrid: Real-Time Disaster Relief and Emergency Resource Management System

**Team ID:** DSCPP-III-2026-T130  
**Team Name:** Crisis Coders  
**Course:** Data Structures in C (TCS-302) & Object-Oriented Programming with C++ (TCS-307)  
**Department:** Department of Computer Science & Engineering, Graphic Era (Deemed to be University), Dehradun  

---

## Overview
**CrisisGrid** is an offline, menu-driven C++ terminal application built for post-disaster emergency coordination when internet connectivity and cloud servers are unavailable[cite: 71, 92]. Using Object-Oriented Programming and custom Data Structures, it manages survivor records, medical trauma triage, relief supply dispatches, active rescue convoys, road network routing, and local file persistence[cite: 71, 92].


## Features & Data Structures Used
1. **Survivor Management (`Survivor`, `Registry` — Singly Linked List):** Registers survivors with auto-generated IDs, searches by name/ID, updates severity levels, and saves/loads records locally in `data/survivors.txt` using C++ `fstream`.
2. **Medical Triage (`PriorityQueue` — Insertion-Sorted Array):** Automatically places critical patients (Severity `5`) at the front of the queue ahead of lower-severity cases.
3. **Supply Management (`CircularQueue` — Ring Buffer):** Manages relief supply batches in FIFO order using modulo wrap-around indexing without array overflow.
4. **Rescue Convoy Tracking (`Convoy` — Linked List):** Tracks active rescue vehicles (`Ambulance`, `Rescue Van`, `Supply Truck`) and prevents duplicate dispatches[cite: 71].
5. **Dispatch Undo (`Stack` — LIFO Array Stack):** Reverts active convoy dispatches and restores vehicle availability[cite: 71].
6. **Road Network Routing (`RoadNetwork` — Adjacency Matrix & Dijkstra's Algorithm):** Models 5 junctions (`J1`–`J5`), filters out blocked roads (`0`), and computes the shortest safe route[cite: 71].

---

## Project Structure
```text
CrisisGrid_Simple/
├── src/
│   ├── main.cpp
│   ├── Survivor.h / Survivor.cpp
│   ├── Registry.h / Registry.cpp
│   ├── PriorityQueue.h / PriorityQueue.cpp
│   ├── CircularQueue.h / CircularQueue.cpp
│   ├── Convoy.h / Convoy.cpp
│   ├── Stack.h / Stack.cpp
│   └── RoadNetwork.h / RoadNetwork.cpp
├── data/
│   ├── README.txt
│   └── survivors.txt
└── README.md
