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

//Função para chamar arquivo indicando que é do tipo FILE
FILE* ChamaArquivo(char caminho[30], char tipo){
	FILE *arquivo;
	
	switch(tipo){ //Opções do tipo de abertura do arquivo
		
		case 'c': //Cria o arquivo caso não existente
			arquivo = fopen(caminho, "wt");
		break;
		
		case 'l': //Lê o arquivo
			arquivo = fopen(caminho, "rt");
		break;
		
		case 'g':
			arquivo = fopen(caminho, "a"); //Grava ao final do arquivo sem perder nenum dado
		break; 
	}
	
	if(arquivo==NULL){ //Verifica se o arquivo é invalido
		printf("Arquivo nao encontrado.\n");
		exit(0); //Fecha o programa caso não tenha encontrado o arquivo
	}
	return arquivo; //Retorna o arquivo para manipulação
}
//Funcao para fechar o arquivo
void FecharArquivo(FILE *arquivo){
	fclose(arquivo);
}

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
							arquivo = ChamaArquivo("DadosPF.txt", 'g'); //chamando função do arquivo e atribuindo a arquivo
							
							fflush(stdin); //limpa memoria do teclado
							//cadastro de pessoa fisica	
							printf("Digite o CPF (Somente numeros): ");
							scanf("%s", &dadospf.cpf);
							fprintf(arquivo, "%s", dadospf.cpf);
							fflush(stdin);
							printf("Digite o nome: ");
							gets(dadospf.nomepf);
							fprintf(arquivo, "\n%s", dadospf.nomepf); //gravando no arquivo
							fflush(stdin);
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

							
							fflush(stdin);//limpa memoria do teclado
							//cadastro de pessoa juridica
							printf("Digite o CNPJ (Somente numeros): ");
							scanf("%s", &dadospj.cnpj[i]);
							fprintf(arquivo, "%s", dadospj.cnpj);
							fflush(stdin); 
							printf("Digite o nome da empresa: ");
							gets(dadospj.nomepj);
							fprintf(arquivo, "\n%s", dadospj.nomepj); //gravando no arquivo
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
							
							FecharArquivo(arquivo); // Chama função de fechar arquivo
							
							arquivo = ChamaArquivo("EmpresaParceira.txt", 'g');
							//declarando e atribuindo a palavra Sim para 
							//comparação com o que foi digitado em parceira
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
							
							FecharArquivo(arquivo); // Chama função de fechar arquivo
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
							arquivo = ChamaArquivo("DadosPF.txt", 'l');
							char cpflocador[10];
							char placalocador[10];
							char modelo[20];
							char nomepf[20];
							char linha[800];
							int l=0, diaria=0;
							time_t data_tempo;
							time(&data_tempo);
							
							struct tm *tempo = localtime(&data_tempo);
							struct tm *data = localtime(&data_tempo);
							
							system("cls");
								
							printf("Digite o CPF(Somente numeros): ");
							scanf("%s", &cpflocador);
					
							while(fgets(linha, 800, arquivo)){
								l++;
								if(strstr(linha, cpflocador) != NULL){
									l++;
									fgets(nomepf, 20, arquivo);
									
								}
							}

							FecharArquivo(arquivo); // Chama função de fechar arquivo
							arquivo = ChamaArquivo("CarroDisponivel.txt", 'l');
							
							printf("Digite a placa do carro desejado (XXX-0000): ");
							scanf("%s", &placalocador);
							l=0;
							while(fgets(linha, 800, arquivo)){
								l++;
								if(strstr(linha, placalocador) != NULL){
									l++;
									fgets(modelo, 20, arquivo);
								}
							}
							FecharArquivo(arquivo); // Chama função de fechar arquivo
							
							printf("Digite a quantidade de diarias: ");
							scanf("%d", &diaria);
							
							printf("\n\n\n+---------------------------------------+\n  Nome: %s", nomepf);
							printf("  Placa do Carro: %s\n", placalocador);
							printf("  Modelo: %s", modelo);
							printf("  Retirada: %d/%d/%d-%i:%i:%i\n", data->tm_mday, data->tm_mon, data->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec );
							printf("  Devolucao: %d/%d/%d-%i:%i:%i\n", data->tm_mday + diaria, data->tm_mon, data->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec );
							printf("+---------------------------------------+\n\n");
							
							arquivo = ChamaArquivo("CarroAlugado.txt", 'g');
							
							fprintf(arquivo,"%s", placalocador);
							fprintf(arquivo,"\n%s", modelo);
							fprintf(arquivo, "%d/%d/%d-%i:%i:%i\n\n", data->tm_mday + diaria, data->tm_mon, data->tm_year + 1900, tempo->tm_hour, tempo->tm_min, tempo->tm_sec );
							FecharArquivo(arquivo); // Chama função de fechar arquivo
							
							printf("1- Voltar ao menu principal\n");
							scanf("%d", &menu);
						break;
						
					}
			break;
			case 3:
				system("cls");
				
				printf("\t\t\tLegal Rent a Car - Devolver Carro\n\n");
				printf("Escolha uma opcao de locador:\n 1- Pessoa Fisica\n 2- Pessoa Juridica\n");
				scanf("%d", &devolver);
				
					switch(devolver){
						case 1:
							arquivo = ChamaArquivo("DadosPF.txt", 'l');
							char cpflocador[10];
							char placalocador[10];
							char modelo[20];
							char nomepf[20];
							char idade[3];
							char linha[800];
							char idoso[2];
							int l=0, diaria=0;
							float valordiaria=105.35, valortotal, desconto;
							strcpy(idoso, "20");
							system("cls");
								
							printf("Digite o CPF(Somente numeros): ");
							scanf("%s", &cpflocador);
							
							while(fgets(linha, 800, arquivo)){
								l++;
								if(strstr(linha, cpflocador) != NULL){
									l++;
									fgets(nomepf, 20, arquivo);
									l++;
									fgets(idade, 3, arquivo);
								}
							}
							FecharArquivo(arquivo); // Chama função de fechar arquivo
							arquivo = ChamaArquivo("CarroAlugado.txt", 'l');
							
							printf("Digite a placa do carro desejado (XXX-0000): ");
							scanf("%s", &placalocador);
							l=0;
							while(fgets(linha, 800, arquivo)){
								l++;
								if(strstr(linha, placalocador) != NULL){
									l++;
									fgets(modelo, 20, arquivo);
								}
							}
							FecharArquivo(arquivo); // Chama função de fechar arquivo
							
							printf("Digite a quantidade de diarias: ");
							scanf("%d", &diaria);
							
							valortotal=valordiaria*diaria;
							
							if(strcmp(idoso, idade)){
								desconto = valortotal*0.1;
								valortotal = valortotal-desconto;
								
							printf("\n\n\n+---------------------------------------+\n  Nome: %s", nomepf);
							printf("  Placa do Carro: %s\n", placalocador);
							printf("  Modelo: %s", modelo);
							printf("  Valor total: %.2f\n", valortotal);
							printf("+---------------------------------------+\n\n");
								
							}else{
							printf("\n\n\n+---------------------------------------+\n  Nome: %s", nomepf);
							printf("  Placa do Carro: %s\n", placalocador);
							printf("  Modelo: %s", modelo);
							printf("Valor total: %.2f\n", valortotal);
							printf("+---------------------------------------+\n\n");
							}
							
							printf("1- Voltar ao menu principal\n");
							scanf("%d", &menu);
						break;
						
					}
			break;
			case 4:
				arquivo = ChamaArquivo("CarroDisponivel.txt", 'l'); //chamando função do arquivo e atribuindo a arquivo
				system("cls");
				
				printf("\t\t\tLegal Rent a Car - Carros Disponiveis\n\n");
				
				char placacarro[9];
				char modelo[20];
				int ano;
				char fabricante[20];
				//laço de repetição enquanto não chegar ao final do arquivo
				while(!feof(arquivo)){
					//lista o que contem no arquivo
					fscanf(arquivo, "%s", &placacarro);
					fscanf(arquivo, "\n%s", &modelo);
					fscanf(arquivo, "\n%d", &ano);
					fscanf(arquivo, "\n%s\n\n", &fabricante);
					printf("Placa: %s\nModelo: %s\nAno: %d\nFabricante: %s\n\n", placacarro, modelo, ano, fabricante);
				}
				FecharArquivo(arquivo); // Chama função de fechar arquivo
				
				printf("1- Voltar ao menu principal\n");
				scanf("%d", &menu);				
			break;
			case 5:
				arquivo = ChamaArquivo("CarroAlugado.txt", 'l'); //chamando função do arquivo e atribuindo a arquivo
				system("cls");
				
				
				char devolucao[30];
				
				printf("\t\t\tLegal Rent a Car - Carros Alugados\n\n");
				
				//laço de repetição enquanto não chegar ao final do arquivo
				while(!feof(arquivo)){
					//lista o que contem no arquivo
					fscanf(arquivo, "%s", &placacarro);
					fscanf(arquivo, "\n%s", &modelo);
					fscanf(arquivo, "\n%s", &devolucao);
					printf("Placa: %s\nModelo: %s\nDevolucao: %s\n", placacarro, modelo, devolucao);
				}
				FecharArquivo(arquivo); // Chama função de fechar arquivo
				
				printf("1- Voltar ao menu principal\n");
				scanf("%d", &menu);				
			break;
			case 6:
				arquivo = ChamaArquivo("EmpresaParceira.txt", 'l'); //chamando função do arquivo e atribuindo a arquivo
				system("cls");
				
				printf("\t\t\tLegal Rent a Car - Empresas Parceiras\n\n");
				
				char nomepj[20];
				char cnpj[20];
				//laço de repetição enquanto não chegar ao final do arquivo
				while(!feof(arquivo)){
					//lista o que contem no arquivo
					fscanf(arquivo, "%s", &nomepj);
					fscanf(arquivo, "\n%s\n\n", &cnpj);
					printf("Empresa: %s\nCNPJ: %s\n\n", nomepj, cnpj);
				}
				FecharArquivo(arquivo); // Chama função de fechar arquivo
				
				printf("1- Voltar ao menu principal\n");
				scanf("%d", &menu);	
			break;
		}
	
	}
}
