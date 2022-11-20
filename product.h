#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#define PRODUCT_TABLE_NAME "products"

typedef struct Product
{
    unsigned long amount;
    double price;
    char description[25];
} Product;

#endif // PRODUCT_H_INCLUDED
