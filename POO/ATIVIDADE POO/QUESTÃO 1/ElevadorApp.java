import java.util.Scanner;

class Elevador {
    private int capacidade;
    private int andarAtual;

    public Elevador(int capacidade) {
        this.capacidade = capacidade;
        this.andarAtual = 0;  // Inicia no térreo
    }

    public void entrar() {
        if (this.capacidade > 0) {
            System.out.println("Entrou uma pessoa no elevador.");
            this.capacidade--;
        } else {
            System.out.println("Elevador cheio. Não é possível entrar.");
        }
    }

    public void sair() {
        if (this.capacidade < 10) {
            System.out.println("Saiu uma pessoa do elevador.");
            this.capacidade++;
        } else {
            System.out.println("Elevador vazio. Não é possível sair.");
        }
    }

    public void subir() {
        if (this.andarAtual < 10) {
            System.out.println("Elevador subiu para o andar " + (++this.andarAtual));
        } else {
            System.out.println("Elevador no último andar. Não é possível subir.");
        }
    }

    public void descer() {
        if (this.andarAtual > 0) {
            System.out.println("Elevador desceu para o andar " + (--this.andarAtual));
        } else {
            System.out.println("Elevador no térreo. Não é possível descer.");
        }
    }
}

public class ElevadorApp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Criação de um elevador com capacidade de 10 pessoas
        Elevador elevador = new Elevador(10);

        // Exemplo de uso do elevador
        elevador.entrar();
        elevador.subir();
        elevador.subir();
        elevador.entrar();
        elevador.descer();
        elevador.sair();
        elevador.subir();

        sc.close();
    }
}
