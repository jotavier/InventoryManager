// Sistema de Gerenciamento de Estoque - Projeto Final
// Disciplina: Estudos integrados de sistemas de controle e programação avançados
// Dupla: Jucemar Vieira Junior e Shaiane Wernke Mendes

#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "database.h"

#define INVALID_OPERATION -1
#define REGISTER_NEW_PRODUCT 1
#define DELETE_PRODUCT_BY_ID 2
#define FIND_PRODUCT_BY_ID 3
#define FIND_PRODUCT_BY_DESCRIPTION 4
#define SHOW_ALL_PRODUCTS 5
#define FINISH_APPLICATION 6

void registerNewProduct();
void deleteProduct();
void getProductById();
void getProductByDescription();
void showAllProducts();
int getOperation();

sqlite3 *db;

int main()
{
    int operation = INVALID_OPERATION;
    db = getDatabase();
    do
    {
        fflush(stdin);
        operation = getOperation();
        switch(operation)
        {
        case REGISTER_NEW_PRODUCT:
            registerNewProduct();
            break;
        case DELETE_PRODUCT_BY_ID:
            deleteProduct();
            break;
        case FIND_PRODUCT_BY_ID:
            getProductById();
            break;
        case FIND_PRODUCT_BY_DESCRIPTION:
            getProductByDescription();
            break;
        case SHOW_ALL_PRODUCTS:
            showAllProducts();
            break;
        case FINISH_APPLICATION:
            printf("\n######## Finalizando Gerenciador de Estoque ########\n");
            break;
        default:
            printf("O numero digitado esta incorreto, por favor, digite novamente");
        }
    }
    while (operation != FINISH_APPLICATION);
    sqlite3_close(db);
    return 0;
}

int getOperation()
{
    int operation = INVALID_OPERATION;
    printf("\n................................................................\n");
    printf("\n |Sistema de Gerenciamento de Estoque| \n\n");
    printf(" - Menu de funcoes, selecione o processo que deseja realizar:\n");
    printf("   [1] Cadastre um novo produto\n");
    printf("   [2] Delete um produto pelo seu ID\n");
    printf("   [3] Procure um produto pelo seu ID\n");
    printf("   [4] Procure um produto pela sua descricao\n");
    printf("   [5] Mostrar todos os produtos\n");
    printf("   [6] Encerrar programa\n");
    printf("\n................................................................\n");
    printf("\nEscolha: ");
    if(!scanf("%d", &operation)) return INVALID_OPERATION;
    return operation;
}

void registerNewProduct()
{
    printf("\n-----------------| CADASTRAR UM PRODUTO |------------------\n\n");
    printf("Entre com os dados do produto a ser cadastrado: \n\n");
    Product prod = {};
    printf("Descricao do produto: ");
    fflush(stdin);
    gets(prod.description);
    printf("Preco do produto: ");
    if(!scanf("%lf", &prod.price)) return invalidValueMessage();
    printf("Quantidade em estoque: ");
    if(!scanf("%lu", &prod.amount)) return invalidValueMessage();
    saveProduct(db, &prod);
}
void deleteProduct()
{
    unsigned long id = 0;
    printf("\n----------------| DELETAR UM PRODUTO POR ID |---------------\n\n");
    getAllProducts(db);
    printf("Digite o ID do produto a ser deletado: ");
    if(!scanf("%ld", &id)) return invalidValueMessage();
    deleteProductById(db, id);
}
void getProductById()
{
    unsigned long id = 0;
    printf("\n---------------| PROCURAR UM PRODUTO POR ID |---------------\n\n");
    printf("Digite o ID do produto que deseja procurar: ");
    if(!scanf("%lu", &id)) return invalidValueMessage();
    findProductById(db, id);
}
void getProductByDescription()
{
    char description[MAX_DESCRIPTION_LENGTH];
    printf("\n------------| PROCURAR UM PRODUTO POR DESCRICAO |------------\n\n");
    printf("Digite a descricao do produto que deseja procurar: ");
    fflush(stdin);
    gets(description);
    findProductByDescription(db, description);
}
void showAllProducts()
{
    printf("\n----------| MOSTRAR TODOS OS PRODUTOS CADASTRADOS |---------\n\n");
    getAllProducts(db);
}

void invalidValueMessage() {
    printf("\n\nValor invalido. Retornando ao menu.\n\n");
}
