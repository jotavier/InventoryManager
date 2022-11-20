#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#define PRODUCT_TABLE_NAME "products"
#define HEADER_ID "Id"
#define HEADER_DESCRIPTION "Descricao"
#define HEADER_AMOUNT "Quantidade"
#define HEADER_PRICE "Preco"

typedef struct Product
{
    unsigned long id;
    unsigned long amount;
    double price;
    char description[255];
} Product;

#endif // PRODUCT_H_INCLUDED
