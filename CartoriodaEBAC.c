#include <stdio.h> //comunicacao com o usuario
#include <stdlib.h> //alocando espaco na memoria
#include <locale.h> //definir linguagem
#include <string.h> //biblioteca string

int registro(){ //funcao para registrar os usuarios no banco de dados
	printf("Você escolheu o Registro de nomes!\n\n");
	
	//variaveis dos dados do cliente
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletar informacao do usuario
	scanf("%s",&cpf);
	
	strcpy(arquivo , cpf); // copiar valores das strings
	
	FILE *file; //cria o arquivo no banco de dados 
	file = fopen(arquivo, "w"); //abre o arquivo , o "w" cria um arquivo e se ele ja existir sobrescreve os dados
	fprintf(file,cpf); //salva valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo , o "a" abre o arquivo para adicao de novos dados
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo , "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("\nUsuario registrado com sucesso!");
	
	system("pause");
}

int consulta(){
	printf("Você escolheu a Consulta de nomes!\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
		{
			printf("Nao foi possivel abrir o  arquivo, nao localizado! \n");
		}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	
	system("pause");
}

int remover(){ //funcao para remover usuario do banco de dados
	printf("Você escolheu a Remoção de nomes!\n");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema!\n");
	}
	else
	{
		printf("Usuario %s deletado do sistema!",cpf);
		remove(cpf);
	}
	system("pause");
}


int sair(){ //funcao para sair do menu
	printf("Muito Obrigado !");
	exit(0); //encerra o programa
}

int main(){
	
	int x = 1 , op = 0;
	
	for (x=1;x=1;){
		
		system("cls"); //limpar a tela
	
		setlocale(LC_ALL, "Portuguese");
	
		printf("### Cartório da EBAC ###\n\n "); //menu
		printf("Escolha a opção desejada no menu \n\n");
		printf("\t1 - Registrar um nome\n");
		printf("\t2 - Consultar um nome\n");
		printf("\t3 - Remover um nome\n");
		printf("\t4 - Fechar o programa\n\n");
		printf("Opção :");
	
		scanf("%d",&op); //leitura 
	
		system("cls"); //limpar a tela
		
		switch(op){ //selecao de opcoes
			
			case 1:
			registro(); //chamada de funcao
			break;
			
			case 2:
			consulta(); //chamada de funcao
			break;
			
			case 3:
			remover(); //chamada de funcao
			break;
			
			case 4:
			sair(); //chamada de funcao
			break;
			
			default: // cliente que escolher uma opcao invalida do menu
			printf("Essa opção não existe, tente novamente.\n");
			system("pause");
			break;	
			
		}
	
		
	
	}
}
