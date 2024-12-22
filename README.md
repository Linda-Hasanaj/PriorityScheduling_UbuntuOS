# Priority Scheduling
This project implements a Priority Scheduling algorithm in C. Priority Scheduling in a CPU scheduling algorithm that selects the process to execute based on priority. Processes with higher priority are executed before those with lower priority.

The project is developed and tested on the Ubuntu operating system.

## Features
- Implements Preemptive and Non-preemptive Priority Scheduling.
- Supports process attributes such as:
    - Process ID
    - Arrival Time
    - Burst Time
    - Priority
  - Calculates key scheduling metrics:
    - Turnaround time
    - Response time
    - Completion time

## Requirements
- Operating System: Ubuntu (or any Linux distribution)
- Compiler: GCC
- Basic understanding of CPU scheduling algorithms.

## Running the program
- Clone the repository.
- Compile the program: gcc -o PriorityScheduling PriorityScheduling.c
- Run the program: ./PriorityScheduling
