
*This project has been created as part of the 42 curriculum by cabboud.*

# Get Next Line

## Description

**Get Next Line (GNL)** is a C programming project whose goal is to implement a function that reads input **line by line** from a file descriptor.  
Each call to the function returns the next available line, including the newline character (`\n`) when present, until the end of the file is reached.

The project focuses on how to read input one line at a time, how to remember data between function calls, and how to manage memory safely in C.
It reflects real situations like reading files, logs, or user input gradually instead of all at once.

---

## Instructions

### Function Prototype

```c
char *get_next_line(int fd);
````

### Compilation

The project is compiled with a configurable buffer size using the `BUFFER_SIZE` macro:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c
```

`BUFFER_SIZE` can be set to any positive value and must not affect the correctness of the program.

### Files Structure

```
.
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── README.md
```

* `get_next_line.c`
  Contains the main `get_next_line` logic.
* `get_next_line_utils.c`
  Contains helper functions (string operations, memory handling).
* `get_next_line.h`
  Contains function prototypes and macro definitions.

### Usage Example

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## Algorithm Explanation and Justification

### Selected Approach

The algorithm is based on **incremental reading and state preservation** using a `static` variable (commonly called a *stash*).

A static variable in C keeps its value between function calls.
In this project, it is used to store leftover data that was read from the file but not yet returned as a complete line, allowing the function to continue reading correctly on the next call.

### Step-by-Step Logic

1. **Persistent Storage**
   A static buffer stores leftover data between calls, allowing the function to remember unread characters.

2. **Buffered Reading**
   The function reads chunks of data using `read()` until:

   * a newline character (`\n`) is found, or
   * the end of the file (EOF) is reached.

3. **Line Extraction**

   * If a newline exists, the line is extracted up to and including `\n`.
   * If EOF is reached without a newline, the remaining content is returned.

4. **State Update**
   Any unused data after the returned line is saved in the static buffer for the next call.

5. **Termination**
   When no data remains and EOF is reached, the function returns `NULL`.

### Justification

* **Memory-efficient**: Reads only what is necessary instead of loading the entire file.
* **Scalable**: Works with very large files.
* **Robust**: Handles partial reads, varying buffer sizes, and incomplete lines.
* **Realistic**: Mirrors how low-level I/O and streaming systems operate in production environments.

---

Here is a **ready-to-paste “Testing” section** you can add directly to your `README.md`.
It matches the `main.c` tester we wrote and is clear for **42 evaluators and recruiters**.

---

## Testing

To test the project, a simple `main.c` file is used to call `get_next_line` on test file (file.txt) and display the returned lines.

### Compilation

Compile the project together with the test file:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c
````

### Execution

Run the executable:

```bash
./a.out
```

The program will read each test file line by line and print the output, allowing verification of correct behavior in all edge cases.

### Memory Check (Optional)

To ensure there are no memory leaks, the program can be tested with Valgrind:

```bash
valgrind --leak-check=full ./a.out
```
---

## File descriptor

A file descriptor is simply a number used by the system to know where to read from or write to.
For example, 0 refers to keyboard input, 1 to screen output, 2 to error output, and any value greater than 2 usually refers to an opened file.
In this project, the file descriptor tells get_next_line which file or input stream it should read from.

---

## Resources

### Technical References

* https://man7.org/linux/man-pages/man2/read.2.html
* https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/
* https://www.geeksforgeeks.org/c/static-variables-in-c/
* https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/
* https://youtu.be/-Mt2FdJjVno?si=Z2h63bkN2uaqtznU

