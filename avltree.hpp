#pragma once
#include <iostream>
#include <string.h>
#include "nodeclass.hpp"
#include "entryclass.hpp"
using namespace std;

class tree
{
public:
    node* root;
    int entries;
/**********INTERFACE***********************/
    void add(string);
    void remove(string);
    void search(string);
    int size(void);
    int countInRange(string,string);
    void print(void);
/******************************************/   
    tree();
    void print_level(node* ,int );
    int height(node* );
    int height_diff(node* );
    node *right_rotation(node* );
    node *left_rotation(node* );
    node* insertion(node*,entry*);
    node * min_val_node(node* );
    node* deletion(node* ,string);
    int countAllInRange(node*,string,string);
};
