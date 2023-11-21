public class Retangulo {
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
        return ponto.getX() >= ponto1.getX() && ponto.getX() <= ponto2.getX() &&
               ponto.getY() >= ponto1.getY() && ponto.getY() <= ponto2.getY();
    }
}
