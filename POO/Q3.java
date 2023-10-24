import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite o valor do saque (entre 10 e 600 reais): ");
        int valorSaque = scanner.nextInt();

        if (valorSaque < 10 || valorSaque > 600) {
            System.out.println("Valor de saque inválido. O valor deve estar entre 10 e 600 reais.");
        } else {
            int notas100 = valorSaque / 100;
            int notas50 = (valorSaque % 100) / 50;
            int notas10 = (valorSaque % 50) / 10;
            int notas5 = (valorSaque % 10) / 5;
            int notas1 = valorSaque % 5;

            System.out.println("Para sacar R$" + valorSaque + " serão fornecidas:");
            System.out.println(notas100 + " nota(s) de 100 reais");
            System.out.println(notas50 + " nota(s) de 50 reais");
            System.out.println(notas10 + " nota(s) de 10 reais");
            System.out.println(notas5 + " nota(s) de 5 reais");
            System.out.println(notas1 + " nota(s) de 1 real");
        }

        scanner.close();
    }
}
