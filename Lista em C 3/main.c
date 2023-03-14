#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    List *lst=create_list();
    insert_list(lst, 1, 0);
    insert_list(lst, 2, 1);
    insert_list(lst, 3, 2);
    insert_list(lst, 4, -1);
    print_list(lst);
    printf("Tamanho da lista: %d\n", size_list(lst));
    remove_list(lst, 0);
    print_list(lst);
    printf("Tamanho da lista: %d\n", size_list(lst));
    printf("Na posicao 0 tem o 1 = %d\n", get_elem_list(lst, 0));
    printf("O 3 esta na posicao 2 = %d\n", get_pos_list(lst, 3));
    free_list(lst);
}