# Dining Philosophers

A multithreaded program simulation of the classic dining philosophers problem, illustrating synchronization and deadlock avoidance in concurrent programming.

## Overview

The Dining Philosophers program simulates a scenario where a fixed number of philosophers sit around a dining table, and they must share resources (forks) to eat. The challenge is to implement a solution that avoids deadlock and starvation, ensuring fair access to resources.

## Usage

Compile the program and run it with the number of philosophers, the time to die, the tie to eat, the time to sleep and the number of time each philosophers must eat(optional argument) :

```
make
./philo 20 410 100 100 
```
or 
```
make
./philo 20 410 100 100 5
```
## Subject

[philosophers.en.subject.pdf](https://github.com/AK7iwi/Philosophers/files/14182171/philosophers.en.subject.pdf)
