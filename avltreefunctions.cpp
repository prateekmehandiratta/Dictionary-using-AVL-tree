#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include "nodeclass.hpp"
#include "entryclass.hpp"
#include "avltree.hpp"
using namespace std;

int max(int a,int b)
{
    if(a>=b)
        return a;
    return b;
}

int comp(string s1,string s2)
{
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if(s1==s2)
        return 0;
    int l1=s1.size();
    int l2=s2.size();
    int diff = l1 - l2;
    int loop;
    if(diff>=0)
        loop = l2;
    else
        loop = l1;
    for(int i=0;i<loop;i++)
    {
        int a1=s1[i];
        int a2=s2[i];
        if(a1<a2)
            return 1;
        else if(a1>a2)
            return -1;
    }
    if(diff>0)
        return -1;
    else if(diff<0)
        return 1;
}

tree::tree(void)
{
    root = NULL;
    entries=0;
}

int tree::height(node* n)
{
    if(n == NULL)
        return 0;
    return n->height;
}

int tree::height_diff(node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

node* tree::right_rotation(node *y)
{
    node *x = y->left;
    node *T = x->right;
    x->right = y;
    y->left = T;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}

node* tree::left_rotation(node *x)
{
    node *y = x->right;
    node *T = y->left;
    y->left = x;
    x->right = T;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}

node* tree::insertion(node* n, entry* e) 
{
    if (n == NULL)                             
    {
        node* new_node = new node;
        new_node->e = e;
        return new_node;
    }
    if(comp(e->word,n->e->word)==0)                       
    {
        n->e = e;
        --entries;
        return n;
    }
    else if(comp(n->e->word,e->word)==1)      
        n->right = insertion(n->right, e);
    else if(comp(e->word,n->e->word)==1)        
        n->left  = insertion(n->left, e);

    n->height = 1 + max(height(n->left),height(n->right));   
    int diff = height_diff(n);     

    if (diff > 1 && comp(e->word,n->left->e->word)==1)  
        return right_rotation(n);
    else if (diff > 1 && comp(n->left->e->word,e->word)==1)    
    {
        n->left =  left_rotation(n->left);
        return right_rotation(n);
    }
    else if (diff < -1 && comp(n->right->e->word,e->word)==1)  
        return left_rotation(n);
    else if (diff < -1 && comp(e->word,n->right->e->word)==1)   
    {
        n->right = right_rotation(n->right);
        return left_rotation(n);
    }

    return n; 
}

void tree::add(string l)
{
    /*****************   WORD & MEANING EXTRACTION   ***********/
    transform(l.begin(),l.end(),l.begin(),::tolower);
    int i=0;
    string w="";
    while(isalpha(l[i]))
    {
    	w = w + l[i];
    	i++;
    }
    string m = &l[i];
    entry* e = new entry(w,m);
    /**********************  INSERTION  ************************/
    ++entries;
    node* new_node = insertion(root,e);
    root = new_node;
    /***********************************************************/
}

int tree::size(void)
{
    return entries;
}

void tree::search(string w)
{
    if(entries == 0)
    {
        cout << "tree is empty" << endl;
        return;
    }
    node* temp = root;
    while(temp!=NULL)
    {
        if(temp->e->word == w)
        {
            cout << "The meaning of the word is: " << temp->e->mean << endl;
            return;
        }
        else
        {
            if(comp(w,temp->e->word)==1)
            {
                if(temp->left == NULL)
                {
                    cout << "WORD IS NOT PRESENT" << endl;
                    return;
                }
                temp = temp->left;
            }
            else if(comp(temp->e->word,w)==1)
            {
                if(temp->right == NULL)
                {
                    cout << "WORD IS NOT PRESENT" << endl;
                    return;
                }
                temp = temp->right;
            }
        }
    }
}

node* tree::min_val_node(node* n)
{
    node* temp = n;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

node* tree::deletion(node* root, string w)
{
    if (root == NULL)      
    {
        entries++;
        return root;
    }
    if(comp(w,root->e->word)==1)      
        root->left = deletion(root->left, w);
    else if(comp(root->e->word,w)==1)  
        root->right = deletion(root->right, w);
    else
    {
    	if( (root->left!=NULL) && (root->right!=NULL) )
        {
            node* temp = min_val_node(root->right);            
            root->e = temp->e;
            root->right = deletion(root->right, temp->e->word);
        }
        else if( (root->left == NULL) || (root->right == NULL) )   
        {
        	node *temp;
        	if(root->left!=NULL)
        		temp = root->left;
        	else
        		temp = root->right;
            if (temp == NULL)              
                temp = root,root = NULL;
            else                           
                *root = *temp;             
            free(temp);
        }
        
    }

    if (root == NULL)     
        return root;

    root->height = 1 + max(height(root->left),height(root->right));

    int diff = height_diff(root);
    if (diff > 1 && height_diff(root->left) >= 0)
        return right_rotation(root);
    else if (diff > 1 && height_diff(root->left) < 0)
    {
        root->left =  left_rotation(root->left);
        return right_rotation(root);
    }
    else if (diff < -1 && height_diff(root->right) <= 0)
        return left_rotation(root);
    else if (diff < -1 && height_diff(root->right) > 0)
    {
        root->right = right_rotation(root->right);
        return left_rotation(root);
    }

    return root;
}

void tree::remove(string w)
{
    node* new_node = deletion(root,w);
    root = new_node;
    entries--;
}

void tree::print_level(node* n,int level)
{
    if (n == NULL)
        return;
    if (level == 1)
    {
		if(n!=NULL)
        	cout << n->e->word << "(" << height(n) << ")" << "\t";
    }
    else if (level > 1)
    {
        print_level(n->left, level-1);
        print_level(n->right, level-1);
    }
}

void tree::print(void)
{
    int h = height(root);
    for (int i=1; i<=h; i++)
    {
	    cout << "Level " << i << "\t\t";
            print_level(root, i);
            cout << "\n\n\n";
    }
}

int tree::countAllInRange(node* n,string k1,string k2)
{
    if(n == NULL)
        return 0;
    if(k1==k2 && comp(k1,n->e->word)==0)
	return 1;
    if( (comp(k1,n->e->word)==1 || comp(k1,n->e->word)==0) && (comp(n->e->word,k2)==1 || comp(n->e->word,k2)==0))
        return 1+countAllInRange(n->left,k1,k2)+countAllInRange(n->right,k1,k2);
    else if(comp(n->e->word,k1)==1)
        return countAllInRange(n->right,k1,k2);
    else if(comp(k2,n->e->word)==1)
        return countAllInRange(n->left,k1,k2);
}

int tree::countInRange(string k1,string k2)
{
    return countAllInRange(root,k1,k2);
}

