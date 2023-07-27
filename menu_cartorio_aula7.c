#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria (acentos e caracteres especiais)
#include <locale.h> // biblioteca de aloca��es de texto por regi�o (idioma)
#include <string.h> // biblioteca para manipula��o de strings

int cadastrar() //Fun��o responsavel por cadastrar clientes
{
	setlocale(LC_ALL, "PORTUGUESE"); 	//definindo a linguagem
	
	// Cria��o das variaveis/string
	char arquivo[40];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char atividade[40];
	// fim da cria��o das variaveis/string
	
	printf("Informe o CPF a ser cadastrado: "); // comando para coletar o CPF a ser cadastrado
	scanf("%s", cpf); // %s refere-se a string 
	
	strcpy(arquivo, cpf); // comando para copiar os valores da string
	
	FILE *file; // cria arquivo
	file = fopen(arquivo, "w"); // cria o arquivo 
	fprintf(file,cpf); // salva o valor da varialvel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // alteracao do arquivo para incluir virgula
	fprintf(file, ",");
	fclose(file); 
	
	printf("Informe o nome a ser cadastrado: "); // comando para coletar o nome a ser cadastrado
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // alteracao do arquivo para incluir nome
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // alteracao do arquivo para incluir virgula
	fprintf(file, ",");
	fclose(file);
	
	printf("Informe o sobrenome a ser cadastrado: "); // comando para coletar o sobrenome a ser cadastrado 
	scanf("%s",sobrenome);
		
	file = fopen(arquivo, "a"); // alteracao do arquivo para incluir virgula
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // alteracao do arquivo para incluir virgula
	fprintf(file, ",");
	fclose(file);
	
	printf("Informe a atividade do cliente cadastrado: "); // comando para coletar o sobrenome a ser cadastrado
	scanf("%s",atividade);
	
	file = fopen(arquivo, "a"); // alteracao do arquivo para incluir virgula
	fprintf(file, atividade);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "PORTUGUESE"); 	//definindo a linguagem
	
	// criacao das variaveis
	char cpf[11];
	char conteudo[200];
	
	printf("Informe o CPF: "); // comando para solicitar o CPF para pesquisa
	scanf("%s",cpf);
	
	FILE *file; 
	file = fopen(cpf, "r"); // comando para ler a informa��o digitada pelo usu�rio 
	
	//condicionante
	if(file == NULL)
	{
		printf("CPF n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Informa��es do Cliente: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int excluir()
{
	// criacao de variavel
	char cpf[11];
		
	printf("Informe o CPF do cliente a ser exclu�do: "); // comando para solicitar o CPF para pesquisa
	scanf("%s",cpf);
	
	remove(cpf); // comando para exclus�o do cliente informado
	
	FILE *file;
	file = fopen(cpf, "r"); //comando para leitura da informa��o a ser excluida 
	
	// Condicionantes
	if(file != NULL)
	{
		printf("Cliente exclu�do com sucesso!\n");
		system("pause");
	}
	
	if(file == NULL)
	{
		printf("CPF n�o localizado!\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0; // Definindo vari�veis
	int menu=1;
	
	for(menu=1;menu=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "PORTUGUESE"); 	//definindo a linguagem
	
		printf(" -----Cart�rio da EBAC-----\n\n"); 	//in�cio do MENU
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1-Cadastrar Cliente\n");
		printf("\t2-Consultar Cliente\n");
		printf("\t3-Excluir Cliente\n");
		printf("\t4-Sair do Sistema\n\n");
		printf("Op��o: "); //fim do MENU
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
	
		switch(opcao)
		{
		case 1:
		cadastrar();
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
		excluir();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf("Op��o n�o dispon�vel!\n");
		system("pause");
		break;
		}
	}
}
