import java.util.Scanner;

public class TesteRetangulo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Criar retângulo a partir de dois pontos
        System.out.println("Digite as coordenadas dos pontos extremos do retângulo:");
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        Retangulo retangulo1 = new Retangulo(x1, y1, x2, y2);

        // Criar retângulo a partir de dois objetos Ponto2D
        System.out.println("\nDigite as coordenadas do primeiro ponto do retângulo:");
        int x3 = sc.nextInt();
        int y3 = sc.nextInt();
        Ponto2D ponto3 = new Ponto2D(x3, y3);

        System.out.println("Digite as coordenadas do segundo ponto do retângulo:");
        int x4 = sc.nextInt();
        int y4 = sc.nextInt();
        Ponto2D ponto4 = new Ponto2D(x4, y4);

        Retangulo retangulo2 = new Retangulo(ponto3, ponto4);

        // Verificar se um ponto está dentro do retângulo
        System.out.println("\nDigite as coordenadas de um ponto para verificar se está dentro do retângulo:");
        int xPonto = sc.nextInt();
        int yPonto = sc.nextInt();
        Ponto2D pontoTeste = new Ponto2D(xPonto, yPonto);

        if (retangulo1.pontoEstaDentro(pontoTeste)) {
            System.out.println("O ponto está dentro do retângulo.");
        } else {
            System.out.println("O ponto está fora do retângulo.");
        }

        sc.close();
    }
}
