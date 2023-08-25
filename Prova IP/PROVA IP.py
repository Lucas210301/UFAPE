lista_filmes = []

def carregar_dados():
    try:
        with open("filmes.csv", mode='r', encoding='utf-8') as arquivo_csv:
            linhas = arquivo_csv.readlines()
            cabecalho = [item.strip() for item in linhas[0].split(',')]
            for linha in linhas[1:]:
                valores = [item.strip() for item in linha.split(',')]
                filme = dict(zip(cabecalho, valores))
                lista_filmes.append(filme)
    except FileNotFoundError:
        pass

def salvar_dados():
    with open("filmes.csv", mode='w', newline='', encoding='utf-8') as arquivo_csv:
        if lista_filmes:
            cabecalho = ",".join(lista_filmes[0].keys())
            arquivo_csv.write(f"{cabecalho}\n")
            for filme in lista_filmes:
                valores = ",".join(filme.values())
                arquivo_csv.write(f"{valores}\n")

def exibir_menu():
    print("Menu:")
    print('\033[32m'"1. Cadastrar Filme"'\033[0;0m')
    print('\033[34m'"2. Ver Filmes"'\033[0;0m')
    print('\033[36m'"3. Buscar por Título"'\033[0;0m')
    print('\033[35m'"4. Buscar por Gênero"'\033[0;0m')
    print('\033[35m'"5. Busca por Estoque / Disponíveis"'\033[0;0m')
    print('\033[33m'"6. Buscar Por Nota"'\033[0;0m')
    print("7. Editar Filme")
    print('\033[2m'"8. Remover Filme"'\033[0;0m')
    print('\033[31m'"9. Sair"'\033[0;0m')

def buscar_filme_por_titulo(titulo):
    filmes_encontrados = []
    titulo_lower = titulo.lower()
    for filme in lista_filmes:
        if titulo_lower in filme["Titulo"].lower():
            filmes_encontrados.append(filme)
    return filmes_encontrados

def editar_filme():
    titulo_editar = input("Digite o título do filme a ser editado: ")
    filme_encontrado = buscar_filme_por_titulo(titulo_editar)
    if filme_encontrado:
        genero = input("Digite o novo gênero do filme: ")
        duracao = input("Digite a nova duração do filme (em horas): ")
        nota = input("Digite a nova nota do filme: ")
        filme_encontrado[0]["Genero"] = genero
        filme_encontrado[0]["Duracao (horas)"] = duracao
        filme_encontrado[0]["Nota"] = nota
        salvar_dados()
        print("Filme editado com sucesso.")
    else:
        print("Filme não encontrado.")

def remover_filme():
    titulo_remover = input('\033[34m'"Digite o título do filme a ser removido: "'\033[0;0m')
    filme_encontrado = buscar_filme_por_titulo(titulo_remover)
    if filme_encontrado:
        lista_filmes.remove(filme_encontrado[0])
        salvar_dados()
        print('\033[31m'"Filme removido com sucesso."'\033[0;0m')
    else:
        print('\033[31m'"Filme não encontrado."'\033[0;0m')

carregar_dados()
exibir_menu()

while True:
    escolha = input("Escolha uma opção: ")

    if escolha == "1":
        titulo = input('\033[34m'"Digite o título do filme: "'\033[0;0m')
        genero = input('\033[36m'"Digite o gênero do filme: "'\033[0;0m')
        duracao = input('\033[37m'"Digite a duração do filme (em horas): "'\033[0;0m')
        nota = input('\033[33m'"Digite a nota do filme: "'\033[0;0m')
        estoque = input('\033[35m'"Digite o estoque do filme (Sim/Não): "'\033[0;0m')
        filme = {"Titulo": titulo, "Genero": genero, "Duracao (horas)": duracao, "Nota": nota, "Estoque": estoque}
        lista_filmes.append(filme)
        salvar_dados()
        print('\033[32m'"Filme cadastrado com sucesso."'\033[0;0m')

    elif escolha == "2":
        for filme in lista_filmes:
            print(f"Título: {filme['Titulo']}, Gênero: {filme['Genero']}, Duração: {filme['Duracao (horas)']}, Nota: {filme['Nota']}, Estoque: {filme['Estoque']}")

    elif escolha == "3":
        titulo_busca = input("Digite o título a ser buscado: ")
        filmes_encontrados = buscar_filme_por_titulo(titulo_busca)
        if filmes_encontrados:
            for filme in filmes_encontrados:
                print(f"Título: {filme['Titulo']}, Gênero: {filme['Genero']}, Duração: {filme['Duracao (horas)']}, Nota: {filme['Nota']}, Estoque: {filme['Estoque']}")
        else:
            print("Nenhum filme encontrado.")

    elif escolha == "4":
        genero_busca = input("Digite o gênero a ser buscado: ")
        genero_bus = genero_busca.lower()
        filmes_encontrados = [filme for filme in lista_filmes if genero_bus in filme["Genero"].lower()]
        if filmes_encontrados:
            for filme in filmes_encontrados:
                print(f"Título: {filme['Titulo']}, Gênero: {filme['Genero']}, Duração: {filme['Duracao (horas)']}, Nota: {filme['Nota']}, Estoque: {filme['Estoque']}")
        else:
            print("Nenhum filme encontrado.")

    elif escolha == "5":
        titulo_busca = input("Digite o título do filme para verificar o estoque: ")
        filme_encontrado = buscar_filme_por_titulo(titulo_busca)
        if filme_encontrado:
            print(f"Estoque do filme '{filme_encontrado[0]['Titulo']}': {filme_encontrado[0]['Estoque']}")
        else:
            print("Nenhum filme encontrado com esse título.")

    elif escolha == "6":
        nota_busca = input("Digite a nota a ser buscada: ")
        filmes_encontrados = [filme for filme in lista_filmes if nota_busca == filme["Nota"]]
        if filmes_encontrados:
            for filme in filmes_encontrados:
                print(f"Título: {filme['Titulo']}, Gênero: {filme['Genero']}, Duração: {filme['Duracao (horas)']}, Nota: {filme['Nota']}, Estoque: {filme['Estoque']}")
        else:
            print('\033[31m'"Nenhum filme encontrado."'\033[0;0m')

    elif escolha == "7":
        editar_filme()

    elif escolha == "8":
        remover_filme()

    elif escolha == "9":
        salvar_dados()
        print('\033[31m'"Saindo do programa..."'\033[0;0m')
        break

    else:
        print('\033[31m'"Opção inválida. Escolha novamente."'\033[0;0m')
