// Conteúdo do arquivo Carta.java
public class Carta {
    private String nome;
    private String naipe;

    // Construtor
    public Carta(String nome, String naipe) {
        this.nome = nome;
        this.naipe = naipe;
    }

    // Métodos de acesso (getters e setters)
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNaipe() {
        return naipe;
    }

    public void setNaipe(String naipe) {
        this.naipe = naipe;
    }

    // Método para imprimir informações da carta
    public void imprimirCarta() {
        System.out.println("Carta: " + nome + " de " + naipe);
    }
}
