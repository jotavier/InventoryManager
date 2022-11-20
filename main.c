#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "database.h"

int main()
{
    sqlite3 *db = getDatabase();
    Product prod = {.id=1, .amount=5, .price=55.8, .description="Banana"};
    saveProduct(db, &prod);
    deleteProductById(db, 1);
    findProductById(db, 3);
    findProductByDescription(db, "Banana");
    getAllProducts(db);
    system("PAUSE");
    return 0;
}
