#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "database.h"

int main()
{
    sqlite3 *db = getDatabase();
    Product prod = {.amount=5, .price=55.8, .description="Arroz"};
    Product prod2 = {.amount=5, .price=55.8, .description="Banana"};
    Product prod3 = {.amount=5, .price=55.8, .description="Macarrao"};
    Product prod4 = {.amount=5, .price=55.8, .description="Chinelo"};
    saveProduct(db, &prod);
    saveProduct(db, &prod2);
    saveProduct(db, &prod3);
    saveProduct(db, &prod4);
    // deleteProductById(db, 1);
    // findProductById(db, 1);
    // findProductByDescription(db, "Arr");
    getAllProducts(db);
    system("PAUSE");
    return 0;
}
