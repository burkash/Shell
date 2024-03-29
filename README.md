## ⌘ Introduction 
  - Welcome to the Operating Systems project repository for the Simple Shell project. 
    - This repository contains the collaborative work of Burhan and Abdulkadir under the supervision of Professor Elma Avdić. 
      - The project focuses on developing a simple shell application named. 

## ⎇ About the Project
  The Simple Shell project aims to create a basic command-line interface that mimics some functionalities of a Unix shell. 
  The project is a part of the Operating Systems course, providing an opportunity for students to delve into the fundamentals of operating systems and gain practical experience in system programming.

## ⌾ Simple Shell Project Outline
- Professor of the course:
 Elma Avdić
  - Authors:
 Abdulkadir Akay, Burhan Hošić

### Overview:
  - This project is a simple implementation of a shell program in C. 
A shell is a command-line interface that allows users to interact with the operating system by executing commands. 
The shell program developed here provides basic functionality similar to popular Unix/Linux shells, such as executing external commands, 
handling built-in commands, and providing a command prompt for user input.

#### **Features and command execution:**

Executes both external commands and built-in commands.
Supports external commands like rm, cat, clear, and cowsay.

Includes support for built-in commands like rm, cat, clear, and cowsay.
Handles built-in commands internally within the shell program.
User Interface:

Displays a custom command prompt for user input.
Parses user input to extract command and arguments.
Error Handling:

Provides **error handling** for various scenarios such as command not found, file not found, etc.
Ensures robustness to prevent crashes and handle errors gracefully.

#### **Running the Shell:**
  - Compile the C program. Execute the compiled binary to start the shell.
  - Enter commands at the prompt and press Enter to execute.

#### **Supported Commands:**
**External commands:** rm, cat, clear, cowsay. 
**Built-in commands:** rm, cat, clear, cowsay, exit.

#### Requirements:
  - C compiler (e.g. GCC)
  - Standard C libraries & ncurses library (for color output)

#### Notes:
This shell project is designed for educational purposes and provides a basic understanding of shell programming concepts.
Further enhancements and optimizations can be made in the future to extend its functionality and improve performance.
The project was made using JetBrains CLion IDE on a MacOS and tested on the same terminal. 

#### Project Structure - The project repository is organized as follows:
  // main - Contains the source code of the azashell. As well as documentation related to the project including this README file. 

### Materials & WebSites that were of help
* Linux man pages: https://linux.die.net/man/
* Writing a Unix Shell - [Part I](https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/), [Part II](https://indradhanush.github.io/blog/writing-a-unix-shell-part-2/), [Part III](https://indradhanush.github.io/blog/writing-a-unix-shell-part-3/).
* [Tutorial - Write a Shell in C by Stephen Brennan • 16 January 2015](https://brennan.io/2015/01/16/write-a-shell-in-c/).

## Assignment
Question 1.5.1:
What does mmap() function do?

Answer:
mmap() is a function in Unix-like operating systems, used to map files or devices into memory.It stands for "memory map".
mmap() treats files as if they are part of the computers memory, it is useful for many things like reading efficiently, writing large files or even sharing memory between processes, creating temporary files.

Question 1.5.2:
What happens during a context switch? Do we want the OS to perform many or few context switches? 

Answer:
During a context switch, operating system saves the state of the process that is currently running so that it can later resume execution from the point it saved.Then it loads the saved state of another process that is ready to run.
It is mainly for multitasking, where multiple processes share the CPU
3 steps that typically happen during a context switch
1. Save Context: the operating system saves the current state of th CPU
2. Loads Context: the operating system retrieves the saved state of the next process that is ready to run.
3. Switch Execution: The operating system updates its internal data structures to reflect the change in the currently running process.

Question 1.5.3:
What is the output of the following code snippet? You are given that the exec system call in the child does not succeed?

Answer:
The parent process is trying to create a child process by using fork() system call. Then child process tries to execute a binary program named "some_binary_that_does_not_exec", Since the exec system call in child process fails it will not be able to execute the program.
The output of the code snippet is going to be "parent".

