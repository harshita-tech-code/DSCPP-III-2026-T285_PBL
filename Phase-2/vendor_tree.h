#ifndef VENDOR_TREE_H
#define VENDOR_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node structure for Vendor Catalog BST */
typedef struct VendorNode {
    int vendorID;                  /* Unique Search Key */
    char vendorName[50];           /* Mess / Vendor Name */
    char location[50];             /* Near PG / Landmark */
    float basePrice;               /* Standard Meal Price */
    struct VendorNode* left;
    struct VendorNode* right;
} VendorNode;

/* Function Prototypes */
VendorNode* createVendorNode(int id, const char* name, const char* loc, float price);
VendorNode* insertVendor(VendorNode* root, int id, const char* name, const char* loc, float price);
VendorNode* searchVendor(VendorNode* root, int id);
void inOrderTraversal(VendorNode* root);
void freeVendorTree(VendorNode* root);

#endif /* VENDOR_TREE_H */