public class ArrayUtilidades {

    public static boolean[] verificarPositivos(int[] array) {
        if (array == null) {
            throw new IllegalArgumentException("O array de entrada não pode ser nulo.");
        }

        boolean[] resultado = new boolean[array.length];

        for (int i = 0; i < array.length; i++) {
            resultado[i] = array[i] > 0;
        }

        return resultado;
    }

    public static void main(String[] args) {
        // Exemplo de uso
        int[] arrayEntrada = {1, -2, 0, 5, -3};
        boolean[] resultado = verificarPositivos(arrayEntrada);

        // Imprimindo o resultado
        System.out.print("Array de entrada: ");
        imprimirArray(arrayEntrada);

        System.out.print("Resultado: ");
        imprimirArray(resultado);
    }

    private static void imprimirArray(int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i]);
            if (i < array.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }

    private static void imprimirArray(boolean[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i]);
            if (i < array.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }
}
