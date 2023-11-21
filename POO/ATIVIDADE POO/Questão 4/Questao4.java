// Parte 1 - Ponto2D
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

// Parte 2 - Retangulo
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

// Parte 3 - Tipo de Associação
/*
* A associação entre as classes Retangulo e Ponto2D pode ser de agregação.
* Isso porque um retângulo é composto por dois pontos (canto superior esquerdo e canto inferior direito),
* mas a existência de um retângulo não é totalmente dependente dos pontos, pois os pontos podem existir
* independentemente do retângulo.
*/

public class Questao4 {
    public static void main(String[] args) {
        // Código de teste aqui, se necessário
    }
}
