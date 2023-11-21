import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class Baralho {
    private List<Carta> cartas;
    private Random random;

    // Construtor
    public Baralho() {
        cartas = new ArrayList<>();
        random = new Random();

        // Adicionando cartas de naipes convencionais
        String[] naipes = {"Copas", "Ouros", "Paus", "Espadas"};
        String[] nomes = {"Ás", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Dama", "Rei"};

        for (String naipe : naipes) {
            for (String nome : nomes) {
                Carta carta = new Carta(nome, naipe);
                cartas.add(carta);
            }
        }

        // Adicionando coringas
        for (int i = 0; i < 4; i++) {
            Carta coringa = new Carta("Coringa", "Coringa");
            cartas.add(coringa);
        }
    }

    // Método para embaralhar as cartas no baralho
    public void embaralhar() {
        for (int i = 0; i < cartas.size(); i++) {
            int posicao1 = random.nextInt(cartas.size());
            int posicao2 = random.nextInt(cartas.size());

            Collections.swap(cartas, posicao1, posicao2);
        }
    }

    // Método para dar uma carta (retirada do topo do baralho)
    public Carta darCarta() {
        if (temCarta()) {
            return cartas.remove(cartas.size() - 1);
        } else {
            return null; // Retorna null se o baralho estiver vazio
        }
    }

    // Método para verificar se há cartas no baralho
    public boolean temCarta() {
        return !cartas.isEmpty();
    }

    // Método para imprimir as cartas do baralho
    public void imprimirBaralho() {
        for (Carta carta : cartas) {
            carta.imprimirCarta();
        }
    }

    public static void main(String[] args) {
        // Exemplo de uso da classe Baralho
        Baralho baralho = new Baralho();

        System.out.println("Baralho antes de embaralhar:");
        baralho.imprimirBaralho();

        baralho.embaralhar();

        System.out.println("\nBaralho depois de embaralhar:");
        baralho.imprimirBaralho();

        System.out.println("\nDando uma carta:");
        Carta cartaRetirada = baralho.darCarta();
        if (cartaRetirada != null) {
            cartaRetirada.imprimirCarta();
        } else {
            System.out.println("O baralho está vazio.");
        }
    }
}
