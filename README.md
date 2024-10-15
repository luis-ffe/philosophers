## philosophers

The **Philosophers Project** is a classic concurrency and synchronization problem that serves as a valuable lesson in resource-sharing issues within computer science.

### Setup

Imagine five philosophers seated around a circular table, each with a plate of spaghetti and a fork in front of them. The philosophers alternate between three states: sleeping, thinking, and eating.

### Rules for Eating

A philosopher can only eat if they have two forks—one in each hand. Since the number of forks equals the number of philosophers, they must coordinate their actions to avoid conflicts and ensure everyone has access to the necessary resources.

### Objectives

- **Avoid Deadlock**: Implement a solution that prevents philosophers from getting stuck in a state of waiting indefinitely for each other.
- **Avoid Starvation**: Ensure that every philosopher eventually has the opportunity to eat, regardless of the order of turns.
- **Handle Concurrency Properly**: Design the solution with careful management of threads and processes to allow for concurrent operations without issues.

### Mandatory Part

The logic for the mandatory portion is implemented in C using threads and mutexes:
- Each philosopher is represented as a thread.
- Synchronization primitives such as mutexes are used to manage access to shared resources (the forks).
- In this part, each philosopher has a fork to their left and another to their right.

### Bonus Part

For the bonus section, the logic is implemented in C using processes and semaphores:
- Each philosopher corresponds to a separate process.
- Synchronization primitives like semaphores are employed to manage access to shared resources (the forks).
- In this scenario, the forks are positioned in the center of the table, allowing for a different method of sharing between philosophers.

This project provides an excellent opportunity to explore and understand concurrency, synchronization, and resource management in a practical context.
