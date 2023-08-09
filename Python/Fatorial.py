print("\t Fatorial de um número")
factorial = 1
num = int(input("Digite um número para calcular: "))
if num < 0:
    print("Não existe fatorial para número negativo")
elif num == 0:
    print("O fatorial de 0 é 1")
else:
    for i in range(1, num + 1):
        factorial = factorial * i
    print("O fatorial de", num, "é", factorial)