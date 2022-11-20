#include "database.h"

#define CREATE

sqlite3* getDatabase()
{
    sqlite3 *db;
    int status = sqlite3_open(DATABASE_NAME, &db);
    if (status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel abrir o Estoque. Causa: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    createInventory(db);
    return db;
}

void createInventory(sqlite3 *db)
{
    char *sql, *errorMessage = "Desconhecida";
    sprintf(sql,
           "CREATE TABLE IF NOT EXISTS %s"
            "(id INT PRIMARY KEY NOT NULL, amount INT NOT NULL, price REAL NOT NULL, description TEXT NOT NULL);",
             PRODUCT_TABLE_NAME
           );
           printf(sql);
    int status = sqlite3_exec(db, sql, 0, 0, &errorMessage);

    if (status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel criar ou encontrar o Estoque. Causa: %s\n", errorMessage);
        sqlite3_free(errorMessage);
    }
}

void saveProduct(sqlite3 *db, Product *product)
{
    printf("Salvando: %s\n", product->description);
    char *sql, *errorMessage = "Desconhecida";

    sprintf(sql, "INSERT INTO %s VALUES(%ld, %ld, %lf, '%s');",
            PRODUCT_TABLE_NAME,
            product->id,
            product->amount,
            product->price,
            product->description
           );
    int status = sqlite3_exec(db, sql, 0, 0, &errorMessage);

    if (status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel salvar este produto (%s). Causa: %s\n", product->description, errorMessage);
        sqlite3_free(errorMessage);
        return;
    }
    printf("Produto: %s, salvo(a) com sucesso.\n\n", product->description);
}

void deleteProductById(sqlite3 *db, unsigned long id)
{
    printf("Deletando produto de id: %ld\n", id);
    char *sql, *errorMessage = "Desconhecida";

    sprintf(sql, "DELETE FROM %s pd WHERE pd.id = %ld", PRODUCT_TABLE_NAME, id);
    printf("Chegou");
    int status = sqlite3_exec(db, sql, 0, 0, &errorMessage);

    printf(status);
    if(status != SQLITE_OK)
    {
        printf("Chegou");
        fprintf(stderr, "Nao foi possivel excluir este produto (#%s). Causa: %s\n", id, errorMessage);
        sqlite3_free(errorMessage);
        return;
    }

    printf("Produto #%s excluido com sucesso.\n\n", id);
}

Product findProductById(sqlite3 *db, unsigned long id)
{
    printf("Buscando produto de id: %ld\n", id);
    return;
}

Product findProductByDescription(sqlite3 *db, char *description)
{
    printf("Buscando produto por descricao: %s\n", description);
    return;
}

Product* getAllProducts(sqlite3 *db)
{
    printf("Buscando todos os produtos\n");
    return;
}
