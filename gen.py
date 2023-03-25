res = ""
n = 1000000
for i in range(3, n, 2):
  is_prime = True
  for j in range(3, i):
    if i%j == 0:
      is_prime = False
      break
  if is_prime:
    res += str(i) + ","
  print(i, end="\r")

print("\n")

with open("dump.txt", "w") as f:
  f.write(res)