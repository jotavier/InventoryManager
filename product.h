#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#define PRODUCT_TABLE_NAME "products"
#define MAX_DESCRIPTION_LENGTH 25

typedef struct Product
{
    unsigned long amount;
    double price;
    char description[MAX_DESCRIPTION_LENGTH];
} Product;

#endif // PRODUCT_H_INCLUDED
