# Introduction
  Welcome to the Operating Systems project repository for the Simple Shell project. This repository contains the collaborative work of Burhan and Abdulkadir under the supervision of Professor Elma Avdic. 
  The project focuses on developing a simple shell application.

## About the Project
  The Simple Shell project aims to create a basic command-line interface that mimics some functionalities of a Unix shell. 
  The project is a part of the Operating Systems course, providing an opportunity for students to delve into the fundamentals of operating systems and gain practical experience in system programming.

## Simple Shell Project Outline
**Authors:** Burhan Hošić and Abdulkadir Akay

**Overview:**
This project is a simple implementation of a shell program in C. 
A shell is a command-line interface that allows users to interact with the operating system by executing commands. 
The shell program developed here provides basic functionality similar to popular Unix/Linux shells, such as executing external commands, 
handling built-in commands, and providing a command prompt for user input.

**Features and command execution:**

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

**Running the Shell:**
Compile the C program. Execute the compiled binary to start the shell.
Enter commands at the prompt and press Enter to execute.

**Supported Commands:**
**External commands:** rm, cat, clear, cowsay. 
**Built-in commands:** rm, cat, clear, cowsay, exit.

Requirements:
C compiler (e.g. GCC)
Standard C libraries & ncurses library (for color output)

Notes:
This shell project is designed for educational purposes and provides a basic understanding of shell programming concepts.
Further enhancements and optimizations can be made in the future to extend its functionality and improve performance.

### Professor
  - Professor Elma Avdić
#### Project Structure - The project repository is organized as follows:
  // src: 
Contains the source code of the simple shell implementation.

  // docs: 
Documentation related to the project, including this README file.
