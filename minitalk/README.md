*This project has been created as part of the 42 curriculum by dkpg-md-.*

# minitalk

## Description
minitalk is a data exchange program using UNIX signals. A client sends a string to a server by encoding each character as a sequence of bits, transmitted one at a time using only two signals: SIGUSR1 (bit 0) and SIGUSR2 (bit 1). The server reconstructs each character from 8 received bits and prints it.

## Instructions

**Compile:**
```bash
make
```

**Start the server first:**
```bash
./server
```
The server will print its PID. Copy it.

**Send a message from the client:**
```bash
./client <server_PID> "hello world"
```

The server will print the received message.

## How it works
- Each character is broken into 8 bits
- SIGUSR1 = bit 0, SIGUSR2 = bit 1
- The server rebuilds each character from 8 signals and prints it
- The server stays running and can receive from multiple clients

## Resources
- [UNIX signals documentation](https://man7.org/linux/man-pages/man7/signal.7.html)
- [sigaction manual](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [Bitwise operations in C](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)

**AI usage:** Claude was used to explain UNIX signals, bitwise operations, and the bit-by-bit encoding concept. All code was written manually with guided explanations of each function.
