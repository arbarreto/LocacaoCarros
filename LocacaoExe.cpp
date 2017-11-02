#include<stdio.h>

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
						gets(nomepf);
						printf("Digite seu CPF: ");
						gets(cpf);
						printf("Digite sua idade: ");
						gets(idade);
						printf("Digite seu sexo: ");
						gets(sexo);
						printf("Digite seu telefone: ");
						gets(telpf);
						printf("Digite seu email: ");
						gets(email);
						printf("Digite sua cidade: ");
						gets(cidadepf);
					break;
					
					//cadstro de pessoa juridica
					case 2:
							printf("Digite o nome da empresa: ");
							gets(nomepj);
							printf("Digite o CNPJ: ");
							gets(cnpj);
							printf("Digite o telefone: ");
							gets(telpj);
							printf("Digite a cidade: ");
							gets(cidadepj);
							printf("Empresa e parceira (S/N)? ");
							gets(parceira);
					break;
					
					//cadastro de automovel
					case 3:
						printf("Digite a placa do carro: ");
						gets(placacarro);	
						printf("Digite o modelo do carro: ");
						gets(modelo);
						printf("Digite o ano do carro: ");
						gets(ano);
						printf("Digite o fabricante do carro: ");
						gets(fabricante);						
					break;	
				
				}
		break;
		
	}
}
