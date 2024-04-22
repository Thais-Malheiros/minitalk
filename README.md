Summary:
The purpose of this project is to code a small data exchange program using UNIX signals.

Mandatory Part:
In the mandatory part we must create a communication program in the form of a client and a server following some rules:
  • The server must be started first. After its launch, it has to print its PID.
  • The client takes two parameters:
    ◦ The server PID.
    ◦ The string to send.
  • The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.
  • The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
The server should be able to receive strings from several clients in a row without needing to restart.
  • The communication between client and server has to be done only using UNIX signals.
  • Only two signals can be used: SIGUSR1 and SIGUSR2.

Bonus Part:
• The server acknowledges every message received by sending back a signal to the client.
• Unicode characters support!
