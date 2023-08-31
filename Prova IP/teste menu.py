def exibir_janela(conteudo):
    largura = max(len(linha) for linha in conteudo) + 2
    linha_superior = "+" + "-" * (largura - 2) + "+"
    print(linha_superior)
    for linha in conteudo:
        print("|" + linha.center(largura - 2) + "|")
    print(linha_superior)

conteudo_janela = [
    "Bem-vindo ao Sistema",
    "1. Cadastrar Filme",
    "2. Ver Filmes",
    "3. Sair"
]

exibir_janela(conteudo_janela)
