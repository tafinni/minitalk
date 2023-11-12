# minitalk

This project's goal was to create a server and client, where the server is able to recieve messages from the client using only two UNIX signals.
To achieve this, the client turns the given message into binary and sends it to server bit by bit.

The server is able to only recieve message from one client at a time.

---

**How to use**

Write "make" in the minitalk folder and run ./server and ./client [servers PID] [your message]

---
