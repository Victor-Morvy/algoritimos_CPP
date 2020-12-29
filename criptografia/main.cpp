#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Configuração da chave para criptografar
char CHAVE[] = "AZZU";
int TAM_CHAVE = strlen(CHAVE);

int TAM_TEXTO = 100000;
char TEXTO[100000];

int TEXTO_CRIPT[100000];

//char CAMINHO = "C:\\Users\\PICHAU\\Desktop\\Faculdade de Ciencias da computação\\testes\\criptografia";
//char ARQUIVO = "C:\\Users\\PICHAU\\Desktop\\Faculdade de Ciencias da computação\\testes\\criptografia\\original.txt";

bool Criptografar()
{

    FILE *arquivo;

    int CHAVE_int;
    for(int i = 0; i < strlen(TEXTO); i++)
    {
        TEXTO_CRIPT[i] = TEXTO[i];
    }


    printf("\n%d\n", TEXTO_CRIPT[0]);

    for(int aux = 0; aux < strlen(TEXTO); )
    {
        for(int i = 0; i < TAM_CHAVE; i++)
        {
            //TEXTO_CRIPT = TEXTO_CRIPT * CHAVE[i];
            CHAVE_int = CHAVE[i];
            TEXTO_CRIPT[aux] *= CHAVE_int;
            aux++;
        }
    }

    printf("\n%d\n", TEXTO_CRIPT[0]);

    arquivo = fopen("C:\\Users\\PICHAU\\Desktop\\Faculdade de Ciencias da computação\\testes\\criptografia\\criptografado.txt", "w");
    if(arquivo == NULL)
    {
        printf("\n\nErro ao criar arquivo!\n\n");
    }
    else
    {
        for(int i = 0; i < strlen(TEXTO); i++)
        {
            fprintf(arquivo, "%d ", TEXTO_CRIPT[i]);
        }

        fclose(arquivo);
    }

    return true;
}

void limparTexto()
{
    memset(TEXTO, '\0', 100000);
}

bool descriptografar()
{
    FILE *arquivo;

    int valor;
    int pos_chave;
    int pos_texto;

    arquivo = fopen("C:\\Users\\PICHAU\\Desktop\\Faculdade de Ciencias da computação\\testes\\criptografia\\criptografado.txt", "r");

    limparTexto();

    if(arquivo==NULL)
    {
        return false;
    }

    pos_chave = 0;
    pos_texto = 0;
    while(!feof(arquivo))
    {

        fscanf(arquivo, "%d", &valor);

        valor /= CHAVE[pos_chave];

        TEXTO[pos_texto] = (char)valor;
        pos_texto++;

        if(pos_chave == TAM_CHAVE-1)
            pos_chave = 0;
        else
            pos_chave++;


    }
    TEXTO[strlen(TEXTO)-1] = '\0';
    fclose(arquivo);
    return true;
}

void abrirPasta()
{
    system("explorer C:\\Users\\PICHAU\\Desktop\\Faculdade de Ciencias da computação\\testes\\criptografia");
}

void Receber_Arquivo_cript()
{
    char pause;
    printf("\n\nInstrucoes para importar um arquivo criptografado:");
    printf("\n\n 1 - Renomeie o arquivo para 'criptografado.txt'");
    printf("\n\n 2 - Copie o arquivo para a pasta que sera aberta a seguir");
    printf("\n\n 3 - Feche o explorador e retorne a aplicacao");

    printf("\n\n\n Pressione Enter para abrir a pasta");
    scanf("%c",&pause);
    setbuf(stdin,NULL);
    abrirPasta();

    printf("\n\nImportando arquivo...\n\n");

    if(descriptografar())
    {
        printf("\n\nArquivo descriptografado com sucesso!\n\n");
        system("pause");
        system("cls");
        printf("%s\n\n", TEXTO);

        system("pause");
    }
    else
        printf("\n\nNao foi possivel descriptografar o arquivo!\n\n");
}



void receberTexto(char tipo[])
{
    FILE *arquivo;
    char palavra[100];

    char aux[TAM_TEXTO], pause;

    if(strcmp(tipo, "msg") == 0)
    {
        printf("\n\nReceber texto para criptografar\n\n");
        printf("\n\nDigite o texto: \n\n");
        gets(aux);
        printf("\n\nTexto recebido, cripitografando...\n\n");

        strcpy(TEXTO, aux);

        if(Criptografar())
        {
            printf("\n\nTexto criptografado com sucesso!");
            printf("\n\nPressione qualquer tecla para abrir a pasta do arquivo gerado");
            scanf("%c", &pause);
            setbuf(stdin, NULL);
            abrirPasta();
        }
        else
            printf("\n\nNao foi possivel criptografar o texto\n\n");

        system("pause");


    }
    else if(strcmp(tipo, "arquivo") == 0)
    {
        printf("\n\nInstrucoes para importar um arquivo de texto:");
        printf("\n\n 1 - Renomeie o arquivo para 'original.txt'");
        printf("\n\n 2 - Copie o arquivo para a pasta que sera aberta a seguir");
        printf("\n\n 3 - Feche o explorador e retorne a aplicacao");

        printf("\n\n\n Pressione Enter para abrir a pasta");
        scanf("%c",&pause);
        setbuf(stdin,NULL);

        printf("\n\nImportando arquivo...\n\n");


        arquivo = fopen("C:\\Users\\PICHAU\\Desktop\\Faculdade de Ciencias da computação\\testes\\criptografia\\original.txt", "r");
        if(arquivo == NULL)
            printf("\n\n Erro ao ler arquivo!\n\n");
        else
        {
            while(!feof(arquivo)){
                fscanf(arquivo,"%s",palavra);
                strcat(aux," ");
                strcat(aux,palavra);

            }

            strcpy(TEXTO, aux);
            //printf("%s", TEXTO);

            if(Criptografar())
            {
                printf("\n\nTexto criptografado com sucesso!");
                printf("\n\nPressione qualquer tecla para abrir a pasta do arquivo gerado");
                scanf("%c", &pause);
                setbuf(stdin, NULL);
                abrirPasta();
            }
            else
                printf("\n\nNao foi possivel criptografar o texto\n\n");

            fclose(arquivo);
        }

        system("pause");

    }
    else
    {
        printf("\n\nErro ao receber texto\n\n");
    }

}
void Menu_Criptografar(){
    int opcao;
    printf("\n\tCriptografia de dados");
    printf("\n\n Criptografar texto ou arquivo");
    printf("\n\n\n 1 - Digitar texto");
    printf("\n\n 2 - Importar arquivo de texto (txt)");
    printf("\n\n 3 - Voltar ao menu principal");
    printf("\n\n Informe a opcao desejada: ");
    scanf("%d",&opcao);
    setbuf(stdin,NULL);
    switch(opcao){
    case 1:
        system("cls");
        receberTexto("msg");
        break;
    case 2:
        system("cls");
        receberTexto("arquivo");
        break;
    case 3:
        break;
    default:
        printf("Opcao invalida! Tente novamente...");
    }
}

void Menu(){
    int opcao;
    while(1){
        system("cls");
        printf("\n\tCriptografia de dados");
        printf("\n\n 1 - Criptografar texto ou arquivo");
        printf("\n\n 2 - Receber arquivo");
        printf("\n\n 3 - Sair");
        printf("\n\n Informe a opcao desejada: ");
        scanf("%d",&opcao);
        setbuf(stdin,NULL);
        switch(opcao){
        case 1:
            system("cls");
            Menu_Criptografar();
            break;
        case 2:
            system("cls");
            Receber_Arquivo_cript();
            break;
        case 3:
            printf("\nFinalizando...\n\n");
            system("pause");
            exit(0);
            break;
        default:
            printf("Opcao invalida! Tente novamente...");
        }
    }
}

int main(){

    Menu();

    return 0;
}
