#include <iostream>
#include <fstream>
#include "avltree.hpp"
#include "entryclass.hpp"
#include "nodeclass.hpp"
using namespace std;

int main()
{
    tree h;
    int n=1;
    while(n)
    {
        cout << "AVL TREE" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Load from input file" << endl;
        cout << "2. Enter keys manually" << endl;
        cin >> n;
        switch(n)
        {
            case 1:{h.root = NULL;
                    h.entries = 0;
                    string line;
                    fstream file;
                    file.open("words.txt");
                    while(!file.eof())
                    {
                        getline(file,line);
                        h.add(line);
                    }
                    int x=1;
                    while(x)
                    {
                        cout << "\t0. Exit" << endl;
                        cout << "\t1. Add key" << endl;
                        cout << "\t2. Remove key" << endl;
                        cout << "\t3. Size of the tree" << endl;
                        cout << "\t4. Search a key" << endl;
                        cout << "\t5. Print the tree in level order" << endl;
                        cout << "\t6. Count in range function" << endl;
                        cin >> x;
                        switch(x)
                        {
                            case 1:{cout << "\tEnter the word with the meaning in same line : " ;
                           			string s;
                                    getline(std::cin,s);
                    				getline(std::cin,s);
                                    h.add(s);
                                    break;
                            }
                            case 2:{cout << "\tEnter the word : ";
                                    string s;
                                    cin >> s;
                                    h.remove(s);
                                    break;
                            }
                            case 3:{cout << "\tNo. of entries in the tree is : " << h.size() << endl;
                                    break;
                            }
                            case 4:{cout << "\tEnter the word : ";
                                    string s;
                                    cin >> s;
                                    h.search(s);
                                    break;
                            }
                            case 5:{h.print();
                                    break;
                            }
                            case 6:{cout << "\tEnter the two keys" << endl;
                                    string k1,k2;
                                    cout << "\tk1 : ";
                                    cin >> k1;
                                    cout << "\n\tk2 : ";
                                    cin >> k2;
                                    cout << "\tNo. of entries in between k1 and k2 : " << h.countInRange(k1,k2) << endl;
                                    break;
                            }
                            default: break;
                        }
                    }
                    break;
            }
            case 2:{h.root = NULL;
                    h.entries = 0;
                    int x=1;
                    while(x)
                    {
                        cout << "\t0. Exit" << endl;
                        cout << "\t1. Add key" << endl;
                        cout << "\t2. Remove key" << endl;
                        cout << "\t3. Size of the tree" << endl;
                        cout << "\t4. Search a key" << endl;
                        cout << "\t5. Print the tree in level order" << endl;
                        cout << "\t6. Count in range function" << endl;
                        cin >> x;
                        switch(x)
                        {
                            case 1:{cout << "\tEnter the word with the meaning in same line : " ;
                                    string s;
                                    getline(std::cin,s);
                    				getline(std::cin,s);
                                    h.add(s);
                                    break;
                            }
                            case 2:{cout << "\tEnter the word : ";
                                    string s;
				                    cin >> s;
                                    h.remove(s);
                                    break;
                            }
                            case 3:{cout << "\tNo. of entries in the tree is : " << h.size() << endl;
                                    break;
                            }
                            case 4:{cout << "\tEnter the word : ";
                                    string s;
                                    cin >> s;
                                    h.search(s);
                                    break;
                            }
                            case 5:{h.print();
                                    break;
                            }
                            case 6:{cout << "\tEnter the two keys" << endl;
                                    string k1,k2;
                                    cout << "\tk1 : ";
                                    cin >> k1;
                                    cout << "\n\tk2 : ";
                                    cin >> k2;
                                    cout << "\tNo. of entries in between k1 and k2 : " << h.countInRange(k1,k2) << endl;
                                    break;
                            }
                            default: break;
                        }
                    }
                    break;
            }
            default: break;
        }
    }
    return 0;
}
