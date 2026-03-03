*This project has been created as part of the 42 curriculum by smariapp.*

# Philosophers 🍝

> *I never thought philosophy would be so deadly.*

## Description

The **Philosophers** project is a classic concurrency problem — the Dining Philosophers Problem — implemented in C using POSIX threads and mutexes.

A set of philosophers sit around a round table with a bowl of spaghetti in the middle. There is one fork between each pair of adjacent philosophers. To eat, a philosopher must pick up both the fork to their left and the fork to their right. After eating, they sleep, then think, and the cycle continues. A philosopher dies if they go too long without eating.

The goal is to implement a simulation where:
- No philosopher starves
- No deadlocks occur
- No data races are present
- Death is detected and reported within 10ms

### Key Concepts Covered

- **POSIX Threads** — each philosopher runs as an independent thread
- **Mutex synchronization** — forks are protected by mutexes to prevent concurrent access
- **Race condition prevention** — all shared state (death flag, meal count, timestamps) is guarded by dedicated mutexes
- **Deadlock avoidance** — fork acquisition uses a consistent lower-index-first ordering

---

## Architecture

| File | Role |
|------|------|
| `main.c` | Entry point, argument validation, initialization, and cleanup |
| `init.c` | Parameter and philosopher struct initialization, thread creation |
| `process.c` | Philosopher lifecycle: fork acquisition, eating, sleeping, thinking |
| `monitor.c` | Background thread that watches for death or full-satiation |
| `utilities.c` | Timing helpers, logging, and cleanup |
| `validation.c` | Input validation and `ft_atoi` |
| `philo.h` | Shared structs, defines, and function prototypes |

### Struct Overview

```c
t_params  // Global simulation state: timing, mutexes, flags
t_philo   // Per-philosopher state: id, last meal time, meal count, thread
```

Philosophers are stored as a **circular linked list** — each node's `next` points to its right neighbour, wrapping around to the head.

---

## Instructions

### Compilation

```bash
make
```

This produces the `philo` binary. Standard Makefile rules are available:

```bash
make clean    # Remove object files
make fclean   # Remove object files and binary
make re       # Full rebuild
make it 	  # re and clean
```

### Execution

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument | Description |
|----------|-------------|
| `number_of_philosophers` | Number of philosophers (and forks) at the table |
| `time_to_die` (ms) | Max time a philosopher can go without starting to eat before dying |
| `time_to_eat` (ms) | Time it takes to complete a meal (two forks required) |
| `time_to_sleep` (ms) | Time spent sleeping after eating |
| `number_of_times_each_philosopher_must_eat` | *(Optional)* Simulation stops once all philosophers have eaten this many times |

### Example Runs

```bash
# 5 philosophers, none should die
./philo 5 800 200 200

# 4 philosophers, none should die
./philo 4 410 200 200

# 4 philosophers, should die
./philo 4 310 200 200

# 1 philosopher, always dies (only one fork available)
./philo 1 800 200 200

# Stop after each philosopher eats 7 times
./philo 5 800 200 200 7
```

### Output Format

Every state change is printed as:

```
timestamp_in_ms philosopher_id message
```

Where `message` is one of:
- `has taken a fork`
- `is eating`
- `is sleeping`
- `is thinking`
- `dead`

---

## Design Decisions

### Deadlock Prevention
Philosophers alternate their fork pickup order based on their ID. Odd-indexed philosophers pick up their right fork first, while even-indexed philosophers pick up their left fork first. This asymmetry breaks the circular wait condition that would otherwise cause deadlock — preventing all philosophers from grabbing one fork simultaneously and waiting forever for the second. This breaks the circular wait condition that would otherwise cause deadlock.

### Even/Odd Staggering
Even-numbered philosophers (0-indexed) start with a delay equal to their eat time. This staggers the initial rush for forks, reducing contention and preventing starvation.

### Think Time Calculation
After sleeping, a philosopher waits a calculated think time before trying to eat again:

```c
par->think = (par->die - par->eat - par->sleep) / 2;
```

This keeps philosophers in a predictable rhythm and prevents any one philosopher from dominating the forks.

### Mutex Strategy

| Mutex | Protects |
|-------|----------|
| `r_d_m` | `dead` and `ready` flags |
| `full_m` | `full` flag |
| `log` | `printf` output (prevents interleaved messages) |
| `start_m` | Simulation start timestamp |
| `forks[i]` | Each individual fork |
| `philo->tlast` | Per-philosopher last-meal timestamp |
| `philo->meal` | Per-philosopher meal count |

### Monitor Thread
A dedicated monitor thread polls all philosophers every millisecond, checking:
1. Whether any philosopher has exceeded `time_to_die` since their last meal
2. Whether all philosophers have reached `eatnum` meals (if specified)

The monitor sets the `dead` or `full` flag accordingly, which causes all threads to exit cleanly on their next check.

---

## Resources

### References
- [pthread_mutex_lock man page](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [gettimeofday man page](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)

### Testing Tools
- `valgrind --tool=helgrind` — thread error and lock-order 

### AI Usage
Claude (claude.ai) was used throughout this project as a debugging and reasoning partner:

- **Debugging mutex bugs** — identifying double-locks, missing unlocks, and inconsistent lock ordering that caused hangs and deadlocks
- **Reasoning about race conditions** — reviewing shared variable accesses and validating that all reads/writes were properly guarded
- **Starvation analysis** — understanding why odd numbers of philosophers can cause one philosopher to be starved under naive even/odd scheduling
- **Readme generation** — to build the base of this readme

All AI-suggested code was reviewed, understood, and tested before inclusion.