velocidade = float(input("Digite a velocidade do seu carro:"))
if velocidade > 80:
    multa = (velocidade - 80) * 5
    print(f"Você foi multado em R$ {multa:7.2f}!")
if velocidade <= 80:
    print("Sua velocidade está ok, boa viagem!")