public class Ponto2D {
    private double x;
    private double y;

    public Ponto2D() {
        this.x = 0.0;
        this.y = 0.0;
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

    public void exibirCoordenadas() {
        System.out.println("Coordenadas do ponto: (" + x + ", " + y + ")");
    }
}
