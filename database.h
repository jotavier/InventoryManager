#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#define DATABASE_NAME "inventory.db"

typedef struct sqlite3 InventoryDatabase;

InventoryDatabase* getInventory();

#endif // DATABASE_H_INCLUDED
