#include "bst_catalog.h"

VendorNode* createVendorNode(int id, const char* name, const char* menu) {
    VendorNode* newNode = (VendorNode*)malloc(sizeof(VendorNode));
    newNode->vendorID = id;
    strcpy(newNode->vendorName, name);
    strcpy(newNode->dailyMenu, menu);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

VendorNode* insertVendorBST(VendorNode* root, int id, const char* name, const char* menu) {
    if (root == NULL) return createVendorNode(id, name, menu);
    
    // O(log n) recursive placement based on vendor ID key
    if (id < root->vendorID)
        root->left = insertVendorBST(root->left, id, name, menu);
    else if (id > root->vendorID)
        root->right = insertVendorBST(root->right, id, name, menu);
        
    return root;
}

VendorNode* searchVendorBST(VendorNode* root, int id) {
    if (root == NULL || root->vendorID == id) return root;
    if (id < root->vendorID) return searchVendorBST(root->left, id);
    return searchVendorBST(root->right, id);
}

void inOrderTraversalBST(VendorNode* root) {
    if (root != NULL) {
        inOrderTraversalBST(root->left);
        printf("Vendor ID: %d | Name: %s | Menu: %s\n", root->vendorID, root->vendorName, root->dailyMenu);
        inOrderTraversalBST(root->right);
    }
}

void freeVendorBST(VendorNode* root) {
    if (root != NULL) {
        freeVendorBST(root->left);
        freeVendorBST(root->right);
        free(root);
    }
}