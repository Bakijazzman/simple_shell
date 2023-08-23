Project title: SIMPLE SHELL

Goal: Create a Simple Shell

Objectives: being able to explain;
How does a shell work
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?

TASKS
0. Betty would be proud
Write a beautiful code that passes the Betty checks

1. Simple shell 0.1
Write a UNIX command line interpreter.
Usage: simple_shell

2. Simple shell 0.2
Simple shell 0.1 +
Handle command lines with arguments

3. Simple shell 0.3
Simple shell 0.2 +
Handle the PATH
fork must not be called if the command doesn’t exist

4. Simple shell 0.4
Simple shell 0.3 +
Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

5. Simple shell 1.0
Simple shell 0.4 +
Implement the env built-in, that prints the current environment
