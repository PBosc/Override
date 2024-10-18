Here, our input is converted to an int then used as a key to a decrypt function that takes every character in the string ``Q}|u`sfg~sf{}|a3`` and applies a xor to each character with 322424845 - our input then compares the output of this with "Congratulation" we can bruteforce it since there are only a few possible ints that could work. We use [our mini bruteforce script](./Ressources/exploit.py) to get the answer.
##
```bash
python exploit.py 
18 322424827
```

And there we got our key :

```bash
level03@OverRide:~$ ./level03 
***********************************
*		level03		**
***********************************
Password:322424827
$ whoami
level04
$ cat /home/users/level04/.pass
kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf
```
