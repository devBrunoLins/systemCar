#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct cadastro //Defini o banco de dados dos clientes 
{
    char CPF[200];
    char telefone[200];
    char nome[200];
    char endereco[200];
    char data[200];
    char CNH [200];
    int vazio,cod;

   }log[200];//nome do banco de dados 


int verifica_pos(void);//função para verificar aposição do codigo
int verifica_cod( int cod );//verificar codigo
int opt;//variavel de opção
void cadastroP(int cod,int pos); //cadastro de clientes 
void list();//lista de clientes 
void consultaCod (void);//consultar cliente por codigo
void excluirCliente (void);//excluir cliente

//inicio do programa
int main(void){

    int i,Opcao,OpcaoCliente,posicao,retorno;
    int codaux = 1;
    do
    {
    	printf("\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");
    	printf("\n\n");
    	printf("\t\t\tSeja Bem Vindo ao SystemCar");
    	printf("\n\n");
    	printf("\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");
    	printf("\n\n");
        printf("\t1 - Cadastrar Novo Cliente\n");
        printf("\t2 - Lista de Clientes\n");
        printf("\t3 - Excluir Cliente\n");
        printf("\t4 - Sair\n");
        printf("\n\n");
        printf("\tOpcao: ");
        scanf("%d", &Opcao); //Ler o que foi digitado pelo usuario
        getchar();
        if (Opcao == 1)//useio o if e else para verificar a opção
        {
        	printf("\n\n");
            printf("\tCadastro de Cliente\n");
            posicao=verifica_pos();//vai chamar a função para verificar a posição do codigo 

                if ( posicao != -1 || posicao >200 )//o numero não pode ser negativo e nem maior que 200
                {	
					while(verifica_cod(codaux) == 0) codaux++; // Seta Codigo do Cliente automágico, de 1 a 200
                    fflush(stdin);	
		
                    retorno = verifica_cod( codaux );//vai habilitar o codigo como usando ou não usando

                    if ( retorno == 1 )// verifica se esta usando ou não
                        cadastroP( codaux, posicao );
                    else{
                        printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
                        getchar();
                        system("cls");
                        main();
                    }

                }
                else
                    printf("\nNao e possivel realizar mais cadastros!\n");//quando atingir a quantidade de cadastros maximas 

                break;
 
        }
        else if (Opcao == 2)//sub pagiina para opções de clintes
        {
            system("cls");
            do{
            printf("\n\n");
            printf("\tPesquisar Clientes\n\n");
            printf("\t1 - Por codigo\n");
            printf("\t2 - Listar todos os Clientes\n");
            printf("\t3 - Menu principal\n\n");
            printf("\tOpcao: ");
            scanf("%d", &OpcaoCliente);
            getchar();
            
                 if(OpcaoCliente == 1)
                 {
                    consultaCod(); //vai puxar a função que consulta o codigo
                }
                else if(OpcaoCliente == 2) // função que lista os cadastros
                {
                    list();
                }
                else if(OpcaoCliente == 3)//para voltar ao menu inicial
                {
                    printf("Voce selecionou voltar ao menu principal, pressione ENTER para continuar");
                    getchar();
                    system("cls");
                }
                else
                    printf("Opcao Invalida\n\n");
    }while(OpcaoCliente =!3 || OpcaoCliente > 3 || OpcaoCliente < 0 || OpcaoCliente == 0);
        }
        else if (Opcao == 3)
        {
            
            excluirCliente();//puxa a função que exçlui o cliente
            printf("AAAAAE APAGO");
            main(); // Chama function Main
        }
        else if (Opcao == 4)
        {
            printf("Voce selecionou a opcao 4 - Sair\n");
        }
        else{
            printf("Opcao invalida, favor pressione enter para voltar ao menu principal");
            getchar();
            system("cls");
        }
        }    while (Opcao != 4 || Opcao < 4);

} // termino do programa
void list(){ // Lista os usuarios cadastrados.
    int i,j;   
    for(i=0;i<200;i++)//vai contar a lista de usuarios mostrando os preenchidos
    {
        if(log[i].cod!= '\0'){
            printf("\n\tCodigo: %d \n\tNome: %s\n\tCPF: %d\n\tEndereco: %s\n\tTelefone: %d\n\tCNH:  %d\n", log[i].cod,log[i].nome,log[i].CPF,log[i].endereco,log[i].telefone,log[i].CNH);
    }
}
    printf("\n\tPressione Enter para volta ao menu principal");
    getchar();
    system("cls");

} //fim da lista
void cadastroP(int cod, int pos){ //Cadastro das pessoas
    int i;
    do{
    pos = verifica_pos();//definindo onde armazena para controle
    log[pos].cod = cod;
        printf("\tNome Completo: ");
        gets(log[pos].nome);//vai armazenar no "banco de dados"
        printf("\tCPF: ");
        gets(log[pos].CPF);
        printf("\tEndereco: ");
        gets(log[pos].endereco);
        printf("\tTelefone: ");
        gets(log[pos].telefone);
        printf("\tCNH: ");
        gets(log[pos].CNH);
        log[pos].vazio = 1;
        opt ==1;
        printf("\t\n");
    	printf("\tCadastro realizado com sucesso.");
        getchar();   
    }while(opt==1);
    system("cls");
    main();

} // FIM DO CADASTRO DE PESSOAS
int verifica_pos( void ) //verificar a posição do codigo de cadastro do cliente
{
    int cont = 0;

    while ( cont <= 200 )
    {

        if ( log[cont].vazio == 0 )
            return(cont);

        cont++;

    }

    return(-1);

} // FIM DO VERIFICADOR
int verifica_cod( int cod ) // VERIFICADOR DE CÓDIGO
{
    int cont = 0;

    while ( cont <= 200 )
    {
        if ( log[cont].cod == cod )
            return(0);

        cont++;
    }

    return(1);

} // FIM DO VERIFICADOR
void consultaCod (void) // CONSULTAR 1 CADASTRADO QUALQUER VIA CÓDIGO DADO POR USUÁRIO.
{
    int cont = 0, cod;

    printf("\n\tCodigo: ");
    scanf("%d",&cod);
    fflush(stdin);
    system("cls");

    while ( cont <= 200 )
    {

        if (log[cont].cod==cod)
        {
            if (log[cont].vazio==1)
            {
               
                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\nCNH: %d\n", log[cont].cod,log[cont].nome,log[cont].CPF,log[cont].endereco,log[cont].telefone,log[cont].CNH);
               

                system ("pause");

                system("cls");

                break;

            }
        }

        cont++;

        if ( cont > 200 ){
            printf("\nCodigo nao encontrado, pressione enter para volar ao menu principal\n");
            getchar();
            system("cls");
        }

    }
} // FIM DA FUNÇÃO CONSULTAR
void excluirCliente(void)  // EXCLUI CLIENTE
//aqui ele vai verificar o codigo no banco de dados
// assim que encontrado ele vai exibir para o usuario o que ele encontrou 
//perguntar se vai ser esse usuario mesmo que vai ser excluido
//tendo a confirmação do usuario o espaço alocado na memoria que estava salvo o cadastro é definido como vazio com o comando NULL
{
    int cod, cont = 0;
    char resp;
    printf("\nEntre com o codigo do registro que deseja excluir: \n");
    scanf("%d", &cod );

    while ( cont <= 200 )
    {

        if ( log[cont].cod == cod )
        {

            if (log[cont].vazio == 1 )
            {
                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", log[cont].cod,log[cont].nome,log[cont].CPF,log[cont].endereco,log[cont].telefone);
                getchar();
                printf("\nDeseja realmente excluir? s/n: ");
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    log[cont].vazio=0;
                    log[cont].cod = NULL;
                    printf("\nExclusao feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 200 )
            printf("\nCodigo nao encontrado\n");

    }

    system("pause");
    system("cls");

}

