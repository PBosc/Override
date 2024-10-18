# Level 6

This one is very simple and pure reverse engineering : it will just take our login (it has to be 6+ characters), pass it through a hash function and compare the password we enter to the result of this function.

We just have to [remake the hash function](./Ressources/unhasher.py) on our side and execute it with the login we choose and then we get the password

```bash
python unhasher.py 
6232806
```

```bash
level06@OverRide:~$ ./level06
***********************************
*		level06		  *
***********************************
-> Enter Login: victor
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6232806
Authenticated!
$ whoami
level07
$ cat /home/users/level07/.pass
GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8
```