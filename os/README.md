# Memory Allocation Techniques Simulator (C)

This project is a **C-based simulator** that demonstrates three classic **memory allocation techniques** used in operating systems:

- **First Fit**
- **Best Fit**
- **Worst Fit**

The program allocates processes to fixed-size memory blocks and calculates **internal fragmentation** for each allocation strategy.

---

## 📌 Features

- Simulates **First Fit**, **Best Fit**, and **Worst Fit** allocation algorithms
- Displays:
  - Process ID
  - Process size
  - Allocated block number
  - Block size
  - Internal fragmentation
- Calculates:
  - Total internal fragmentation
  - Number of successfully allocated processes
- Resets memory and processes before each algorithm for fair comparison

---

## 🧠 Concepts Covered

- Memory management in operating systems
- Fixed partition allocation
- Internal fragmentation
- Allocation strategy comparison

---



| Function Name      | Description                               |
| ------------------ | ----------------------------------------- |
| `firstFit()`       | Allocates the first suitable memory block |
| `bestFit()`        | Allocates the smallest suitable block     |
| `worstFit()`       | Allocates the largest suitable block      |
| `resetBlocks()`    | Resets memory blocks                      |
| `resetProcesses()` | Resets process allocation                 |
| `displayResults()` | Prints allocation results                 |


Notes
Maximum supported blocks and processes: 10
Memory blocks are treated as fixed-size partitions
External fragmentation is not simulated
Use Cases
Operating Systems laboratory experiments
Understanding memory allocation strategies
Comparing allocation efficiency
This project is intended for educational use.
Developed as part of an Operating Systems memory management simulation.

Contact & Profiles

Email: sanjanagrao.mys06@gmail.com

LinkedIn:www.linkedin.com/in/sanjana-g-rao-537839366

GitHub:https://github.com/sanjanagraomys06-rgb

Email:ayeshatahreem1983@gmail.com

LinkedIn:www.linkedin.com/in/ayesha-tahreem-63190a337

GitHub:https:https://github.com/ayeshatahreem2006
