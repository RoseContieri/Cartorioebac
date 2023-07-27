#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória (acentos e caracteres especiais)
#include <locale.h> // biblioteca de alocações de texto por região (idioma)
#include <string.h> // biblioteca para manipulação de strings

int cadastrar() //Função responsavel por cadastrar clientes
{
	setlocale(LC_ALL, "PORTUGUESE"); 	//definindo a linguagem
	
	// Criação das variaveis/string
	char arquivo[40];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char atividade[40];
	// fim da criação das variaveis/string
	
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
	file = fopen(cpf, "r"); // comando para ler a informação digitada pelo usuário 
	
	//condicionante
	if(file == NULL)
	{
		printf("CPF não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Informações do Cliente: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int excluir()
{
	// criacao de variavel
	char cpf[11];
		
	printf("Informe o CPF do cliente a ser excluído: "); // comando para solicitar o CPF para pesquisa
	scanf("%s",cpf);
	
	remove(cpf); // comando para exclusão do cliente informado
	
	FILE *file;
	file = fopen(cpf, "r"); //comando para leitura da informação a ser excluida 
	
	// Condicionantes
	if(file != NULL)
	{
		printf("Cliente excluído com sucesso!\n");
		system("pause");
	}
	
	if(file == NULL)
	{
		printf("CPF não localizado!\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0; // Definindo variáveis
	int menu=1;
	
	for(menu=1;menu=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "PORTUGUESE"); 	//definindo a linguagem
	
		printf(" -----Cartório da EBAC-----\n\n"); 	//início do MENU
		printf("Escolha a opção desejada:\n\n");
		printf("\t1-Cadastrar Cliente\n");
		printf("\t2-Consultar Cliente\n");
		printf("\t3-Excluir Cliente\n");
		printf("\t4-Sair do Sistema\n\n");
		printf("Opção: "); //fim do MENU
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
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
		printf("Opção não disponível!\n");
		system("pause");
		break;
		}
	}
}
