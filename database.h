#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <stdio.h>
#include "libs/sqlite3/sqlite3.h"
#include "product.h"

#define DATABASE_NAME "inventory.db"
#define DEFAULT_STATEMENT_SIZE 1000000

sqlite3* getDatabase();
void saveProduct(sqlite3 *db, Product *product);
void deleteProductById(sqlite3 *db, unsigned long id);
void findProductById(sqlite3 *db, unsigned long id);
void findProductByDescription(sqlite3 *db, char *description);
void getAllProducts(sqlite3 *db);

#endif // DATABASE_H_INCLUDED
