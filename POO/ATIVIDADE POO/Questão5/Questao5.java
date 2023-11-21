import java.util.Scanner;

class Retangulo {
    public int x1, y1, x2, y2;

    public Retangulo(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    public Retangulo calculaInterseccao(Retangulo outro) {
        int interseccaoX1 = Math.max(this.x1, outro.x1);
        int interseccaoY1 = Math.max(this.y1, outro.y1);
        int interseccaoX2 = Math.min(this.x2, outro.x2);
        int interseccaoY2 = Math.min(this.y2, outro.y2);

        if (interseccaoX1 <= interseccaoX2 && interseccaoY1 <= interseccaoY2) {
            return new Retangulo(interseccaoX1, interseccaoY1, interseccaoX2, interseccaoY2);
        } else {
            return null; // Sem interseção
        }
    }
}

public class Questao5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Criação dos retângulos
        System.out.println("Digite as coordenadas x e y do primeiro retângulo:");
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        Retangulo retangulo1 = new Retangulo(x1, y1, x2, y2);

        System.out.println("Digite as coordenadas x e y do segundo retângulo:");
        int x3 = sc.nextInt();
        int y3 = sc.nextInt();
        int x4 = sc.nextInt();
        int y4 = sc.nextInt();
        Retangulo retangulo2 = new Retangulo(x3, y3, x4, y4);

        // Calcula a interseção e exibe os resultados
        Retangulo interseccao = retangulo1.calculaInterseccao(retangulo2);

        if (interseccao != null) {
            System.out.println("Os retângulos têm interseção. Coordenadas do retângulo de interseção:");
            System.out.println("x1: " + interseccao.x1 + ", y1: " + interseccao.y1);
            System.out.println("x2: " + interseccao.x2 + ", y2: " + interseccao.y2);
        } else {
            System.out.println("Os retângulos não têm interseção.");
        }

        sc.close();
    }
}
