class ContaBancaria:
    def __init__(self, numero, saldo, titular):
        self.numero = numero
        self.saldo = saldo
        self.titular = titular
    
    def __str__(self):
        return f"Conta: {self.numero}\nSaldo: R${self.saldo:.2f}\nTitular: {self.titular}"

contas = []

while True:
    print("1 - Cadastrar conta")
    print("2 - Exibir saldo e titular da conta")
    print("3 - Identificar o cliente mais rico por número de conta")
    print("4 - Sair")
    
    opcao = int(input("Escolha uma opção: "))
    
    if opcao == 1:
        numero = int(input("Digite o número da conta: "))
        saldo = float(input("Digite o saldo da conta: "))
        titular = input("Digite o nome do titular da conta: ")
        
        contas.append(ContaBancaria(numero, saldo, titular))
        
        print("Conta cadastrada com sucesso!")
    
    elif opcao == 2:
        numero = int(input("Digite o número da conta: "))
        for conta in contas:
            if conta.numero == numero:
                print(conta)
                break
        else:
            print("Conta não encontrada.")
    
    elif opcao == 3:
        mais_rico = None
        for conta in contas:
            if mais_rico is None or conta.saldo > mais_rico.saldo:
                mais_rico = conta
        
        if mais_rico is not None:
            print(f"Cliente mais rico: {mais_rico.titular}, Conta: {mais_rico.numero}, Saldo: R${mais_rico.saldo:.2f}")
        else:
            print("Não há contas cadastradas.")
    
    elif opcao == 4:
        print("Encerrando o programa...")
        break
    
    else:
        print("Opção inválida.")
