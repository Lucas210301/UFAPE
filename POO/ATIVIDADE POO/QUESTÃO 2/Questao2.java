import java.util.Scanner;

class Ponto2D {
    private double x;
    private double y;

    public Ponto2D() {
        this.x = 0;
        this.y = 0;
    }

    public Ponto2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Ponto2D(double xy) {
        this.x = xy;
        this.y = xy;
    }

    public Ponto2D(Ponto2D ponto) {
        this.x = -ponto.getX();
        this.y = -ponto.getY();
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }
}

public class Questao2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Criar o primeiro ponto
        System.out.println("Digite as coordenadas x e y do primeiro ponto:");
        double x1 = sc.nextDouble();
        double y1 = sc.nextDouble();
        Ponto2D ponto1 = new Ponto2D(x1, y1);

        // Criar o segundo ponto
        System.out.println("Digite as coordenadas x e y do segundo ponto:");
        double x2 = sc.nextDouble();
        double y2 = sc.nextDouble();
        Ponto2D ponto2 = new Ponto2D(x2, y2);

        // Exibir as coordenadas do primeiro ponto
        System.out.println("Coordenadas do primeiro ponto: (" + ponto1.getX() + ", " + ponto1.getY() + ")");

        // Exibir as coordenadas do segundo ponto
        System.out.println("Coordenadas do segundo ponto: (" + ponto2.getX() + ", " + ponto2.getY() + ")");

        sc.close();
    }
}
