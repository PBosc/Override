Here, we go back to a more classic buffer overflow exploit. We see at first the secret_backdoor function that can execute whichever command we want. We can make it execute /bin/sh or just simply cat /home/users/end/.pass at the end if we manage to get inside it. First we find the address of this function using any disassembly tool.

The binary works simply and writes a message given as input. It stores it in a struct with the message at first followed by the username then the length of the message that is supposed to be limited to 128.

However, there is an exploit, when writing the username, we can write one extra character that will overflow in the len of the message in the struct.

By changing it, we can replace it by anything up to 255.

With 255 characters in the message, we can overflow in EIP easily, in order to see that, we can just use any characters and see where it starts segfaulting.
With a little fidgetting, we see that after 0xd0 characters, we overflow in EIP and segfault. This number is 208 so the EIP offset is 200.

Then we only have to overflow the username (first input) into the len with 40 characters, then set the len to anything over 0xd0 (208).
Finally in the message input, we can put any 200 characters followed by the address of the secret backdoor we found at the begining and simply put it in EIP.

```bash
(python -c 'print "N" * 40 + "\xd0" + "\n" + "N" * 200 "\x8c\x48\x55\x55\x55\x55\x00" + "\n" + "/bin/sh" ' ; cat) | ./level09
```

Flag : j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE