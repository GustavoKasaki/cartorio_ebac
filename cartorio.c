//Programa C para cadastrar, consultar e remover usuários

#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória (acentuação e simbolos)
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por manusear as strings

int registro() //Menu 1: Função para cadastrar usuários
{
	//início da criação das variáveis
	char arquivo[40];
	char cpf[40]; //"[]" cria uma string (conj. de caracteres do tipo texto)
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação das variáveis
	
	//Tela 1: Obter CPF
	printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n");
	printf("1. Registrar usuário\n\n");
	printf("Insira o CPF: "); //Registro do CPF
	scanf("%s",cpf); //"%s" armazena a informação inserida (CPF) dentro de uma string
	
	strcpy(arquivo,cpf); //"string copy": copia o valor da string
	
	FILE *file; //Comando "FILE" (em maiusculo): ordena o computador à criar/acessar um arquivo denominado por *"nome"
	file=fopen(arquivo,"w"); //"fopen" abre um "arquivo" denominado e cria o arquivo ("w" = write)
	fprintf(file,cpf); //escreve a informação no arquivo
	fclose(file); //fecha o arquivo (LEMBRAR)
	
	file=fopen(arquivo,"a"); //"a" = append/adicionar ao final do arquivo
	fprintf(file,","); //insere um separador na string
	fclose(file);
	
	printf("\nInsira o primeiro nome: "); //Registro do primeiro nome
	scanf("%s",nome);
	file=fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("\nInsira o sobrenome: "); //Registro do sobrenome
	scanf("%s",sobrenome);
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("\nInsira o cargo: "); //Registro do cargo
	scanf("%s",cargo);
	file=fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	//Fim da Tela 1
	
	//Tela 2: Confirmação de cadastro
	system("cls");
	printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n");
	printf("Usuário cadastrado com sucesso!\n\n");
	//Fim da Tela 2
	
	system("pause");
}

int consulta() //Menu 2: Função para consultar usuários
{
	//início da criação das variáveis
	setlocale(LC_ALL,"portuguese");
	char cpf[40];
	char conteudo[200];
	char *token;
	//fim da criação das variáveis

	printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n");
	printf("2. Consultar usuário\n\n");
	printf("Insira o CPF: ");
	scanf("%s",cpf);
	
	FILE *file;
	file=fopen(cpf,"r"); //"r" = read/ler
	
	if(file==NULL) //se não encontrar o valor
	{
		system("cls");
		printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n");
		printf("2. Consultar usuário\n\n");
		printf("Usuário não cadastrado!\n\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL) //"fgets" = procurar no arquivo
	{
		system("cls");
		printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n");
		printf("2. Consultar usuário\n\n");
		printf("Informações do usuário:\n\n");
		
		token=strtok(conteudo,","); //"strtok" = variável que divide a string em linhas a partir do separador definido (no caso, ",")
		printf("CPF: %s\n",token);
		
		token=strtok(NULL,",");
		printf("Nome: %s\n",token);
		
		token=strtok(NULL,",");
		printf("Sobrenome: %s\n",token);
		
		token=strtok(NULL,",");
		printf("Cargo: %s\n",token);
		
		printf("\n\n");
	}

	fclose(file);
	system("pause");
}


int remover() //Menu 3: Função para remover usuários
{
	//início da criação das variáveis
	setlocale(LC_ALL,"portuguese");
	char cpf[40];
	char conteudo[200];
	char *token;
	char opcao;
	//Fim da criação das variáveis

	printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n");
	printf("3. Remover usuário\n\n");
	printf("Insira o CPF: ");
	scanf("%s",cpf);

		
	FILE *file;
	file=fopen(cpf,"r");
	fclose(file);

	
	if(file==NULL) //Caso não exista o usuário
	{
		system("cls");
		printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n");
		printf("3. Remover usuário\n\n");
		printf("CPF não cadastrado!\n\n");
	}
	
	remove(cpf); //remove o arquivo
	
	if(file!=NULL)
	{

		system("cls");
		printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n");
		printf("3. Remover usuário\n\n");
		printf("Usuário removido com sucesso!\n\n");		
	}	
	
	system("pause");
	
}


int main() //Menu Principal
{
	int opcao=0; //definindo a variável opção
	int lasso=1; // definindo a variável lasso
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n"); //lembrar de colocar ";" ao fim de cada comando, para evitar erros
	printf("Login de Administrador:\n");
	printf("\tDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin"); //strcmp = comparação de strings: compara valores
	
	system("cls");
	
	if(comparacao == 0)
	{
		for(lasso=1;lasso=1;) //Laço de repetição (Qualquer input mantém o usuário no mesmo menu, a nâo ser os inputs das opções)
			{
			system("cls"); //limpar a tela
			
			setlocale(LC_ALL, "portuguese"); //define o idioma e acentuação (LC_ALL = linguagens da categoria do texto é "português")
		
			//início do menu
			printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n"); //lembrar de colocar ";" ao fim de cada comando, para evitar erros
			printf("Escolha a opção desejada abaixo:\n");
			printf("\t1. Registrar usuário\n"); //a definição "\t" insere uma indentação
			printf("\t2. Consultar usuário\n");
			printf("\t3. Remover usuário\n"); //não é necessário criar varias linhas, pode-se utilizar as definições "\n" e "\t" conforme demonstrado abaixo
			printf("\t4. Fechar programa\n\n");		
			printf("Opção: ");
		
			//armazenando a escolha do usuário
			scanf("%d",&opcao); //"scanf" solicita input do usuário. "%d" armazena a informação na variável definida no início do programa
		
			system("cls"); //limpar a tela
		
			switch(opcao)
			{
				case 1: //Redireciona ao Menu 1
				registro();
				break;
			
				case 2: //Redireciona ao Menu 2
				consulta();
				break;
			
				case 3: //Redireciona ao Menu 3
				remover();
				break;
			
				case 4: //Encerra o programa
				printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n"); //lembrar de colocar ";" ao fim de cada comando, para evitar erros
				printf("Fechando programa...\n\nAperte qualquer tecla para continuar\n\n");
				return 0;
				break;
			
				default:
				printf("Opção inválida! Tente novamente.\n\n");
				system("Pause");
			}
		}	
	}
	
	else
		printf("==================================\n======== Cartório da EBAC ========\n==================================\n\n");
		printf("Login de Administrador:\n\n");
		printf("Senha Incorreta! Tente novamente.\n\n");
		system("pause");
}
