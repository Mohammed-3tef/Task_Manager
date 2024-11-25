# Task Manager

## Overview
**Task Manager** is a C++ program that displays and manages processes running on your system. The program interacts with the `tasklist` command to retrieve and parse details about active processes, including:
- **Image Name**
- **PID (Process ID)**
- **Session Name**
- **Session ID**
- **Memory Usage**

### Features
1. Display all running processes.
2. Sort processes by:
   - Image Name
   - PID
   - Session Number
   - Memory Usage
3. Filter processes by session name (e.g., Console or Services).
4. Exit the program gracefully.

---

## How It Works
The program uses the `tasklist` command to generate a CSV file of processes, parses the file to extract process details, and provides sorting and filtering options to the user.

---

## Usage Instructions

### 1. Run the Program
Compile the program and execute it:
```bash
g++ -o TaskManager TaskManager.cpp
./TaskManager
```

### 2. Program Menu
When the program runs, you'll see the following menu:
```
Choose:
 1) Display Processes.
 2) Display Sorted Processes by Image Name.
 3) Display Sorted Processes by PID.
 4) Display Sorted Processes by Session Number.
 5) Display Sorted Processes by Memory Usage.
 6) Display Filtered Processes by Session Name.
 7) Exit Program.
```

Enter your choice to interact with the program:
- **Option 1:** Display all processes.
- **Option 2-5:** View sorted processes.
- **Option 6:** Filter processes by session name (`Console` or `Services`).
- **Option 7:** Exit the program.

---

## Example Output
Here’s an example of the program’s output when displaying processes:

```
                              The Processes are:

Image Name                    PID Session Name        Session#    Mem Usage
======================== ======== ================ =========== ============
System Idle Process             0 Services                   0          8 K
System                          4 Services                   0      3,300 K
Registry                      224 Services                   0     78,420 K
smss.exe                      712 Services                   0      1,328 K
csrss.exe                    1028 Services                   0      8,060 K
wininit.exe                  1128 Services                   0      8,780 K
csrss.exe                    1140 Console                    1      9,276 K
```

---

## Code Details

### Core Classes and Functions
- **`TaskManager` Class:** Manages all process-related operations.
    - **`displayProcess()`**: Displays all processes.
    - **`sortedByImageName()`**: Sorts by image name alphabetically.
    - **`sortedByPID()`**: Sorts by Process ID.
    - **`sortedBySessionNumber()`**: Sorts by session number.
    - **`sortedByMemoryUsage()`**: Sorts by memory usage (numerical).
    - **`filterSessionName()`**: Filters processes by session name.

- **Helper Functions:**
    - `convertMemoryUsage()`: Converts memory usage strings to integers for sorting.
    - `splitWords()`: Parses CSV file lines to extract process details.

### Dependencies
The program uses:
- `<bits/stdc++.h>` for standard C++ libraries.
- **`tasklist` command** (Windows).

---

## Requirements
- Operating System: **Windows**
- Compiler: **g++**
- The program relies on the `tasklist` command, so ensure it's available in your environment.

---

## Contributing
Contributions are welcome! If you'd like to contribute: 
1) Fork the repository.
2) Create a new branch (```git checkout -b feature-name```).
3) Commit your changes (```git commit -m 'Add feature name'```).
4) Push to the branch (```git push origin feature-name```).
5) Create a pull request.

---

## Author
- **Name:** [Mohammed Atef Abd El-Kader](https://www.linkedin.com/in/mohammed-atef-b0a408299/)
- **ID:** 20231143
- **Version:** 3.0
- **Date:** 25 Nov 2024

---

## License
This project is licensed under the MIT License. See the [LICENSE](https://github.com/Mohammed-3tef/TaskList_Command/blob/main/LICENSE) file for details.
