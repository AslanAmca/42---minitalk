# Minitalk

**Minitalk** is a system programming project from Ecole 42 that focuses on inter-process communication using UNIX signals. The project requires building a small data exchange program between a server and a client using only two signals: `SIGUSR1` and `SIGUSR2`. The client will send a string to the server, which will then display the string.

## Project Overview

The **Minitalk** project involves two primary programs:

- **Server**: This program will wait to receive messages from the client. Once it receives a message, it will display it.
- **Client**: This program will send a string message to the server, character by character, using UNIX signals.

## Goals

The main objectives of the project are:
- To understand how processes communicate via signals.
- To learn how to handle and manage UNIX signals.
- To improve low-level programming skills, particularly in C.
- To ensure reliable data transmission between processes.

## How It Works

- The server program starts and prints its process ID (PID), waiting to receive a message from the client.
- The client program takes the server's PID and a string as arguments. It sends the string to the server using `SIGUSR1` and `SIGUSR2` signals to represent binary data.
- The server receives the signals, decodes the binary data into characters, and prints the message.

## Setup Instructions

1. Use make to compile both the server and client programs

2. Start the server:
   ```bash
   ./server
   ```
   This will output the server's PID, which you will need for the client.

3. Use the client to send a message to the server:
	```bash
	./client <server_pid> "Your message here"
	```
	The server will receive the message and print it.
