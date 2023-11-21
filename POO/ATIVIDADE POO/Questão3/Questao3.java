package Questao3;

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

class Retangulo {
    private Ponto2D ponto1;
    private Ponto2D ponto2;

    public Retangulo(Ponto2D ponto1, Ponto2D ponto2) {
        this.ponto1 = ponto1;
        this.ponto2 = ponto2;
    }

    public Retangulo(int x1, int y1, int x2, int y2) {
        this.ponto1 = new Ponto2D(x1, y1);
        this.ponto2 = new Ponto2D(x2, y2);
    }

    public boolean pontoEstaDentro(Ponto2D ponto) {
        double x = ponto.getX();
        double y = ponto.getY();

        double minX = Math.min(ponto1.getX(), ponto2.getX());
        double maxX = Math.max(ponto1.getX(), ponto2.getX());
        double minY = Math.min(ponto1.getY(), ponto2.getY());
        double maxY = Math.max(ponto1.getY(), ponto2.getY());

        return x >= minX && x <= maxX && y >= minY && y <= maxY;
    }
}

public class Questao3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Criar retângulo a partir de dois pontos
        System.out.println("Digite as coordenadas x e y do primeiro ponto do retângulo:");
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();

        System.out.println("Digite as coordenadas x e y do segundo ponto do retângulo:");
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();

        Retangulo retangulo = new Retangulo(x1, y1, x2, y2);

        // Verificar se um ponto está dentro do retângulo
        System.out.println("Digite as coordenadas x e y do ponto a ser verificado:");
        double xPonto = sc.nextDouble();
        double yPonto = sc.nextDouble();
        Ponto2D ponto = new Ponto2D(xPonto, yPonto);

        if (retangulo.pontoEstaDentro(ponto)) {
            System.out.println("O ponto está dentro do retângulo.");
        } else {
            System.out.println("O ponto está fora do retângulo.");
        }

        sc.close();
    }
}
