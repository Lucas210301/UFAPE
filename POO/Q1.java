import java.util.Scanner;

public class Q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite um número de 5 dígitos: ");
        int numero = scanner.nextInt();

        if (numero < 10000 || numero > 99999) {
            System.out.println("O número não possui 5 dígitos.");
        } else {
            int digito1 = numero / 10000;
            int digito2 = (numero % 10000) / 1000;
            int digito3 = (numero % 1000) / 100;
            int digito4 = (numero % 100) / 10;
            int digito5 = numero % 10;

            System.out.println(digito1 + "   " + digito2 + "   " + digito3 + "   " + digito4 + "   " + digito5);
        }

        scanner.close();
    }
}
