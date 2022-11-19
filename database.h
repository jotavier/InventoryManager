#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <stdio.h>
#include "product.h"

#define DATABASE_NAME "inventory.db"

typedef struct sqlite3 InventoryDatabase;

void saveProduct(InventoryDatabase *db, Product *product);
void deleteProductById(InventoryDatabase *db, unsigned long id);
Product findProductById(InventoryDatabase *db, unsigned long id);
Product* getAllProducts(InventoryDatabase *db);

#endif // DATABASE_H_INCLUDED
