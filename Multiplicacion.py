n = int(input("Cuantos digitos tendran los numero?: "))
num1 = input("Ingrese el primer numero: ")
num2 = input("Ingrese el segundo numero: ")

arr1 = [int(num1[i]) for i in range(n)]
arr2 = [int(num2[i]) for i in range(n)]
res = [0] * (2 * n)

for i in range(n - 1, -1, -1):
    for j in range(n - 1, -1, -1):
        mul = arr1[i] * arr2[j]
        pos1 = i + j
        pos2 = i + j + 1
        suma = mul + res[pos2]
        res[pos1] += suma // 10
        res[pos2] = suma % 10

k = 0
while k < 2 * n and res[k] == 0:
    k += 1

if k == 2 * n:
    print("0")
else:
    print(''.join(str(d) for d in res[k:]))