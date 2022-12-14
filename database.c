#include "database.h"

sqlite3* getDatabase()
{
    sqlite3 *db;
    int status = sqlite3_open(DATABASE_NAME, &db);
    if (status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel abrir o Estoque. Causa: %s\n\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    createInventory(db);
    return db;
}

int callback(void *NotUsed, int columns, char **fields, char **columnsNames);

void createInventory(sqlite3 *db)
{
    char sql[DEFAULT_STATEMENT_SIZE], *errorMessage = "Desconhecida";

    sprintf(sql,
            "CREATE TABLE IF NOT EXISTS %s"
            "(Id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "Descricao TEXT UNIQUE NOT NULL, "
            "Quantidade INT NOT NULL, "
            "Preco REAL NOT NULL);",
            PRODUCT_TABLE_NAME
           );
    int status = sqlite3_exec(db, sql, 0, 0, &errorMessage);

    if (status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel criar ou encontrar o Estoque. Causa: %s\n\n", errorMessage);
        sqlite3_free(errorMessage);
        sqlite3_close(db);
        exit(1);
    }
}

void saveProduct(sqlite3 *db, Product *product)
{
    printf("Salvando: %s\n\n", product->description);
    char sql[DEFAULT_STATEMENT_SIZE], *errorMessage = "Desconhecida";

    sprintf(sql, "INSERT INTO %s VALUES(?, '%s', %ld, %0.2lf);",
            PRODUCT_TABLE_NAME,
            product->description,
            product->amount,
            product->price
           );
    int status = sqlite3_exec(db, sql, 0, 0, &errorMessage);

    switch(status)
    {
    case SQLITE_OK:
        printf("Produto: %s, salvo(a) com sucesso.\n\n", product->description);
        break;
    case SQLITE_CONSTRAINT:
        fprintf(stderr, "Nao foi possivel salvar este produto (%s). "
                "Causa: Ja existe um produto com este Id ou Descricao.\n\n", product->description, errorMessage);
        sqlite3_free(errorMessage);
        findProductByDescription(db, product->description);
        break;
    default:
        fprintf(stderr, "Nao foi possivel salvar este produto (%s). Causa: %s\n\n", product->description, errorMessage);
        sqlite3_free(errorMessage);
    }
}

void deleteProductById(sqlite3 *db, unsigned long id)
{
    printf("Deletando produto de id: %ld\n\n", id);
    char sql[DEFAULT_STATEMENT_SIZE], *errorMessage = "Desconhecida";

    sprintf(sql, "DELETE FROM %s WHERE id = %ld", PRODUCT_TABLE_NAME, id);
    int status = sqlite3_exec(db, sql, 0, 0, &errorMessage);

    if(status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel excluir este produto (#%ld). Causa: %s\n\n", id, errorMessage);
        sqlite3_free(errorMessage);
        return;
    }

    printf("Produto #%ld excluido com sucesso.\n\n", id);
}

void findProductById(sqlite3 *db, unsigned long id)
{
    printf("Buscando produto de id: %ld\n\n", id);
    char sql[DEFAULT_STATEMENT_SIZE], *errorMessage = "Desconhecida";

    sprintf(sql, "SELECT * FROM %s WHERE id = %ld", PRODUCT_TABLE_NAME, id);
    int status = sqlite3_exec(db, sql, callback, 0, &errorMessage);

    if(status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel encontrar este produto (#%ld). Causa: %s\n\n", id, errorMessage);
        sqlite3_free(errorMessage);
    }
}

void findProductByDescription(sqlite3 *db, char *description)
{
    printf("Buscando produto por descricao: %s\n\n", description);
    char sql[DEFAULT_STATEMENT_SIZE], *errorMessage = "Desconhecida";

    sprintf(sql, "SELECT Id, Descricao, Quantidade, Preco FROM %s "
            "WHERE Descricao LIKE '%%%s%%%'", PRODUCT_TABLE_NAME, description);
    int status = sqlite3_exec(db, sql, callback, 0, &errorMessage);

    if(status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel encontrar este produto (#%s). Causa: %s\n\n", description, errorMessage);
        sqlite3_free(errorMessage);
    }
}

void getAllProducts(sqlite3 *db)
{
    printf("Buscando todos os produtos\n\n");
    char sql[DEFAULT_STATEMENT_SIZE], *errorMessage = "Desconhecida";

    sprintf(sql, "SELECT * FROM %s", PRODUCT_TABLE_NAME);
    int status = sqlite3_exec(db, sql, callback, 0, &errorMessage);

    if(status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel encontrar os produtos do Estoque. Causa: %s\n\n", errorMessage);
        sqlite3_free(errorMessage);
    }
}

int callback(void *NotUsed, int columns, char **fields, char **columnsNames)
{

    NotUsed = 0;
    int column;

    printf("\t[");

    for (column = 0; column < columns; column++)
    {
        printf("%s: %s", columnsNames[column], fields[column] ? fields[column] : "NULL");
        if(column != columns - 1)
        {
            printf("     ");
        }
    }

    printf("]\n\n");

    return 0;
}
