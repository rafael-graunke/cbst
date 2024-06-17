#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

typedef struct s_bst
{
    struct s_bst *left;
    struct s_bst *right;
    int value;
} Bst;

Bst *bst_create(int value)
{
    Bst *bst = (Bst *)malloc(sizeof(Bst));
    bst->value = value;
    bst->left = bst->right = NULL;

    return bst;
}

void bst_destroy(Bst *bst)
{
    /*
        This is actually just a post-order DFS for
        freeing all nodes of the three :)
    */
    if (bst == NULL)
        return;

    bst_destroy(bst->left);
    bst_destroy(bst->right);
    free(bst);
}

bool bst_insert(Bst *bst, int value)
{
    if (value > bst->value)
    {
        if (bst->right != NULL)
            return bst_insert(bst->right, value);

        bst->right = bst_create(value);
        return true;
    }

    if (value < bst->value)
    {
        if (bst->left != NULL)
            return bst_insert(bst->left, value);

        bst->left = bst_create(value);
        return true;
    }

    return false;
}

void dfs_depth(Bst *bst, int curr, int *depth)
{
    if (bst == NULL)
        return;

    if (curr > *depth)
        *depth = curr;

    dfs_depth(bst->left, curr + 1, depth);
    dfs_depth(bst->right, curr + 1, depth);
}

void dfs_leaf_sum(Bst *bst, int *value)
{
    if (bst == NULL)
        return;

    if (bst->left == NULL && bst->right == NULL) // Reached a leaf
        *value += bst->value;

    dfs_leaf_sum(bst->left, value);
    dfs_leaf_sum(bst->right, value);
}

int bst_depth(Bst *bst)
{
    int depth = 0;
    dfs_depth(bst, 1, &depth);
    return depth;
}

int bst_leaf_sum(Bst *bst)
{
    int leaf_sum = 0;
    dfs_leaf_sum(bst, &leaf_sum);

    return leaf_sum;
}

void bst_dfs_preord(Bst *bst)
{
    if (bst == NULL)
        return;

    printf("%d\n", bst->value);
    bst_dfs_preord(bst->left);
    bst_dfs_preord(bst->right);
}

void bst_dfs_inord(Bst *bst)
{
    if (bst == NULL)
        return;

    bst_dfs_inord(bst->left);
    printf("%d\n", bst->value);
    bst_dfs_inord(bst->right);
}

void bst_dfs_pstord(Bst *bst)
{
    if (bst == NULL)
        return;

    bst_dfs_pstord(bst->left);
    bst_dfs_pstord(bst->right);
    printf("%d\n", bst->value);
}
