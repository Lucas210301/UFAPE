from random import randint


def cpf_validate(numbers):
    #  Obtém os números do CPF e ignora outros caracteres ('-', '.')
    cpf = [int(char) for char in numbers if char.isdigit()]

    #  Verifica se o CPF tem 11 dígitos
    if len(cpf) != 11:
        return False

    #  Verifica se o CPF tem todos os números iguais, ex: 111.111.111-11
    #  Esses CPFs são considerados inválidos mas todos passam na validação dos dígitos.
    #  Antigo código para referência: if all(cpf[i] == cpf[i+1] for i in range (0, len(cpf)-1))
    if cpf == cpf[::-1]:
        return False

    #  Valida os dois dígitos verificadores
    for i in range(9, 11):
        value = sum((cpf[num] * ((i + 1) - num) for num in range(0, i)))
        digit = ((value * 10) % 11) % 10
        if digit != cpf[i]:
            return False
    return True


def cpf_generate():
    #  Gera os primeiros nove dígitos (e certifica-se de que não são todos iguais)
    while True:
        cpf = [randint(0, 9) for i in range(9)]
        if cpf != cpf[::-1]:
            break

    #  Gera os dois dígitos verificadores
    for i in range(9, 11):
        value = sum((cpf[num] * ((i + 1) - num) for num in range(0, i)))
        digit = ((value * 10) % 11) % 10
        cpf.append(digit)

    #  Retorna o CPF como string
    result = ''.join(map(str, cpf))
    return result


opcao = int(input('''[1] Validar um CPF
[2] Gerar um CPF válido
Opção: '''))

if opcao == 1:
    cpf = input('Digite o CPF: ')
    if cpf_validate(cpf):
        print('CPF válido.')
    else:
        print('CPF inválido.')
elif opcao == 2:
    cpf = cpf_generate()
    if cpf_validate(cpf):
        print(f'CPF gerado: {cpf[:3]}.{cpf[3:6]}.{cpf[6:9]}-{cpf[9:]}')
else:
    print('Inválido.')
