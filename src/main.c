#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void)
{
    Bst *bst = bst_create(50);
    bst_insert(bst, 90);
    bst_insert(bst, 81);
    bst_insert(bst, 40);

    printf("Max depth reached was %d\n", bst_depth(bst));

    printf("#--- Pre-Order ---#\n");
    bst_dfs_preord(bst);
    printf("#--- In-Order ---#\n");
    bst_dfs_inord(bst);
    printf("#--- Post-Order ---#\n");
    bst_dfs_pstord(bst);

    printf("Sum of the leafs is %d\n", bst_leaf_sum(bst));

    bst_destroy(bst);
    return EXIT_SUCCESS;
}