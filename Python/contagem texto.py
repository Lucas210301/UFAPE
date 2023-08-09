frase = input("Digite uma frase para contar as letras:")
d = {}
for letra in frase: 
    if letra in d:
        d[letra] = d[letra] + 1
else: 
    d[letra] = 1
print(d)        