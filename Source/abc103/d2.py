def gcd(a, b):
    if(b == 0):
        return a
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

n = int(input())
a = input().split()

for i in range(n):
    a[i] = int(a[i])

l = 1
for i in range(n):
    l = lcm(l, a[i])

l -= 1
s = 0

for i in range(n):
    s += l % a[i]

print(s)