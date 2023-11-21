public class Elevador {
    private int capacidade;
    private int pessoasPresentes;
    private int andarAtual;

    public Elevador(int capacidade) {
        this.capacidade = capacidade;
        this.pessoasPresentes = 0;
        this.andarAtual = 0;
    }

    public void entrar(int pessoas) {
        if (pessoas + pessoasPresentes <= capacidade) {
            pessoasPresentes += pessoas;
            System.out.println(pessoas + " pessoa(s) entrou/entraram no elevador.");
        } else {
            System.out.println("Capacidade excedida. Não foi possível entrar.");
        }
    }

    public void sair(int pessoas) {
        if (pessoas <= pessoasPresentes) {
            pessoasPresentes -= pessoas;
            System.out.println(pessoas + " pessoa(s) saiu/saíram do elevador.");
        } else {
            System.out.println("Número de pessoas inválido. Não foi possível sair.");
        }
    }

    public void subir() {
        if (andarAtual < 10) {
            andarAtual++;
            System.out.println("Elevador subiu para o andar " + andarAtual + ".");
        } else {
            System.out.println("O elevador já está no último andar. Não é possível subir mais.");
        }
    }

    public void descer() {
        if (andarAtual > 0) {
            andarAtual--;
            System.out.println("Elevador desceu para o andar " + andarAtual + ".");
        } else {
            System.out.println("O elevador já está no térreo. Não é possível descer mais.");
        }
    }

    public void status() {
        System.out.println("Andar Atual: " + andarAtual);
        System.out.println("Pessoas Presentes: " + pessoasPresentes);
    }
}
