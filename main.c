#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "database.h"

int main()
{
    getInventory();
    Product prod = {.description="Banana"};
    save(&prod);
    getProductById(1);
    getAllProducts();
    return 0;
}
