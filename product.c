#include "product.h"

void save(Product *product) {
    printf("Salvando: %s", product->description);
}

Product getProductById(unsigned long id) {
    printf("Buscando pelo produto de id: %ld", id);
}

Product* getAllProducts() {
    printf("Buscando todos os produtos");
}
