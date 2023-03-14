#include <stdio.h>
#include <stdlib.h>
#include "l7ex1.h"
#include "l7ex2.h"
#include "l7ex3.h"
#include "l7ex4.h"
#include "l7ex5.h"
#include "l7ex6.h"
#include "l7ex7.h"
#include "l7ex8.h"
#include "l7ex9.h"

int main(){
    List *lst=create_list();
    insert_list(lst, 1, 0);
    insert_list(lst, 2, 1);
    insert_list(lst, 3, 2);
    print_list(lst);
    printf("Tamanho da lista: %d\n", size_list(lst));
    remove_list(lst, 0);
    print_list(lst);
    printf("Tamanho da lista: %d\n", size_list(lst));
    printf("Na posicao 0 tem o 2 = %d\n", get_elem_list(lst, 0));
    printf("O 3 esta na posicao 1 = %d\n", get_pos_list(lst, 3));
    free_list(lst);
}