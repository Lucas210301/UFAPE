public class RetanguloInterseccao {
    private int x1, y1, x2, y2;

    public RetanguloInterseccao(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    public RetanguloInterseccao calculaInterseccao(RetanguloInterseccao outro) {
        int interseccaoX1 = Math.max(this.x1, outro.x1);
        int interseccaoY1 = Math.max(this.y1, outro.y1);
        int interseccaoX2 = Math.min(this.x2, outro.x2);
        int interseccaoY2 = Math.min(this.y2, outro.y2);

        if (interseccaoX1 < interseccaoX2 && interseccaoY1 < interseccaoY2) {
            return new RetanguloInterseccao(interseccaoX1, interseccaoY1, interseccaoX2, interseccaoY2);
        } else {
            return null; // Não há interseção
        }
    }

    // Outros métodos da classe RetanguloInterseccao
    // ...

    // Métodos getters e setters
    // ...
}
