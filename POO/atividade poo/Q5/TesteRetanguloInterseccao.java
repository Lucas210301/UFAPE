import java.util.Scanner;

public class TesteRetanguloInterseccao {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Criar retângulo 1
        System.out.println("Digite as coordenadas dos pontos extremos do retângulo 1:");
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        RetanguloInterseccao retangulo1 = new RetanguloInterseccao(x1, y1, x2, y2);

        // Criar retângulo 2
        System.out.println("Digite as coordenadas dos pontos extremos do retângulo 2:");
        int x3 = sc.nextInt();
        int y3 = sc.nextInt();
        int x4 = sc.nextInt();
        int y4 = sc.nextInt();
        RetanguloInterseccao retangulo2 = new RetanguloInterseccao(x3, y3, x4, y4);

        // Calcular e exibir a interseção dos retângulos
        RetanguloInterseccao interseccao = retangulo1.calculaInterseccao(retangulo2);

        if (interseccao != null) {
            System.out.println("Os retângulos têm interseção.");
            System.out.println("Coordenadas da interseção: (" + interseccao.getX1() + ", " + interseccao.getY1() + ") - (" + interseccao.getX2() + ", " + interseccao.getY2() + ")");
        } else {
            System.out.println("Os retângulos não têm interseção.");
        }

        sc.close();
    }
}
