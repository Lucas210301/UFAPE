import java.util.Scanner;

public class TesteElevador {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite a capacidade do elevador:");
        int capacidade = sc.nextInt();

        Elevador elevador = new Elevador(capacidade);

        System.out.println("Digite o número de pessoas para entrar no elevador:");
        int pessoasEntrar = sc.nextInt();
        elevador.entrar(pessoasEntrar);

        System.out.println("Digite o número de pessoas para sair do elevador:");
        int pessoasSair = sc.nextInt();
        elevador.sair(pessoasSair);

        System.out.println("Deseja subir ou descer? (s/d)");
        char opcao = sc.next().charAt(0);

        if (opcao == 's') {
            elevador.subir();
        } else if (opcao == 'd') {
            elevador.descer();
        } else {
            System.out.println("Opção inválida.");
        }

        elevador.status();

        sc.close();
    }
}
