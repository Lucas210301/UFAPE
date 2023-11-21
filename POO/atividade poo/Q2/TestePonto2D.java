import java.util.Scanner;

public class TestePonto2D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Criar ponto na origem
        Ponto2D ponto1 = new Ponto2D();
        System.out.print("Ponto na origem: ");
        ponto1.exibirCoordenadas();

        // Criar ponto com coordenadas indicadas
        System.out.println("\nDigite as coordenadas para criar um ponto:");
        double x2 = sc.nextDouble();
        double y2 = sc.nextDouble();
        Ponto2D ponto2 = new Ponto2D(x2, y2);
        System.out.print("Novo ponto criado: ");
        ponto2.exibirCoordenadas();

        // Criar ponto com uma única coordenada
        System.out.println("\nDigite uma coordenada para criar um ponto:");
        double xy3 = sc.nextDouble();
        Ponto2D ponto3 = new Ponto2D(xy3);
        System.out.print("Novo ponto criado: ");
        ponto3.exibirCoordenadas();

        // Criar ponto oposto a um ponto existente
        System.out.println("\nCriar um ponto oposto ao ponto2:");
        Ponto2D ponto4 = new Ponto2D(ponto2);
        System.out.print("Novo ponto criado (oposto): ");
        ponto4.exibirCoordenadas();

        sc.close();
    }
}
