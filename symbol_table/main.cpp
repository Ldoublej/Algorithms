#include <iostream>
#include <string>
#include "binary_search_st.h"
#include "BST.h"


using namespace std;
int main()
{
    BST<int,string> bst;
    bst.put(1,"offfffffffffffffffffffffne");
    bst.put(2,"two");
    bst.put(3,"thdffdfffe");
    bst.put(5,"five");

    bst.del(1);
    bst.del(55);
    BST<int,string>::pair * min = bst.min();
    min->swap(*min);
    cout << *min->val << endl;
    return 0;
}
