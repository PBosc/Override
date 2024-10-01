login = "victor"
hashed = (ord(login[3]) ^ 0x1337) + 0x5eeded
for c in login:
    if c < ' ':
        print("FAIL")
        break
    hashed += (ord(c) ^ hashed) % 0x539
print(hashed)