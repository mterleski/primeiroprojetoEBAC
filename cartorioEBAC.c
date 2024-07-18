#include<stdio.h> //biblioteca de comunicação com o usuário
#include<stdlib.h>//biblioteca de alocação de espaço em memoria
#include<locale.h>//biblioteca de alocação de texto por região
#include<string.h>//biblioteca responsável por strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:\n");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf);//responsável por copiar os valores das strings
	
	FILE*file;//cria o arquivo
	file=fopen(arquivo, "w");//cria o arquivo
	fprintf(file,cpf);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:\n");
	scanf("%s", nome);
	
	file=fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[40];
	
	printf("Digite o CPF a ser consultado:\n");
	scanf("%s",cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL){
		printf("Usuário não cadastrado. Tente novamente.\n\n");
	}
	
	while(fgets(conteudo, 200,file)!=NULL){
		printf("Informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL){
		printf("Usuário não encontrado.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1-Registrar nomes\n");
		printf("\t2-Consultar nomes\n");
		printf("\t3-Deletar nomes\n"); //fim do menu
		printf("\t4-Sair do menu\n\n");
		printf("Opção:");
	
		scanf("%d",&opcao); //armazenando a escolha do usuário
	
		system ("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema");
			return 0;
			break;
			
			default:
			printf("Opção não disponível\n");
			system("pause");
			break;
			
		}
	
	
	}
}
