#include<stdio.h>
#include<string.h>


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
	//Declarando tipo File para gravar em um arquivo texto
	FILE *dadospf;
	FILE *dadospj;
	FILE *cadastroaut;
	//Variavel para gravação no arquivo
	//char gravarnomepf, gravarcpf, gravaridade, gravarsexo, gravartelpf, gravaremail, gravarcidadepf;
	// Cria um arquivo texto para gravação
	dadospf = fopen("DadosPF.txt", "a");
	dadospj = fopen("DadosPJ.txt", "a");
	cadastroaut = fopen("CadastroAut.txt", "a");
	int i;
	
	//menu principal
	printf("Escolha uma opcao do menu:\n 1- Cadastrar\n 2- Alugar\n 3- Devolver\n 4- Automoveis Disponiveis\n 5- Automoveis Alugados\n 6- Empresas Parceiras\n 7- Sair\n ");
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
						printf("Digite seu nome: ");
						scanf("%s", &nomepf);
						//escrevendo no final do arquivo, sendo o f do começo de file
						fprintf(dadospf, "%s", nomepf);
						fprintf(dadospf, "\n");
						//Limpa a memoria do teclado
						 fflush(stdin);
						printf("Digite seu CPF: ");
						gets(cpf);
						//escrevendo no final do arquivo, sendo o f do começo de file
						fprintf(dadospf, "%s", cpf);
						fprintf(dadospf, "\n");
						printf("Digite sua idade: ");
						gets(idade);
						//escrevendo no final do arquivo, sendo o f do começo de file
						fprintf(dadospf, "%s", idade);
						fprintf(dadospf, "\n");
						printf("Digite seu sexo: ");
						gets(sexo);
						//escrevendo no final do arquivo, sendo o f do começo de file
						fprintf(dadospf, "%s", sexo);
						fprintf(dadospf, "\n");
						printf("Digite seu telefone: ");
						gets(telpf);
						//escrevendo no final do arquivo, sendo o f do começo de file
						fprintf(dadospf, "%s", telpf);
						fprintf(dadospf, "\n");
						printf("Digite seu email: ");
						gets(email);
						//escrevendo no final do arquivo, sendo o f do começo de file
						fprintf(dadospf, "%s", email);
						fprintf(dadospf, "\n");
						printf("Digite sua cidade: ");
						gets(cidadepf);
						//escrevendo no final do arquivo, sendo o f do começo de file
						fprintf(dadospf, "%s", cidadepf);
						fprintf(dadospf, "\n\n");
						fclose(dadospf);
					break;
					
					//cadstro de pessoa juridica
					case 2:
							printf("Digite o nome da empresa: ");
							scanf("%s", &nomepj);
							//escrevendo no final do arquivo, sendo o f do começo de file
							fprintf(dadospj, "%s", nomepj);
							fprintf(dadospj, "\n");
						 	fflush(stdin);
							printf("Digite o CNPJ: ");
							gets(cnpj);
							//escrevendo no final do arquivo, sendo o f do começo de file
							fprintf(dadospj, "%s", cnpj);
							fprintf(dadospj, "\n");
							printf("Digite o telefone: ");
							gets(telpj);
							//escrevendo no final do arquivo, sendo o f do começo de file
							fprintf(dadospj, "%s", telpj);
							fprintf(dadospj, "\n");
							printf("Digite a cidade: ");
							gets(cidadepj);
							//escrevendo no final do arquivo, sendo o f do começo de file
							fprintf(dadospj, "%s", cidadepj);
							fprintf(dadospj, "\n");
							printf("Empresa e parceira (S/N)? ");
							gets(parceira);
							//escrevendo no final do arquivo, sendo o f do começo de file
							fprintf(dadospj, "%s", parceira);
							fprintf(dadospj, "\n\n");
					break;
					
					//cadastro de automovel
					case 3:
						printf("Digite a placa do carro (XXX-000): ");
						scanf("%s", &placacarro);
						//escrevendo no final do arquivo, sendo o f do começo de file
						fprintf(cadastroaut, "%s", placacarro);
						fprintf(cadastroaut, "\n");
						fflush(stdin);	
						printf("Digite o modelo do carro: ");
						gets(modelo);
						//escrevendo no final do arquivo, sendo o f do começo de file
						fprintf(cadastroaut, "%s", modelo);
						fprintf(cadastroaut, "\n");
						printf("Digite o ano do carro : ");
						gets(ano);
						//escrevendo no final do arquivo, sendo o f do começo de file
						fprintf(cadastroaut, "%s", ano);
						fprintf(cadastroaut, "\n");
						printf("Digite o fabricante do carro: ");
						gets(fabricante);
						//escrevendo no final do arquivo, sendo o f do começo de file
						fprintf(cadastroaut, "%s", fabricante);
						fprintf(cadastroaut, "\n\n");					
					break;	
				
				}
		break;
		
	}
}
