#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <conio.h>
#include <time.h>

//Variaveis para cadastro de pessoa fisica
struct pessoafisica{
	char nomepf[20];
	char cpf[15];
	int idade;
	char sexo[3];
	int telpf;
	char email[30];
	char cidadepf[20];
};
//Variaveis de cadastro de pessoa juridica
struct pessoajuridica{
	char nomepj[20];
	char cnpj[20];
	int telpj;
	char cidadepj[30];
	char parceira[3];
};
//Variaveis de cadastro de carro
struct carro{
	char placacarro[9];
	char modelo[20];
	int ano;
	char fabricante[20];
};

//Fun��o para chamar arquivo indicando que � do tipo FILE
FILE* ChamaArquivo(char caminho[30], char tipo){
	FILE *arquivo;
	
	switch(tipo){ //Op��es do tipo de abertura do arquivo
		
		case 'c': //Cria o arquivo caso n�o existente
			arquivo = fopen(caminho, "wt");
		break;
		
		case 'l': //L� o arquivo
			arquivo = fopen(caminho, "rt");
		break;
		
		case 'g':
			arquivo = fopen(caminho, "a"); //Grava ao final do arquivo sem perder nenum dado
		break; 
	}
	
	if(arquivo==NULL){ //Verifica se o arquivo � invalido
		printf("Arquivo nao encontrado.\n");
		exit(0); //Fecha o programa caso n�o tenha encontrado o arquivo
	}
	return arquivo; //Retorna o arquivo para manipula��o
}
//Funcao para fechar o arquivo
void FecharArquivo(FILE *arquivo){
	fclose(arquivo);
}
/*
int BuscaCPF(File *arquivo){
	//codigo da busca de cpf
	
	return 0;
}

int BuscaCNPJ(File *arquivo){
	//codigo da busca de cnpj
	
	return 0;
}

int BuscaPlaca(File *arquivo){
	//codigo da busca de placa do carro
	
	return 0;
}
*/
struct pessoafisica dadospf;
struct pessoajuridica dadospj;
struct carro dadoscarro;


int main(){
	//variaveis para switch do menu principal
	int menu, cadastrar, alugar, devolver, disponivel, alugados, empresapar, sair;
	
	while(menu != 7){
		FILE *arquivo; //declarando variavel do ponteiro arquvio
		int i; //variavel para posicao do vetor
		system("cls"); //limpa a tela
		 
		printf("\t\t\tLegal Rent a Car\n\n"); //Apresenta nome da empresa
		//Menu principal
		printf("Escolha uma opcao do menu:\n 1- Cadastrar\n 2- Alugar\n 3- Devolver\n 4- Carros Disponiveis\n 5- Carros Alugados\n 6- Empresas Parceiras\n 7- Sair\n");
		scanf("%d", &menu);
		//escolhas do menu principal
		switch(menu){
			case 1:
				system("cls");
				
				printf("\t\t\tLegal Rent a Car - Cadastro\n\n");
				//submenu da opcao cadastrar
				printf("Escolha uma opcao de cadastro:\n 1- Pessoa Fisica\n 2- Pessoa Juridica\n 3- Automovel\n 4- Voltar ao menu anterior\n");
				scanf("%d", &cadastrar);
					//escolhas submenu cadastrar
					switch(cadastrar){
						case 1:
							system("cls");
				
							printf("\t\t\tLegal Rent a Car - Cadastrar Pessoa Fisica\n\n");
							arquivo = ChamaArquivo("DadosPF.txt", 'g'); //chamando fun��o do arquivo e atribuindo a arquivo
							
							fflush(stdin); //limpa memoria do teclado
							//cadastro de pessoa fisica
							printf("Digite o nome: ");
							gets(dadospf.nomepf);
							fprintf(arquivo, "%s", dadospf.nomepf); //gravando no arquivo
							fflush(stdin);
							printf("Digite o CPF (Somente numeros): ");
							scanf("%s", &dadospf.cpf);
							fprintf(arquivo, "\n%s", dadospf.cpf);
							printf("Digite a idade: ");
							scanf("%d", &dadospf.idade);
							fprintf(arquivo, "\n%d", dadospf.idade);//gravando no arquivo
							fflush(stdin);
							printf("Digite o sexo (F/M): ");
							scanf("%s", &dadospf.sexo[i]);
							fprintf(arquivo, "\n%s", dadospf.sexo); //gravando no arquivo
							fflush(stdin);
							printf("Digite o telefone (Somente numeros): ");
							scanf("%d", &dadospf.telpf);
							fprintf(arquivo, "\n%d", dadospf.telpf); //gravando no arquivo
							fflush(stdin);
							printf("Digite o email: ");
							scanf("%s", &dadospf.email[i]);
							fprintf(arquivo, "\n%s", dadospf.email); //gravando no arquivo
							fflush(stdin);
							printf("Digite a cidade: ");
							scanf("%s", &dadospf.cidadepf[i]);
							fprintf(arquivo, "\n%s\n\n", dadospf.cidadepf); //gravando no arquivo
							fflush(stdin);
							
							FecharArquivo(arquivo); //Chama funcao de fechar o arquivo
							printf("\n1- Voltar ao menu principal\n");
							scanf("%d", &menu);	
						break;
						case 2:
							system("cls");
				
							printf("\t\t\tLegal Rent a Car - Cadastrar Pessoa Juridica\n\n");
							arquivo = ChamaArquivo("DadosPJ.txt", 'g');

							fflush(stdin); //limpa memoria do teclado
							//cadastro de pessoa juridica
							printf("Digite o nome da empresa: ");
							gets(dadospj.nomepj);
							fprintf(arquivo, "%s", dadospj.nomepj); //gravando no arquivo
							fflush(stdin);
							printf("Digite o CNPJ (Somente numeros): ");
							scanf("%s", &dadospj.cnpj[i]);
							fprintf(arquivo, "\n%s", dadospj.cnpj);
							fflush(stdin);
							printf("Digite o telefone (Somente numeros): ");
							scanf("%d", &dadospj.telpj);
							fprintf(arquivo, "\n%d", dadospj.telpj); //gravando no arquivo
							fflush(stdin);
							printf("Digite a cidade: ");
							scanf("%s", &dadospj.cidadepj[i]);
							fprintf(arquivo, "\n%s", dadospj.cidadepj); //gravando no arquivo
							fflush(stdin);
							printf("Empresa eh parceira? (Sim/Nao): ");
							scanf("%s", &dadospj.parceira[i]);
							fprintf(arquivo, "\n%s\n\n", dadospj.parceira); //gravando no arquivo
							fflush(stdin);
							
							FecharArquivo(arquivo); // Chama fun��o de fechar arquivo
							
							arquivo = ChamaArquivo("EmpresaParceira.txt", 'g');
							//declarando e atribuindo a palavra Sim para 
							//compara��o com o que foi digitado em parceira
							char comp1[3], comp2[3];
							strcpy(comp1, "Sim");
							strcpy(comp2, "sim");
								//compara Sim com o que foi digitado em parceiras
								if(strcmp(comp1,dadospj.parceira)){
								//gravano arquivo se for igual a Sim
								}else{
									fprintf(arquivo, "%s", dadospj.nomepj);
									fprintf(arquivo, "\n%s\n\n", dadospj.cnpj);
									}
									//compara sim com o que foi digitado em parceiras
									if(strcmp(comp2,dadospj.parceira)){
									//gravano arquivo se for igual a sim
									}else{
										fprintf(arquivo, "%s", dadospj.nomepj);
										fprintf(arquivo, "\n%s\n\n", dadospj.cnpj);
									}
									
							FecharArquivo(arquivo);
										
							printf("\n1- Voltar ao menu principal\n");
							scanf("%d", &menu);	
							
						break;
						case 3:
							system("cls");
				
							printf("\t\t\tLegal Rent a Car - Cadastrar Carro\n\n");
							arquivo = ChamaArquivo("CarroDisponivel.txt", 'g');
							
							fflush(stdin); //limpa memoria do teclado
							//cadastro de carro
							printf("Digite a placa do carro (XXX-0000): ");
							scanf("%s", &dadoscarro.placacarro);
							fprintf(arquivo, "%s", dadoscarro.placacarro); //gravando no arquivo
							fflush(stdin);
							printf("Digite o modelo do carro: ");
							scanf("%s", &dadoscarro.modelo[i]);
							fprintf(arquivo, "\n%s", dadoscarro.modelo);
							fflush(stdin);
							printf("Digite o ano do carro : ");
							scanf("%d", &dadoscarro.ano);
							fprintf(arquivo, "\n%d", dadoscarro.ano); //gravando no arquivo
							fflush(stdin);
							printf("Digite o fabricante do carro: ");
							scanf("%s", &dadoscarro.fabricante);
							fprintf(arquivo, "\n%s\n\n", dadoscarro.fabricante); //gravando no arquivo
							fflush(stdin);
							
							FecharArquivo(arquivo); // Chama fun��o de fechar arquivo
							printf("\n1- Voltar ao menu principal\n");
							scanf("%d", &menu);	
						break;
					}
			break;
			case 2:
				system("cls");
				
				printf("\t\t\tLegal Rent a Car - Alugar Carro\n\n");
				printf("Escolha uma opcao de locador:\n 1- Pessoa Fisica\n 2- Pessoa Juridica\n");
				scanf("%d", &alugar);
					//escolhas submenu aludar
					switch(alugar){
						case 1:
							
							
							
						break;
					}
			break;
			case 4:
				arquivo = ChamaArquivo("CarroDisponivel.txt", 'l'); //chamando fun��o do arquivo e atribuindo a arquivo
				system("cls");
				
				printf("\t\t\tLegal Rent a Car - Carros Disponiveis\n\n");
				
				char placacarro[9];
				char modelo[20];
				int ano;
				char fabricante[20];
				//la�o de repeti��o enquanto n�o chegar ao final do arquivo
				while(!feof(arquivo)){
					//lista o que contem no arquivo
					fscanf(arquivo, "%s", &placacarro);
					fscanf(arquivo, "\n%s", &modelo);
					fscanf(arquivo, "\n%d", &ano);
					fscanf(arquivo, "\n%s\n\n", &fabricante);
					printf("Placa: %s\nModelo: %s\nAno: %d\nFabricante: %s\n\n", placacarro, modelo, ano, fabricante);
				}
				FecharArquivo(arquivo); // Chama fun��o de fechar arquivo
				
				printf("1- Voltar ao menu principal\n");
				scanf("%d", &menu);				
			break;
			case 5:
				arquivo = ChamaArquivo("CarroAlugado.txt", 'l'); //chamando fun��o do arquivo e atribuindo a arquivo
				system("cls");
				
				printf("\t\t\tLegal Rent a Car - Carros Alugados\n\n");
				
				//la�o de repeti��o enquanto n�o chegar ao final do arquivo
				while(!feof(arquivo)){
					//lista o que contem no arquivo
					fscanf(arquivo, "%s", &placacarro);
					fscanf(arquivo, "\n%s", &modelo);
					fscanf(arquivo, "\n%d", &ano);
					fscanf(arquivo, "\n%s\n\n", &fabricante);
					printf("Placa: %s\nModelo: %s\nAno: %d\nFabricante: %s\n", placacarro, modelo, ano, fabricante);
					printf("Devolucao: 5/12/2017 - 14:33:34\n\n");
				}
				FecharArquivo(arquivo); // Chama fun��o de fechar arquivo
				
				printf("1- Voltar ao menu principal\n");
				scanf("%d", &menu);				
			break;
			case 6:
				arquivo = ChamaArquivo("EmpresaParceira.txt", 'l'); //chamando fun��o do arquivo e atribuindo a arquivo
				system("cls");
				
				printf("\t\t\tLegal Rent a Car - Empresas Parceiras\n\n");
				
				char nomepj[20];
				char cnpj[20];
				//la�o de repeti��o enquanto n�o chegar ao final do arquivo
				while(!feof(arquivo)){
					//lista o que contem no arquivo
					fscanf(arquivo, "%s", &nomepj);
					fscanf(arquivo, "\n%s\n\n", &cnpj);
					printf("Empresa: %s\nCNPJ: %s\n\n", nomepj, cnpj);
				}
				FecharArquivo(arquivo); // Chama fun��o de fechar arquivo
				
				printf("1- Voltar ao menu principal\n");
				scanf("%d", &menu);	
			break;
		}
	
	}
}