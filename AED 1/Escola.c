#include <stdio.h>

char CalculaMedia(int falta, double nota1, double nota2, double nota3, double nota4, double nota5){
	
	double media;
	
	media = (nota1+nota2+nota3+nota4+nota5)/5;
	if(falta>=5){
		printf("REPROVADO");
	}
	else if(media<7){
		
		printf("REPROVADO");
	}
	else if(media>=7){
		printf("APROVADO");
	}
}
int main(){
	int falta;
	double nota1, nota2, nota3, nota4, nota5;
	scanf("%i%lf%lf%lf%lf%lf", &falta, &nota1, &nota2, &nota3, &nota4, &nota5);
	printf("%c", CalculaMedia(falta, nota1, nota2, nota3, nota4, nota5));
}