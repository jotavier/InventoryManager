#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <stdio.h>
#include "libs/sqlite3/sqlite3.h"
#include "product.h"

#define DATABASE_NAME "inventory.db"

sqlite3* getDatabase();
void saveProduct(sqlite3 *db, Product *product);
void deleteProductById(sqlite3 *db, unsigned long id);
Product findProductById(sqlite3 *db, unsigned long id);
Product findProductByDescription(sqlite3 *db, char *description);
Product* getAllProducts(sqlite3 *db);
#endif // DATABASE_H_INCLUDED
