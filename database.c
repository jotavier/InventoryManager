#include "database.h"

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
    char sql[DEFAULT_STATEMENT_SIZE], *errorMessage = "Desconhecida";

    sprintf(sql,
           "CREATE TABLE IF NOT EXISTS %s(id INTEGER PRIMARY KEY AUTOINCREMENT, description TEXT UNIQUE NOT NULL, amount INT NOT NULL, price REAL NOT NULL);",
             PRODUCT_TABLE_NAME
           );
    int status = sqlite3_exec(db, sql, 0, 0, &errorMessage);

    if (status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel criar ou encontrar o Estoque. Causa: %s\n", errorMessage);
        sqlite3_free(errorMessage);
        sqlite3_close(db);
        exit(1);
    }
}

void saveProduct(sqlite3 *db, Product *product)
{
    printf("Salvando: %s\n", product->description);
    char sql[DEFAULT_STATEMENT_SIZE], *errorMessage = "Desconhecida";

    sprintf(sql, "INSERT INTO %s VALUES(?, '%s', %ld, %lf);",
            PRODUCT_TABLE_NAME,
            product->description,
            product->amount,
            product->price
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
    char sql[DEFAULT_STATEMENT_SIZE], *errorMessage = "Desconhecida";

    sprintf(sql, "DELETE FROM %s WHERE id = %ld", PRODUCT_TABLE_NAME, id);
    printf(sql);
    int status = sqlite3_exec(db, sql, 0, 0, &errorMessage);
    printf("Chegou");
    if(status != SQLITE_OK)
    {
        printf("Chegou dentro");
        fprintf(stderr, "Nao foi possivel excluir este produto (#%s). Causa: %s\n", id, errorMessage);
        printf("Chegou dentro 2");
        sqlite3_free(errorMessage);
        return;
    }
    printf("Chegou fora");
    printf("Produto #%ld excluido com sucesso.\n\n", id);
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
