#pragma once
#include <iostream>
#include "entryclass.hpp"
using namespace std;

class node
{
public:
    node();
    entry* e;
    node* left;
    node* right;
    int height;
};

