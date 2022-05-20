/**
 * Purpose : COMP90077 Adv Algs & DS (2022) - Assignment 2
 * @author Zhen Cai (1049487) <zhcai@student.unimelb.edu.au>
 */

#include "treap.h"

/**
 * Rotation in direction d at node p.
 */
void Treap::rotate(Node * &p, const Direction d) const
{
    Node *new_p;
    if (d == LEFT) {
        new_p = p->right;
        p->right = new_p->left;
        new_p->left = p;
    } else {
        new_p = p->left;
        p->left = new_p->right;
        new_p->right = p;
    }
    p = new_p;
}

/**
 * Insert a new element x.
 */
void Treap::insert(Data *x) {
    insert(root, x);
}

void Treap::insert(Node * &p, Data *x) const
{
    // Insert x to an appropriate leaf position in the BST
    if (!p) {
        p = new Node(x);
    }
    else if (x->key < p->data->key ||
            (x->key == p->data->key && x->id < p->data->id)) {
        insert(p->left, x);
    }
    else {
        insert(p->right, x);
    }

    // Resolve the heap property violations by rotations
    if (p->left && p->left->priority < p->priority) {
        rotate(p, RIGHT);
    }
    else if (p->right && p->right->priority < p->priority) {
        rotate(p, LEFT);
    }
}

/**
 * Delete an arbitrary element (if it exists) from the treap with the search key.
 */
void Treap::remove(const int key) {
    remove(root, key);
}

void Treap::remove(Node * &p, const int key) const
{
    if (!p) {
        return;
    }
    else if (p->data->key < key) {
        remove(p->right, key);
    }
    else if (p->data->key > key) {
        remove(p->left, key);
    }
    // Found x in the BST.
    // Increase x’s priority to infinity, and resolve the heap property violations by rotations.
    // As a result, it will be rotated to become a leaf then removed.
    else {
        if (!p->left) {
            delete p;
            p = p->right;
        }
        else if (!p->right) {
            delete p;
            p = p->left;
        }
        else {
            if (p->left->priority < p->right->priority) {
                rotate(p, RIGHT);
                remove(p->right, key);
            } else {
                rotate(p, LEFT);
                remove(p->left, key);
            }
        }
    }
}



/**
 * Return an arbitrary element (if it exists) that has a search key; otherwise, return NULL.
 * The same way as a BST search.
 */
Data *Treap::search(const int key) const
{
    Node *p = root;
    while (p) {
        if (p->data->key == key) {
            return p->data;
        }
        else {
            p = p->data->key < key ? p->right : p->left;
        }
    }
    return NULL;
}

void Treap::free(Node *subroot) const
{
    if (root) {
        delete root->data;
        delete root->left;
        delete root->right;
        delete root;
    }
}

Treap::~Treap() {
    free(root);
}
