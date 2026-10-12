#include "vendor_tree.h"

/* Allocates dynamic memory for a new vendor node */
VendorNode* createVendorNode(int id, const char* name, const char* loc, float price) {
    VendorNode* newNode = (VendorNode*)malloc(sizeof(VendorNode));
    if (newNode == NULL) {
        printf("Memory allocation error for VendorNode!\n");
        return NULL;
    }
    newNode->vendorID = id;
    strncpy(newNode->vendorName, name, sizeof(newNode->vendorName) - 1);
    newNode->vendorName[sizeof(newNode->vendorName) - 1] = '\0';
    strncpy(newNode->location, loc, sizeof(newNode->location) - 1);
    newNode->location[sizeof(newNode->location) - 1] = '\0';
    newNode->basePrice = price;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Inserts a new vendor node while maintaining BST property */
VendorNode* insertVendor(VendorNode* root, int id, const char* name, const char* loc, float price) {
    if (root == NULL) {
        return createVendorNode(id, name, loc, price);
    }

    if (id < root->vendorID) {
        root->left = insertVendor(root->left, id, name, loc, price);
    } else if (id > root->vendorID) {
        root->right = insertVendor(root->right, id, name, loc, price);
    } else {
        printf("Vendor ID %d already exists. Duplicate ignored.\n", id);
    }
    return root;
}

/* Searches for a vendor by ID in O(log n) average time */
VendorNode* searchVendor(VendorNode* root, int id) {
    if (root == NULL || root->vendorID == id) {
        return root;
    }
    if (id < root->vendorID) {
        return searchVendor(root->left, id);
    }
    return searchVendor(root->right, id);
}

/* Traverses the BST in-order to print vendors in sorted ID order */
void inOrderTraversal(VendorNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("[ID: %-4d] %-20s | Location: %-15s | Meal: Rs. %.2f\n",
               root->vendorID, root->vendorName, root->location, root->basePrice);
        inOrderTraversal(root->right);
    }
}

/* Safely frees all dynamically allocated nodes in post-order */
void freeVendorTree(VendorNode* root) {
    if (root != NULL) {
        freeVendorTree(root->left);
        freeVendorTree(root->right);
        free(root);
    }
}