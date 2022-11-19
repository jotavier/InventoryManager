#include "database.h"
#include "libs/sqlite3/sqlite3.h"

InventoryDatabase* getDatabase()
{
    InventoryDatabase *db;
    int status = sqlite3_open(DATABASE_NAME, &db);
    if (status != SQLITE_OK)
    {
        fprintf(stderr, "Nao foi possivel abrir o Inventario. Causa: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    createInventory();
    return db;
}

void createTable(InventoryDatabase *db)
{
    char *createTable = "CREATE TABLE IF NOT EXISTS products(id PRIMARY KEY, price DECIMAL, amount INT, description TEXT UNIQUE ON CONFLICT FAIL);",
          *errorMessage;

    int status = sqlite3_exec(db, sql, 0, 0, &errorMessage);
    if (status != SQLITE_OK )
    {
        fprintf(stderr, "Nao foi possivel criar ou encontrar o Estoque. Causa: %s\n", errorMessage);
        sqlite3_free(errorMessage);
        sqlite3_close(db);
    }
}

void saveProduct(InventoryDatabase *db, Product *product)
{
    char *sql, *errorMessage;
    char *action = "INSERT INTO products VALUES(%ld, %ld, %ld, %s);",
    sprintf(sql, action, product->id, product->price, product->amount, product->description);

    int status = sqlite3_exec(db, sql, 0, 0, &errorMessage);

    if (status != SQLITE_OK )
    {
        fprintf(stderr, "Nao foi possivel salvar este produto. Causa: %s\n", errorMessage);
        sqlite3_free(errorMessage);
        sqlite3_close(db);
    }
}

void deleteProductById(InventoryDatabase *db, unsigned long id)
{

}

Product* findProductById(InventoryDatabase *db, unsigned long id)
{

}

Product* getAllProducts(InventoryDatabase *db)
{

}
