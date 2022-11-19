#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "database.h"

int main()
{
    InventoryDatabase *db = getInventory();
    Product prod = {.id=1, .amount=5, .price=55.8, .description="Banana"};
    saveProduct(&db, &prod);
    getProductById(&db, 1);
    getAllProducts(&db);
    return 0;
}
