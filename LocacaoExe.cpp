#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include <conio.h>


int main(){
	
	//variaveis para switch 
	int menu, cadastrar, alugar, devolver, disponivel, alugados, empresapar, sair;
	//vetores para cadastro pessoa fisica
	char nomepf[5], cpf[5], idade[5], sexo[5], telpf[5], email[5], cidadepf[5];
	//vetores para cadastro pessoa juridica
	char nomepj[5], cnpj[5], telpj[5], cidadepj[5], parceira[2];
	//vetores para cadatsro de automovel
	char placacarro[5], modelo[5], ano[5], fabricante[5];
	//vetor para lista de carros disponiveis e alugados
	char lista;
	//variavel do valor da diaria
	float valordiaria;
	//Declarando tipo File para gravar em um arquivo texto
	FILE *dadospf;
	FILE *dadospj;
	FILE *carrodisponivel;
	FILE *listardisponivel;
	FILE *listaralugados;
	FILE *empresaparceira;
	// Cria um arquivo texto para gravação e leitura
	dadospf = fopen("DadosPF.txt", "a");
	dadospj = fopen("DadosPJ.txt", "a");
	carrodisponivel = fopen("CarroDisponivel.txt", "a");
	empresaparceira = fopen("EmpresaParceira.txt", "a");
	listardisponivel = fopen("CarroDisponivel.txt", "r");
	listaralugados = fopen("CarroAlugado.txt", "r");
	
	
	//laço para voltar para o menu após terminar alguma funçaõ
	while(menu != 7){
	//limpa a tela
	system("cls");
		//menu principal
		printf("Escolha uma opcao do menu:\n 1- Cadastrar\n 2- Alugar\n 3- Devolver\n 4- Carros Disponiveis\n 5- Carros Alugados\n 6- Empresas Parceiras\n 7- Sair\n ");
		scanf("%d", &menu);
		//switch do primeiro menu
		switch (menu){
			case 1:
				//menu do cadastro
				printf("Escolha uma opcao de cadastro:\n 1- Pessoa Fisica\n 2- Pessoa Juridica\n 3- Automovel\n 4- Voltar ao menu anterior\n ");
				scanf("%d", &cadastrar);
					//switch para escolher o que vai cadastrar
					switch(cadastrar){
						//cadastro de pessoa fisica
						case 1:
						//	system("cls");
							printf("Digite seu nome: ");
							scanf("%s", &nomepf);
							//escrevendo no final do arquivo, sendo o f do começo de file
							fprintf(dadospf, "%s", nomepf);
							fprintf(dadospf, "\n");
							//Limpa a memoria do teclado
							 fflush(stdin);
							printf("Digite seu CPF: ");
							gets(cpf);
							fprintf(dadospf, "%s", cpf);
							fprintf(dadospf, "\n");
							printf("Digite sua idade: ");
							gets(idade);
							fprintf(dadospf, "%s", idade);
							fprintf(dadospf, "\n");
							printf("Digite seu sexo: ");
							gets(sexo);
							fprintf(dadospf, "%s", sexo);
							fprintf(dadospf, "\n");
							printf("Digite seu telefone: ");
							gets(telpf);
							fprintf(dadospf, "%s", telpf);
							fprintf(dadospf, "\n");
							printf("Digite seu email: ");
							gets(email);
							fprintf(dadospf, "%s", email);
							fprintf(dadospf, "\n");
							printf("Digite sua cidade: ");
							gets(cidadepf);
							fprintf(dadospf, "%s", cidadepf);
							fprintf(dadospf, "\n\n");
							fclose(dadospf);
						break;
						
						//cadstro de pessoa juridica
						case 2:
						//	system("cls");
								printf("Digite o nome da empresa: ");
								scanf("%s", &nomepj);
								fprintf(dadospj, "%s", nomepj);
								fprintf(dadospj, "\n");
							 	fflush(stdin);
								printf("Digite o CNPJ: ");
								gets(cnpj);
								fprintf(dadospj, "%s", cnpj);
								fprintf(dadospj, "\n");
								printf("Digite o telefone: ");
								gets(telpj);
								fprintf(dadospj, "%s", telpj);
								fprintf(dadospj, "\n");
								printf("Digite a cidade: ");
								gets(cidadepj);
								fprintf(dadospj, "%s", cidadepj);
								fprintf(dadospj, "\n");
								printf("Empresa e parceira (S/N)? ");
								gets(parceira);
								fprintf(dadospj, "%s", parceira);
								fprintf(dadospj, "\n\n");
								fclose(dadospj);
																
						break;
						
						//cadastro de automovel
						case 3:
						//	system("cls");
							printf("Digite a placa do carro (XXX-0000): ");
							scanf("%s", &placacarro);
							fprintf(carrodisponivel, "%s", placacarro);
							fprintf(carrodisponivel, "\n");
							fflush(stdin);	
							printf("Digite o modelo do carro: ");
							gets(modelo);
							fprintf(carrodisponivel, "%s", modelo);
							fprintf(carrodisponivel, "\n");
							printf("Digite o ano do carro : ");
							gets(ano);
							fprintf(carrodisponivel, "%s", ano);
							fprintf(carrodisponivel, "\n");
							printf("Digite o fabricante do carro: ");
							gets(fabricante);
							fprintf(carrodisponivel, "%s", fabricante);
							fprintf(carrodisponivel, "\n\n");	
							fclose(carrodisponivel);				
						break;	
					
					}
			break;
			
			case 4:
				system("cls");
				
				while(lista != EOF){

				lista = fgetc(listardisponivel);
				
				printf("%c", lista);
				}
				
				printf("1- Voltar ao menu anterior\n");
				scanf("%d", &menu);
			break;
			
			case 5:
				system("cls");
				
				while(lista != EOF){

				lista = fgetc(listaralugados);
				
				printf("%c", lista);
				}
				
				printf("1- Voltar ao menu anterior\n");
				scanf("%d", &menu);
			break;
			
			case 6:
				system("cls");
				
				
			break;
		}
	}
}
