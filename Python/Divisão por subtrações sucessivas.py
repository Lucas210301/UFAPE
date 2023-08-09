from re import X


dividendo = int(input("dividendo: "))
divisor = int(input("divisor: "))
quociente = 0 
x = dividendo 
while x >= divisor:
    x = x - divisor
    quociente = quociente + 1
resto = X
print(f"{dividendo} / {divisor} = (quociente) {resto} (resto)")    