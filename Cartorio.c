#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o responsavel por cadastrar os usuarios nop sistema
{
	//inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	printf("Digite o CPF a ser cadastrado: "); //coletando insforma��es do usuario
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf ); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");  // abre o arquivo e o "a" armazena dentro do arquivo
	fprintf(file,","); // escrevendo "," dentro do arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");  //coletando insforma��es do usuario
	scanf("%s",nome); //%s refere-se a strings
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file =fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//inicio da cria��o de variaveis/string
	char conteudo[200];
	char cpf[40];
	//final da cria��o de variaveis/string
	printf("Digite o cpf a ser consultado: "); //coletando insforma��es do usuario
	scanf("%s", cpf); //%s refere-se a strings
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // cria o arquivo e o "r" significa ler
	
	
	if(file == NULL) // refere-se caso n�o tenha o cpf citado no sistema
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");// mensagem dada ap�s n�o achar o cpf no sistema
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		        
		printf("\nInforma��es: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}

	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s", cpf);
	
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo "r" significa ler
	fclose(file); // fecha o arquivo
	
	if(file == NULL) //caso n�o tenha o cpf no sistema
	{
		printf("O Usu�rio n�o se encontra no sistema! \n");//caso a resposta dada pelo o usuario n�o exista
		
	}
		else
		{
		remove(cpf);
		printf("Usu�rio deletado com sucesso! \n\n");
		} //caso tenha o cpf cadastrado no sistema

		system("pause");
	 	
}


int main ()
    {
    int opcao=0; //Definindo as variaveis
    int x=1;
    
    for(x=1;x=10;)
    {

       
            system("cls");// responsavel por limpar a tela
        

	        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	        printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	        printf("Escolha a op��o desejada do menu\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
	        printf("Op��o: ");//fim do menu
	
	        scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
 	        system("cls");
 	    
 	    
 	        switch(opcao)//inicio da sele��o do menu
	 	    {
			case 1:
			registro();//chamada de fun��es
 	        break;
 	        
 	        case 2:
 	        consulta();
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        case 4:
	    	printf("Obrigado por utilizar o sistema!\n");
	    	return 0;
	    	break;
	        
	        default:
	       	printf("Essa op��o n�o est� disponivel!\n");
	        system("pause");
	        break;
		    // final da sele��o do menu
		
		}
	
	   
    }
}

