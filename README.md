*This project has been created as part of the 42 curriculum by iualkhim*

<p align="center">
  <img src="./assets/get_next_line.png" alt="get_next_line 42 project badge"/>
</p>

## Description
The main goal of the `get_next_line` project is creating a function that returns one line at a time from a file descriptor. This challenge allows you to dive deeply into key Unix concepts such as **file descriptors**, the `open()`, `read()`, and `close()` system calls, memory management, and **static variables** to persist state between function calls.

The implementation handles any line length and works efficiently with large files by reading in fixed-size chunks defined by `BUFFER_SIZE` at compile time.

### Definition and Usage
The `get_next_line()` function reads from a file descriptor and returns the next line ending in `\n`, or the remaining content if EOF is reached. Returns `NULL` when there is nothing left to read or on error.

```c
char	*get_next_line(int fd);
```

### Key Concepts
| Concept | Description |
|---|---|
| File Descriptor | Integer handle used by the OS to identify an open file or I/O resource |
| `BUFFER_SIZE` | Compile-time constant that defines how many bytes are read per `read()` call |
| Static Variable | Persists the leftover buffer between consecutive calls to the function |

## Algorithm

`get_next_line` is built around a `static char *save` that persists between calls, acting as a buffer for unconsumed content from the previous read.

```
┌───────────────────────────────────────────────────┐
│                 get_next_line(fd)                 │
│                                                   │
│  static save ──► read_and_save() ──► save         │
│                                                   │
│                  save ──► extract_line() ──► line │
│                                                   │
│                  save ──► update_save() ──► save  │
│                                                   │
│                  return line                      │
└───────────────────────────────────────────────────┘
```

**1. `read_and_save(fd, save)`** — Feed the buffer  
Reads `BUFFER_SIZE` bytes at a time from `fd` and appends each chunk to `save` via `ft_strjoin`. Stops as soon as a `\n` is found in `save` (checked with `ft_strchr`) or EOF is reached.

**2. `extract_line(save)`** — Carve out the line  
Scans `save` from the start up to and including the first `\n`, then allocates and returns that slice as the line the caller receives.

**3. `update_save(save)`** — Keep the remainder  
Trims everything that was just returned from `save`, preserving only what comes after the `\n` for the next call. If nothing remains, returns `NULL` and frees the buffer.

## Helper Functions (`get_next_line_utils.c`)
| Function | Description |
|---|---|
| `ft_strjoin` | Concatenates the static buffer with each new chunk read |
| `ft_strchr` | Detects whether a `\n` is already in the buffer, stopping further reads |
| `ft_substr` | Used by both `extract_line` and `update_save` to slice the buffer |
| `ft_strlen` | String length utility |
| `ft_memcpy` | Memory copy utility used internally by `ft_strjoin` |

## Instructions

1. Clone the project:
```bash
git clone https://github.com/JuliAlchemDev/42_get_next_line.git get_next_line

cd get_next_line
```

2. Compile with a custom `BUFFER_SIZE` and run:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c -o test && ./test
```

> A `main.c` and `text.txt` are included in the repo so you can test it right away. You can change `BUFFER_SIZE` to any positive integer to observe different read chunk behaviors.

## Resources

Static Variables in C -> [GeeksForGeeks](https://www.geeksforgeeks.org/c/static-variables-in-c/) 

Input-output system calls -> [GeeksForGeeks](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/) 

You can also check my investigation and implementation process in [playground](./playground.c) 

---
**AI Usage:** I used [Claude](https://claude.ai) (Anthropic) as an AI augmentation tool throughout my learning process — breaking the project down into smaller parts before coding, discussing architecture and organization decisions, and getting guidance on documentation writing and evaluation preparation.








