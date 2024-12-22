# 📝 miniGetLine

## 🚀 Project Goal

This project consists of implementing the `get_next_line()` function to read a line from a file descriptor. It allows you to explore advanced C programming concepts, especially the use of **static variables**.

## 🔑 Key Concepts

- **File Descriptor Handling**: Read one line at a time from a file or standard input (`stdin`).
- **Static Variables**: Use of persistent variables across function calls.
- **Memory Management**: Dynamic memory allocation and preventing memory leaks.
- **Optimized Reading**: Minimize system calls to improve performance.

## 🛠️ Main Features

- 📥 **Line-by-line reading** from a file or standard input.
- 🔄 **Repeated calls**: Each call to `get_next_line()` returns a new line until the end of the file or an error occurs.
- 🔚 **End-of-file (EOF) handling**: Return `NULL` when there are no more lines to read or if an error occurs.

## ⚙️ Prototype

```c
char *get_next_line(int fd);
```

- **Parameter**: `fd` - The file descriptor.
- **Return**:
  - The read line, including the `\n` terminator, or `NULL` if the end of the file is reached or an error occurs.

## 🧰 Bonus Features

- 📂 **Support for multiple file descriptors** using a single static variable.
- 🚀 **Optimized reading**: Efficient reading minimizing system calls and managing separate reading states for each file descriptor.

## 🚧 Restrictions

- **No libft**: Only the standard C library should be used.
- **No `lseek()`**: Do not use file offset functions.
- **No global variables**: Everything must be managed locally in the function.

## 🧑‍💻 Usage

### Compilation

To compile the project, use the following command (example with a buffer size of 42):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

### Testing

You can test the `get_next_line()` function with different file sizes and formats. Make sure the program handles errors and the end of the file properly.

## 📂 File Structure

- `get_next_line.c`: Main implementation of `get_next_line()`.
- `get_next_line_utils.c`: Utility functions for line processing.
- `get_next_line.h`: Declarations of function prototypes.
- `Makefile`: Compilation file with necessary rules.

## 👨‍🏫 Learning Outcomes

This project helped me:
- Master the use of **static variables** in C.
- Understand the importance of fine-grained **memory management** and **file descriptor** handling.
- Work on optimizing file reading in C.
