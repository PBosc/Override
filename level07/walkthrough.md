# Level 7

In this program we have a very poorly done integer storage system. We can pretty much store whatever we want wherever we want. Only problem is that very high memory addresses and addresses that are multiples of 3 are "reserved to wil". Fortunately, the indexes are hard coded and because we are storing int, it has to multiply the unsigned int index by 4. We can overflow the unsigned int by exploiting this multiplication and thus 1073741824 becomes UINT_MAX + 1 which loops back to 0. With this, we can write all of out shellcode by converting each byte to little endian then to base 10.

After that, we need to find the EIP pointer location. We found it by estimating how much memory was in the stack after the array and assuming there is an other bunch of specific things stored in memory we fidget around and find that the offset is 114 after the array, so we store the address of our shellcode at this offset. The address of the shellcode is a bit of a mess because it changes with the env, so to get a little wiggle room we add a bunch of NOPs.

All of this is automatized in [a little python script](./Ressources/script.py)

```bash
cat /tmp/in07 - | env - ./level07
whoami
level08
cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```
