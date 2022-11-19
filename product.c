#include "product.h"

void save(Product *product) {
    printf("Salvando: %s\n", product->description);
    return;
}

Product* getProductById(unsigned long id) {
    printf("Buscando pelo produto de id: %ld\n", id);
    return;
}

Product* getAllProducts() {
    printf("uscando todos os produtos\n");
    return [];
}
