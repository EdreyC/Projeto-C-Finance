#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int sair = 0; //Controle global menu principal 
int numeroTotalDeEntradas = 0 ; //Controle global Entrada
float saldoCofrinho = 0, totalOrcamento = 0,totalContas = 0;
FILE *dataBaseContasPagar;
FILE *dataBaseRenda;
FILE *dataBaseCofrinho;

//Struct Adicionar Conta
struct salvarConta{
    char nome[50][100];
    float valorConta[50];
    char vencimentoConta[50][11];
};

struct salvarConta novaConta;

//Struct Orçamento Mensal
struct orcamento{
    char nomeEntrada[50][100];
    float valorEntrada[50];
    char dataEntrada[50][11];
};

struct orcamento novaEntrada; 

//Struct Cofrinho
struct cofrinho{
    char proposito[50][100];
    float valor [50];
};

struct cofrinho novocofrinho;

void atualizarDadosTotais (){
   
}

//Funções Módulo 1 -  Contas
int CPaddCont (){
    int icont = 0, indiceSalvar = 0;

    for(icont = 0;  icont < 50; icont++){
        if(novaConta.valorConta[icont] == 0){
            indiceSalvar = icont;

            break;
        }
    }

        fflush(stdin);
        printf("\nInsira uma identificação para a conta: ");
        gets(novaConta.nome[indiceSalvar]);

        fflush(stdin);
        printf("Insira a data de vencimento da conta (DD/MM/AAAA): ");
        gets(novaConta.vencimentoConta[indiceSalvar]);
        fflush(stdin);

        printf("Insira o valor da conta: ");
        scanf("%f", &novaConta.valorConta[indiceSalvar]);

        dataBaseContasPagar = fopen(".dataBaseContasPagar.bin", "wb");
        fwrite(&novaConta, sizeof(struct salvarConta), 1, dataBaseContasPagar);
        fclose(dataBaseContasPagar);
    return 0;
}

int CPeditCont (){
    int icont = 0, idconta;
    fflush(stdin);
    for(icont = 0;  icont < 50; icont++){
        if(novaConta.valorConta[icont] != 0){
            printf("ID da conta: %d \nNome da Conta: %s \nVencimento da Conta: %s \nValor da Conta: R$%.2f\n\n",icont, novaConta.nome[icont], novaConta.vencimentoConta[icont], novaConta.valorConta[icont]);
        }
    }
    printf("Insira o ID da conta deseja editar: ");
    scanf("%d", &idconta);

    fflush(stdin);
        printf("\nInsira uma identificação para a conta: ");
        gets(novaConta.nome[idconta]);

        fflush(stdin);
        printf("Insira a data de vencimento da conta (DD/MM/AAAA): ");
        gets(novaConta.vencimentoConta[idconta]);
        fflush(stdin);

        printf("Insira o valor da conta: ");
        scanf("%f", &novaConta.valorConta[idconta]);

    printf("\nA ID %d editada com sucesso!\n", idconta);

    
    dataBaseContasPagar = fopen(".dataBaseContasPagar.bin", "wb");
    fwrite(&novaConta, sizeof(struct salvarConta), 1, dataBaseContasPagar);
    fclose(dataBaseContasPagar);
    return 0;
}

int CPremoveCont (){
    int icont = 0, idconta;
    fflush(stdin);
    for(icont = 0;  icont < 50; icont++){
        if(novaConta.valorConta[icont] != 0){
            printf("ID da conta: %d \nNome da Conta: %s \nVencimento da Conta: %s \nValor da Conta: R$%.2f\n\n",icont, novaConta.nome[icont], novaConta.vencimentoConta[icont], novaConta.valorConta[icont]);
        }
    }
    printf("Qual conta deseja remover: ");
    scanf("%d", &idconta);

    novaConta.valorConta[idconta] = 0;

    printf("\nA ID %d apagada com sucesso!\n", idconta);

    dataBaseContasPagar = fopen(".dataBaseContasPagar.bin", "wb");
    fwrite(&novaConta, sizeof(struct salvarConta), 1, dataBaseContasPagar);
    fclose(dataBaseContasPagar);

    return 0;
}

void CPlistCont (){
    int icont = 0;
    fflush(stdin);
    for(icont = 0;  icont < 50; icont++){
        if(novaConta.valorConta[icont] != 0){
            printf("ID da conta: %d \nNome da Conta: %s \nVencimento da Conta: %s \nValor da Conta: R$%.2f\n\n",icont, novaConta.nome[icont], novaConta.vencimentoConta[icont], novaConta.valorConta[icont]);
        }
    }
}

// Funções Módulo 2 - Orçamento Mensal
void OMaddRenda(){
    
    int icont = 0, idrenda;
    
    for (icont = 0; icont <= 50; icont++){
        if (novaEntrada.valorEntrada[icont] == 0){
            idrenda = icont;
            break;
        }
    }

    fflush(stdin);
    printf("\nQual a origem da renda: ");
    gets(novaEntrada.nomeEntrada[idrenda]);
    fflush(stdin);
    printf("\nQual o valor da renda: ");
    scanf("%f",&novaEntrada.valorEntrada[idrenda]);
    fflush(stdin);
    printf("\nQual a data de adição da renda (DD/MM/AAAA): ");
    gets(novaEntrada.dataEntrada[idrenda]);
    fflush(stdin);
    
    dataBaseRenda = fopen(".dataBaseRenda.bin","wb")    ;
    fwrite(&novaEntrada,sizeof(struct orcamento),1,dataBaseRenda);
    fclose(dataBaseRenda);
}

int OMeditRenda(){
    int idrenda = 0 ;
    int icont = 0;
    fflush(stdin);
    for(icont = 0;  icont < 50; icont++){
        if(novaEntrada.valorEntrada[icont] != 0){
            printf("ID da conta: %d \nNome da Renda: %s \n Data adição da renda: %s \nValor da renda: R$%.2f\n\n",icont, novaEntrada.nomeEntrada[icont], novaEntrada.dataEntrada[icont], novaEntrada.valorEntrada[icont]);
        }
    }

    printf("\nQual id da renda que deseja remover: \n");
    scanf("%d",&idrenda);
    novaEntrada.valorEntrada[idrenda] = 0;

    fflush(stdin);
    printf("\nQual a origem da renda: ");
    gets(novaEntrada.nomeEntrada[idrenda]);
    fflush(stdin);
    printf("\nQual o valor da renda: ");
    scanf("%f",&novaEntrada.valorEntrada[idrenda]);
    fflush(stdin);
    printf("\nQual a data de adição da renda (DD/MM/AAAA): ");
    gets(novaEntrada.dataEntrada[idrenda]);
    fflush(stdin);
    
    dataBaseRenda = fopen(".dataBaseRenda.bin","wb")    ;
    fwrite(&novaEntrada,sizeof(struct orcamento),1,dataBaseRenda);
    fclose(dataBaseRenda);
    
    return 0;
}

int OMremove(){
    
    int icont = 0, idrenda;
    fflush(stdin);
    for(icont = 0;  icont < 50; icont++){
        if(novaEntrada.valorEntrada[icont] != 0){
            printf("ID da conta: %d \nNome da Renda: %s \n Data adição da renda: %s \nValor da renda: R$%.2f\n\n",icont, novaEntrada.nomeEntrada[icont], novaEntrada.dataEntrada[icont], novaEntrada.valorEntrada[icont]);
        }
    }
    
    printf("\nQual id da renda que deseja remover: \n");
    scanf("%d",&idrenda);
    novaEntrada.valorEntrada[idrenda] = 0;
    
    printf("\nRenda id: %d removida com sucesso\n",idrenda);

    dataBaseRenda = fopen(".dataBaseRenda.bin","wb");
    fwrite(&novaEntrada,sizeof(struct orcamento),1,dataBaseRenda);
    fclose(dataBaseRenda);
    
    return 0;
}

void OMorcamentoTotal (){
    int icont = 0; 
    float totalOrcamento = 0;
    fflush(stdin);
    for(icont = 0;  icont < 50; icont++){
        if(novaEntrada.valorEntrada[icont] != 0){
            printf("ID da conta: %d \nNome da Renda: %s \n Data adição da renda: %s \nValor da renda: R$%.2f\n\n",icont, novaEntrada.nomeEntrada[icont], novaEntrada.dataEntrada[icont], novaEntrada.valorEntrada[icont]);
        }
    }
    
    for(icont = 0;  icont < 50; icont++){
        if(novaEntrada.valorEntrada[icont] != 0){
            totalOrcamento += novaEntrada.valorEntrada[icont];
        }
    }
    
    printf("\nO orçamento total é: %.2f \n",totalOrcamento);
}

//Funções Módulo 3 - Cofrinho
int COaddFundos (){
    
    float valor = 0;
    
    printf("\nQual valor deseja guardar :");    
    scanf("%f",&valor);
    
    saldoCofrinho += valor;
    
    printf("\nForam guardados R$ %.2f , o saldo do cofrinho é R$ %.2f \n",valor,saldoCofrinho);
    
    return 0;
}

int COremoveFundos (){
    float valorSacar = 0;
    
    printf("\nQuanto você que sacar do cofrinho: ");
    scanf("%f",&valorSacar); 
    
    if (saldoCofrinho >= valorSacar){
        
        saldoCofrinho -= valorSacar;
        printf("\nVocê sacou R$ %.2f do cofrinho o saldo é %.2f \n",valorSacar,saldoCofrinho);
    
    }else{
        printf("\nVocê não tem saldo suficiente no cofrinho.");
    }
    
    return 0;
}

float COrendFundos (){
    float valorMes = 0;
    int  qtdMeses = 0;

    printf("\nInsira o valor que você quer guardar mensalmente: ");
    scanf("%f", &valorMes);

    printf("\nInforme durante quantos meses você irá depositar esse mesmo valor: ");
    scanf("%d", &qtdMeses);

    float totalAcumulado = qtdMeses * valorMes;

    printf("\nNo final de %i meses, você terá guardado R$ %.2f reais.", qtdMeses, totalAcumulado);

    return 0;
}
float COsaldo(){
    printf("\nO saldo do cofrinho é : R$ %.2f \n",saldoCofrinho);
    return 0;
}

//Menu Principal
void menuPrincipal (){
    int MPcontrolMenu = 0; //Controle menu principal
    int CPcontrolMenu = 0; //Controle menu Contas a Pagar
    int OMcontrolMenu = 0; //Controle menu Orçamento mensal
    int COcontrolMenu = 0; //Controle menu Cofrinho
    
    do{

        printf("\nMenu principal\n");
        printf("\n1- Orçamento Mensal\n2- Contas a pagar\n3- Cofrinho\n0- Fechar a Aplicação\n");
        printf("\nSelecione a sua opção: ");
        scanf("%i", &MPcontrolMenu);
        
        //Menu Principal
        switch (MPcontrolMenu){
            
            //Fechar aplicativo
            case 0:
                printf("\nFechando a aplicação...\n");
                sair = 1;
                break;
            
            // Menu Orçamento Mensal
            case 1:     
                do{
                    printf("\nOrçamento Mensal\n");    
                    printf("\n1- Adicionar Renda\n2- Editar Renda \n3- Remover Renda\n4- Listar Renda\n0- Voltar para o menu principal\n");
                    printf("\nSelecione a sua opção: ");
                    scanf("%i", &OMcontrolMenu);
                    
                    switch(OMcontrolMenu){
                        case 0:
                            menuPrincipal ();
                            break;
                        case 1:
                            OMaddRenda();
                            break;
                        case 2:
                            OMeditRenda();
                            break;
                        case 3:
                            OMremove();
                            break;
                        case 4:
                            OMorcamentoTotal();
                            break;
                        default:    
                            printf("\nOpção Inválida.\n");
                            break;
                        }

                }while(OMcontrolMenu != 0);
                break;
            
            //Menu Contas a Pagar
            case 2:
                do{
                    printf("\nContas a Pagar\n");    
                    printf("\n1- Adicionar Conta\n2- Listar Contas \n3- Editar Contas\n4- Remover Contas\n0- Voltar para o menu principal\n");
                    printf("\nSelecione a sua opção: ");
                    scanf("%i", &CPcontrolMenu);
                    
                    switch(CPcontrolMenu){
                        case 0:
                            menuPrincipal ();
                            break;
                        case 1:
                            CPaddCont ();
                            break;
                        case 2:
                            CPlistCont ();
                            break;
                        case 3:
                            CPeditCont ();
                            break;
                        case 4:
                            CPremoveCont ();
                            break;
                        default:    
                            printf("\nOpção Inválida.\n");
                            break;
                        }

                }while(CPcontrolMenu != 0);
                break;
            
            //Menu cofrinho 
            case 3:
                do{
                     printf("\nCofrinho\n");   
                    printf("\n1- Adicionar Fundos\n2- Remover Fundos\n3- Saldo\n4- Pespectiva de economia \n0- Voltar para o menu principal\n");
                    printf("\nSelecione a sua opção: ");
                    scanf("%i", &COcontrolMenu);
                    
                    switch(COcontrolMenu){
                        case 0:
                            menuPrincipal ();
                            break;
                        case 1:
                            COaddFundos();
                            break;
                        case 2:
                            COremoveFundos();
                            break;
                        case 3:
                            COsaldo();
                            break;
                        case 4:
                            COrendFundos();
                            break;
                        default:    
                            printf("\nOpção Inválida.\n");
                            break;
                        }

                }while(COcontrolMenu != 0);
                break;
            
            //Opção invalida 
            default:
                printf("\nOpção inválida! Tente novamente...\n");
                break;
        }
    } while (sair != 1);
}

int main (){
    setlocale(LC_ALL, "Portuguese"); //Reconhecendo caracteres da lingua portuguesa
   
    int count = 0;
    
    //Lendo/crindo base de dados das contas a pagar 
    dataBaseContasPagar = fopen(".dataBaseContasPagar.bin", "rb");
    if (dataBaseContasPagar == NULL){
        for(count = 0; count <= 50; count++){
            novaConta.valorConta[count] = 0;
        }
        dataBaseContasPagar = fopen(".dataBaseContasPagar.bin", "wb");
        fwrite(&novaConta, sizeof(struct salvarConta), 1, dataBaseContasPagar);
    }
    fread(&novaConta,sizeof(struct salvarConta),1,dataBaseContasPagar);
    fclose(dataBaseContasPagar);

    //Lendo/criando base de dados renda
    dataBaseRenda = fopen(".dataBaseRenda.bin","rb");
    if(dataBaseRenda == NULL){
        for(count = 0; count <= 50; count++){
            novaEntrada.valorEntrada[count] = 0;
        }
        dataBaseRenda = fopen(".dataBaseRenda.bin","wb");
        fwrite(&novaEntrada,sizeof(struct orcamento),1,dataBaseRenda);
    }
    fread(&novaEntrada,sizeof(struct orcamento),1,dataBaseRenda);
    fclose(dataBaseRenda);
    
    //Lendo/Criando base de dados cofrinho
    dataBaseCofrinho = fopen(".dataBaseCofrinho.bin","rb");
    if (dataBaseCofrinho == NULL){
        for(count = 0; count <= 50; count++){
            novocofrinho.valor[count] = 0;
        }
        dataBaseCofrinho = fopen(".dataBaseCofrinho.bin","wb");
        fwrite(&novocofrinho,sizeof(struct cofrinho),1,dataBaseCofrinho);
    }
    fread(&novocofrinho,sizeof(struct cofrinho),1,dataBaseCofrinho);
    fclose(dataBaseCofrinho);
    
    void menuPrincipal ();  
    
    do{
        menuPrincipal ();
    }while(sair != 1);

        
    return 0;
}