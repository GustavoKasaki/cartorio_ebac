//Programa C para cadastrar, consultar e remover usu�rios

#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria (acentua��o e simbolos)
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por manusear as strings

int registro() //Menu 1: Fun��o para cadastrar usu�rios
{
	//in�cio da cria��o das vari�veis
	char arquivo[40];
	char cpf[40]; //"[]" cria uma string (conj. de caracteres do tipo texto)
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o das vari�veis
	
	//Tela 1: Obter CPF
	printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n");
	printf("1. Registrar usu�rio\n\n");
	printf("Insira o CPF: "); //Registro do CPF
	scanf("%s",cpf); //"%s" armazena a informa��o inserida (CPF) dentro de uma string
	
	strcpy(arquivo,cpf); //"string copy": copia o valor da string
	
	FILE *file; //Comando "FILE" (em maiusculo): ordena o computador � criar/acessar um arquivo denominado por *"nome"
	file=fopen(arquivo,"w"); //"fopen" abre um "arquivo" denominado e cria o arquivo ("w" = write)
	fprintf(file,cpf); //escreve a informa��o no arquivo
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
	
	//Tela 2: Confirma��o de cadastro
	system("cls");
	printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n");
	printf("Usu�rio cadastrado com sucesso!\n\n");
	//Fim da Tela 2
	
	system("pause");
}

int consulta() //Menu 2: Fun��o para consultar usu�rios
{
	//in�cio da cria��o das vari�veis
	setlocale(LC_ALL,"portuguese");
	char cpf[40];
	char conteudo[200];
	char *token;
	//fim da cria��o das vari�veis

	printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n");
	printf("2. Consultar usu�rio\n\n");
	printf("Insira o CPF: ");
	scanf("%s",cpf);
	
	FILE *file;
	file=fopen(cpf,"r"); //"r" = read/ler
	
	if(file==NULL) //se n�o encontrar o valor
	{
		system("cls");
		printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n");
		printf("2. Consultar usu�rio\n\n");
		printf("Usu�rio n�o cadastrado!\n\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL) //"fgets" = procurar no arquivo
	{
		system("cls");
		printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n");
		printf("2. Consultar usu�rio\n\n");
		printf("Informa��es do usu�rio:\n\n");
		
		token=strtok(conteudo,","); //"strtok" = vari�vel que divide a string em linhas a partir do separador definido (no caso, ",")
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


int remover() //Menu 3: Fun��o para remover usu�rios
{
	//in�cio da cria��o das vari�veis
	setlocale(LC_ALL,"portuguese");
	char cpf[40];
	char conteudo[200];
	char *token;
	char opcao;
	//Fim da cria��o das vari�veis

	printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n");
	printf("3. Remover usu�rio\n\n");
	printf("Insira o CPF: ");
	scanf("%s",cpf);

		
	FILE *file;
	file=fopen(cpf,"r");
	fclose(file);

	
	if(file==NULL) //Caso n�o exista o usu�rio
	{
		system("cls");
		printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n");
		printf("3. Remover usu�rio\n\n");
		printf("CPF n�o cadastrado!\n\n");
	}
	
	remove(cpf); //remove o arquivo
	
	if(file!=NULL)
	{

		system("cls");
		printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n");
		printf("3. Remover usu�rio\n\n");
		printf("Usu�rio removido com sucesso!\n\n");		
	}	
	
	system("pause");
	
}


int main() //Menu Principal
{
	int opcao=0; //definindo a vari�vel op��o
	int lasso=1; // definindo a vari�vel lasso
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n"); //lembrar de colocar ";" ao fim de cada comando, para evitar erros
	printf("Login de Administrador:\n");
	printf("\tDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin"); //strcmp = compara��o de strings: compara valores
	
	system("cls");
	
	if(comparacao == 0)
	{
		for(lasso=1;lasso=1;) //La�o de repeti��o (Qualquer input mant�m o usu�rio no mesmo menu, a n�o ser os inputs das op��es)
			{
			system("cls"); //limpar a tela
			
			setlocale(LC_ALL, "portuguese"); //define o idioma e acentua��o (LC_ALL = linguagens da categoria do texto � "portugu�s")
		
			//in�cio do menu
			printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n"); //lembrar de colocar ";" ao fim de cada comando, para evitar erros
			printf("Escolha a op��o desejada abaixo:\n");
			printf("\t1. Registrar usu�rio\n"); //a defini��o "\t" insere uma indenta��o
			printf("\t2. Consultar usu�rio\n");
			printf("\t3. Remover usu�rio\n"); //n�o � necess�rio criar varias linhas, pode-se utilizar as defini��es "\n" e "\t" conforme demonstrado abaixo
			printf("\t4. Fechar programa\n\n");		
			printf("Op��o: ");
		
			//armazenando a escolha do usu�rio
			scanf("%d",&opcao); //"scanf" solicita input do usu�rio. "%d" armazena a informa��o na vari�vel definida no in�cio do programa
		
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
				printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n"); //lembrar de colocar ";" ao fim de cada comando, para evitar erros
				printf("Fechando programa...\n\nAperte qualquer tecla para continuar\n\n");
				return 0;
				break;
			
				default:
				printf("Op��o inv�lida! Tente novamente.\n\n");
				system("Pause");
			}
		}	
	}
	
	else
		printf("==================================\n======== Cart�rio da EBAC ========\n==================================\n\n");
		printf("Login de Administrador:\n\n");
		printf("Senha Incorreta! Tente novamente.\n\n");
		system("pause");
}
