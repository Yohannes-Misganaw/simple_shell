# Simple Shell

A simple UNIX command interpreter implemented in C.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Author](#author)

## Description

Simple Shell is a command-line interpreter developed in C as a group project. It provides basic shell functionalities, including executing commands, handling arguments, and implementing built-in commands like `exit` and `env`. The project follows the specifications provided by Julien Barbier.

## Features

- Interactive shell prompt.
- Execute simple commands with or without arguments.
- Handle the PATH environment variable to locate executables.
- Implement built-ins: `exit` and `env`.
- Error handling for command not found and end-of-file condition.
- Code follows the style guide provided by Betty.

## Requirements

- Ubuntu 20.04 LTS
- GCC compiler with specified options: `-Wall -Werror -Wextra -pedantic -std=gnu89`

Compile the shell using the following command:

$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


## Author
- [Yohannes Misganaw Assefa](https://github.com/yohannes-misganaw)
