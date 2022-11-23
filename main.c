// Sistema de Gerenciamento de Estoque - Projeto Final
// Disciplina: Estudos integrados de sistemas de controle e programação avançados
// Dupla: Jucemar Vieira Junior e Shaiane Wernke Mendes

#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "database.h"

int main()
{
    int selection;
    unsigned long id = 0;
    char description[25];
    sqlite3 *db = getDatabase();
    do
    {
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
        scanf("%d",&selection);

        if (selection==1)
        {
            printf("\n-----------------| CADASTRAR UM PRODUTO |------------------\n\n");
            printf("Entre com os dados do produto a ser cadastrado: \n\n");
            Product prod = {};
            printf("Descricao do produto: ");
            scanf("%s", prod.description);
            printf("Preco do produto: ");
            scanf("%lf", &prod.price);
            printf("Quantidade em estoque: ");
            scanf("%lu", &prod.amount);
            saveProduct(db, &prod);
        }
        if (selection==2)
        {
            printf("\n----------------| DELETAR UM PRODUTO POR ID |---------------\n\n");
            printf("Digite o ID do produto a ser deletado: ");
            scanf("%ld", &id);
            deleteProductById(db, id);
        }
        if (selection==3)
        {
            printf("\n---------------| PROCURAR UM PRODUTO POR ID |---------------\n\n");
            printf("Digite o ID do produto que deseja procurar: ");
            scanf("%lu", &id);
            findProductById(db, id);
        }
        if (selection==4)
        {
            printf("\n------------| PROCURAR UM PRODUTO POR DESCRICAO |------------\n\n");
            printf("Digite a descricao do produto que deseja procurar: ");
            scanf("%s", &description);
            findProductByDescription(db, description);
        }
        if (selection==5)
        {
             printf("\n----------| MOSTRAR TODOS OS PRODUTOS CADASTRADOS |---------\n\n");
            getAllProducts(db);
        }
        if (selection>6)
        {
            printf("O numero digitado esta incorreto, por favor, digite novamente");
        }
    }
    while (selection<6);
    return 0;
}
