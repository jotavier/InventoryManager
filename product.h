#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED


typedef struct Product {
    unsigned long id;
    unsigned long amount;
    char *description;
} Product;

void save(Product *product);
Product getProductById(unsigned long id);
Product* getAllProducts();

#endif // PRODUCT_H_INCLUDED
