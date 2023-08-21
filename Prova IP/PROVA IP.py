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
    print("4. Buscar por Gênero")
    print("5. Buscar Por Duração")
    print("6. Buscar Por Nota")
    print("7. Editar Filme")
    print('\033[31m'"8. Remover Filme"'\033[0;0m')
    print("9. Sair")

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
    titulo_remover = input("Digite o título do filme a ser removido: ")
    filme_encontrado = buscar_filme_por_titulo(titulo_remover)
    if filme_encontrado:
        lista_filmes.remove(filme_encontrado[0])
        salvar_dados()
        print("Filme removido com sucesso.")
    else:
        print("Filme não encontrado.")

carregar_dados()
exibir_menu()

while True:
    escolha = input("Escolha uma opção: ")

    if escolha == "1":
        titulo = input("Digite o título do filme: ")
        genero = input("Digite o gênero do filme: ")
        duracao = input("Digite a duração do filme (em horas): ")
        nota = input("Digite a nota do filme: ")
        filme = {"Titulo": titulo, "Genero": genero, "Duracao (horas)": duracao, "Nota": nota}
        lista_filmes.append(filme)
        salvar_dados()
        print("Filme cadastrado com sucesso.")

    elif escolha == "2":
        for filme in lista_filmes:
            print(f"Título: {filme['Titulo']}, Gênero: {filme['Genero']}, Duração: {filme['Duracao (horas)']}, Nota: {filme['Nota']}")

    elif escolha == "3":
        titulo_busca = input("Digite o título a ser buscado: ")
        filmes_encontrados = buscar_filme_por_titulo(titulo_busca)
        if filmes_encontrados:
            for filme in filmes_encontrados:
                print(f"Título: {filme['Titulo']}, Gênero: {filme['Genero']}, Duração: {filme['Duracao (horas)']}, Nota: {filme['Nota']}")
        else:
            print("Nenhum filme encontrado.")

    elif escolha == "4":
        genero_busca = input("Digite o gênero a ser buscado: ")
        genero_bus = genero_busca.lower()
        filmes_encontrados = [filme for filme in lista_filmes if genero_bus in filme["Genero"].lower()]
        if filmes_encontrados:
            for filme in filmes_encontrados:
                print(f"Título: {filme['Titulo']}, Gênero: {filme['Genero']}, Duração: {filme['Duracao (horas)']}, Nota: {filme['Nota']}")
        else:
            print("Nenhum filme encontrado.")

    elif escolha == "5":
        duracao_busca = input("Digite a duração a ser buscada (em horas): ")
        filmes_encontrados = [filme for filme in lista_filmes if duracao_busca == filme["Duracao (horas)"]]
        if filmes_encontrados:
            for filme in filmes_encontrados:
                print(f"Título: {filme['Titulo']}, Gênero: {filme['Genero']}, Duração: {filme['Duracao (horas)']}, Nota: {filme['Nota']}")
        else:
            print("Nenhum filme encontrado.")

    elif escolha == "6":
        nota_busca = input("Digite a nota a ser buscada: ")
        filmes_encontrados = [filme for filme in lista_filmes if nota_busca == filme["Nota"]]
        if filmes_encontrados:
            for filme in filmes_encontrados:
                print(f"Título: {filme['Titulo']}, Gênero: {filme['Genero']}, Duração: {filme['Duracao (horas)']}, Nota: {filme['Nota']}")
        else:
            print("Nenhum filme encontrado.")

    elif escolha == "7":
        editar_filme()

    elif escolha == "8":
        remover_filme()

    elif escolha == "9":
        salvar_dados()
        print("Saindo do programa...")
        break

    else:
        print("Opção inválida. Escolha novamente.")
