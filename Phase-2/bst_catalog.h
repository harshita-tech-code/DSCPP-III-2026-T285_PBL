#ifndef BST_CATALOG_H
#define BST_CATALOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct VendorNode {
    int vendorID;
    char vendorName[50];
    char dailyMenu[100];
    struct VendorNode* left;
    struct VendorNode* right;
} VendorNode;

VendorNode* createVendorNode(int id, const char* name, const char* menu);
VendorNode* insertVendorBST(VendorNode* root, int id, const char* name, const char* menu);
VendorNode* searchVendorBST(VendorNode* root, int id);
void inOrderTraversalBST(VendorNode* root);
void freeVendorBST(VendorNode* root);

#endif