# Taskly

A simple command-line task manager written in C++.  
Built from scratch without external libraries.

## Build

```bash
g++ -o task main.cpp
```

## Usage

```bash
./task add "Task"   
./task list               
./task delete <number>     
```

## Example

```bash
$ ./task add "Learn C++"
$ ./task add "Sleep"
$ ./task list
1. Learn C++
2. Sleep
$ ./task delete 1
$ ./task list
1. Sleep
```