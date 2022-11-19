#include "database.h"

sqlite3* getDatabase()
{
    sqlite3 *db;
    int status = sqlite3_open(DATABASE_NAME, &db);
    if (status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel abrir o Inventario. Causa: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    createInventory(db);
    return db;
}

void createInventory(sqlite3 *db)
{
    char *createTable = "CREATE TABLE IF NOT EXISTS products(id INT PRIMARY KEY NOT NULL, price REAL NOT NULL, amount INT, description TEXT UNIQUE ON CONFLICT FAIL);",
          *errorMessage;

    int status = sqlite3_exec(db, createTable, 0, 0, &errorMessage);
    if (status != SQLITE_OK )
    {
        fprintf(stderr, "Nao foi possivel criar ou encontrar o Estoque. Causa: %s\n", errorMessage);
        sqlite3_free(errorMessage);
        sqlite3_close(db);
    }
}

void saveProduct(sqlite3 *db, Product *product)
{
    printf("Salvando: %s\n", product->description);
    /*
    char *sql = "INSERT INTO products VALUES(%ld, %ld, %ld, %s);" ,
          *errorMessage;
    int length = sizeof(&sql) + sizeof(&product);
    printf(length);
    snprintf(sql, length, product->id, product->price, product->amount, product->description);
    int status = sqlite3_exec(db, sql, 0, 0, &errorMessage);

    if (status != SQLITE_OK )
    {
        fprintf(stderr, "Nao foi possivel salvar este produto. Causa: %s\n", errorMessage);
        sqlite3_free(errorMessage);
    }
    */
}

void deleteProductById(sqlite3 *db, unsigned long id) {
    printf("Deletando produto de id: %ld\n", id);
    return;
}

Product findProductById(sqlite3 *db, unsigned long id) {
    printf("Buscando produto de id: %ld\n", id);
    return;
}

Product findProductByDescription(sqlite3 *db, char *description) {
    printf("Buscando produto por descricao: %s\n", description);
    return;
}

Product* getAllProducts(sqlite3 *db) {
    printf("Buscando todos os produtos\n");
    return;
}
