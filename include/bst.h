#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>

typedef struct s_bst Bst;

Bst *bst_create(int value);
void bst_destroy(Bst *bst);
bool bst_insert(Bst *bst, int value);
int bst_depth(Bst *bst);
int bst_leaf_sum(Bst *bst);

void bst_dfs_preord(Bst *bst);
void bst_dfs_inord(Bst *bst);
void bst_dfs_pstord(Bst *bst);

#endif