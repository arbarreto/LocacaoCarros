#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>


int main(){
	
	//variaveis para switch 
	int menu, cadastrar, alugar, devolver, disponivel, alugados, empresapar, sair;
	//vetores para cadastro pessoa fisica
	char nomepf[5], cpf[5], idade[5], sexo[5], telpf[5], email[5], cidadepf[5];
	//vetores para cadastro pessoa juridica
	char nomepj[5], cnpj[5], telpj[5], cidadepj[5], parceira[2];
	//vetores para cadatsro de automovel
	char placacarro[5], modelo[5], ano[5], fabricante[5];
	
	//variavel do valor da diaria
	float valordiaria;

	//la�o para voltar para o menu ap�s terminar alguma fun�a�
	do{
	//limpa a tela
	system("cls");
		//menu principal
		printf("Escolha uma opcao do menu:\n 1- Cadastrar\n 2- Alugar\n 3- Devolver\n 4- Carros Disponiveis\n 5- Carros Alugados\n 6- Empresas Parceiras\n 7- Sair\n ");
		scanf("%d", &menu);
		
		//switch do primeiro menu
		switch (menu){
			case 1:
				//Declarando tipo File para gravar em um arquivo texto
				FILE *dadospf;
				
				// Cria um arquivo texto para grava��o 
				dadospf = fopen("DadosPF.txt", "a");
				
				//menu do cadastro
				printf("Escolha uma opcao de cadastro:\n 1- Pessoa Fisica\n 2- Pessoa Juridica\n 3- Automovel\n 4- Voltar ao menu anterior\n");
				scanf("%d", &cadastrar);
					//switch para escolher o que vai cadastrar
					switch(cadastrar){
						//cadastro de pessoa fisica
						case 1:
						//	system("cls");
							printf("Digite o nome: ");
							scanf("%s", &nomepf);
							//escrevendo no final do arquivo, sendo o f do come�o de file
							fprintf(dadospf, "%s", nomepf);
							fprintf(dadospf, "\n");
							//Limpa a memoria do teclado
							 fflush(stdin);
							printf("Digite o CPF (Somente numeros): ");
							gets(cpf);
							fprintf(dadospf, "%s", cpf);
							fprintf(dadospf, "\n");
							printf("Digite a idade: ");
							gets(idade);
							fprintf(dadospf, "%s", idade);
							fprintf(dadospf, "\n");
							printf("Digite o sexo (F/M): ");
							gets(sexo);
							fprintf(dadospf, "%s", sexo);
							fprintf(dadospf, "\n");
							printf("Digite o telefone: ");
							gets(telpf);
							fprintf(dadospf, "%s", telpf);
							fprintf(dadospf, "\n");
							printf("Digite o email: ");
							gets(email);
							fprintf(dadospf, "%s", email);
							fprintf(dadospf, "\n");
							printf("Digite a cidade: ");
							gets(cidadepf);
							fprintf(dadospf, "%s", cidadepf);
							fprintf(dadospf, "\n\n");
							//fclose(dadospf);
						break;
						
						//cadstro de pessoa juridica
						case 2:
							//Declarando tipo File para gravar em um arquivo texto
							FILE *dadospj;
							FILE *empresaparceira;
							
							// Cria um arquivo texto para grava��o 
							dadospj = fopen("DadosPJ.txt", "a");
							empresaparceira = fopen("EmpresaParceira.txt", "a");
							
							//system("cls");
								printf("Digite o nome da empresa: ");
								scanf("%s", &nomepj);
								fprintf(dadospj, "%s", nomepj);
								fprintf(dadospj, "\n");
							 	fflush(stdin);
								printf("Digite o CNPJ (Somente numeros): ");
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
								scanf("%s", &parceira);
								fprintf(dadospj, "%s", parceira);
								fprintf(dadospj, "\n\n");
								fclose(dadospj);
								fflush(stdin);
								
								/*if(parceira == "S"){
									printf("%s \n%s \n", nomepj, parceira);
								}else if(parceira == "N"){
									printf("Nao e parceira");
								}	else{
									printf("Nao eh parceira");
								}						
										system("pause");*/					
						break;
						
						//cadastro de automovel
						case 3:
							//Declarando tipo File para gravar em um arquivo texto
							FILE *carrodisponivel;
							
							// Cria um arquivo texto para grava��o 
							carrodisponivel = fopen("CarroDisponivel.txt", "a");
							
							//system("cls");
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
				//variavel para ler aquivo
				FILE *listardisponivel;
				
				
				//utilizando variavel para ler o arquivo
				listardisponivel = fopen("CarroDisponivel.txt", "r");
				
				
				system("cls");
				
				//vetor para lista de carros disponiveis
				char listadisponivel;
				
				while(!feof(listardisponivel)){
					
					printf("%c", listadisponivel);

				listadisponivel = fgetc(listardisponivel);
				
				}
				
				fclose(listardisponivel);
				
				printf("1- Voltar ao menu anterior\n");
				scanf("%d", &menu);
			break;
			
			case 5:
				//variavel para ler aquivo
				FILE *listaralugados;
				
				//utilizando variavel para ler o arquivo
				listaralugados = fopen("CarroAlugado.txt", "r");
				
				system("cls");
				
				//vetor para lista de carros disponiveis
				char listaalugado;
				
				while(!feof(listaralugados)){
					
					printf("%c", listaalugado);

				listaalugado = fgetc(listaralugados);
				
				}
				
				fclose(listaralugados);
				
				printf("1- Voltar ao menu anterior\n");
				scanf("%d", &menu);
			break;
			
			case 6:
				system("cls");
				
				
			break;
		}
	}while(menu != 7);
}
