#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1

struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct Book books[MAX_BOOKS];

    for (int i = 0; i < MAX_BOOKS; i++) {
        printf("Enter title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        strtok(books[i].title, "\n");

        printf("Enter author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        strtok(books[i].author, "\n");

        printf("Enter price: ");
        scanf("%f", &books[i].price);
        getchar(); // consume newline after float
    }

    FILE *fptr = fopen("book5.txt", "w");
    if (!fptr) return 1;
    for (int i = 0; i < MAX_BOOKS; i++) {
        fprintf(fptr, "%s\n%s\n%.2f\n", books[i].title, books[i].author, books[i].price);
    }
    fclose(fptr);

    // Just to demonstrate reading back
    struct Book rb;
    fptr = fopen("book5.txt", "r");
    fgets(rb.title, sizeof(rb.title), fptr);
    fgets(rb.author, sizeof(rb.author), fptr);
    fscanf(fptr, "%f", &rb.price);
    fclose(fptr);

    printf("\nTitle: %sAuthor: %sPrice: %.2f\n", rb.title, rb.author, rb.price);
    return 0;
}
