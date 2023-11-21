public class AssociacaoRetanguloPonto2D {
    public static void main(String[] args) {
        // Criação de objetos Retangulo e Ponto2D
        Ponto2D ponto1 = new Ponto2D(2, 3);
        Ponto2D ponto2 = new Ponto2D(5, 7);

        Retangulo retangulo = new Retangulo(ponto1, ponto2);

        // Verificação se um ponto está dentro do retângulo
        Ponto2D pontoTeste = new Ponto2D(4, 5);

        if (retangulo.pontoEstaDentro(pontoTeste)) {
            System.out.println("O ponto está dentro do retângulo.");
        } else {
            System.out.println("O ponto está fora do retângulo.");
        }
    }
}
