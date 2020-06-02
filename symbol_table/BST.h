//
// Created by ldoublej on 2020/4/15.
//

#ifndef SYMBOL_TABLE_BST_H
#define SYMBOL_TABLE_BST_H

template <typename K,typename V>
class BST;


template <typename K,typename V>
struct Node
{
    friend class  BST<K,V>;
    K * key;
    V * val;
    Node(K * k,V * v,int n):key(k),val(v),N(n)
    {

    }
    ~Node()
    {
        delete key;
        delete val;
    }
    void swap(Node & lsh);
    Node & operator=(const Node & lsh)
    {
        this->key = new K(*lsh.key);
        this->val = new V(*lsh.val);
    }
private:
    Node * left, *right;
    int N;
};

template <typename K,typename V>
class BST
{

public:
    typedef Node<K,V> pair;
    BST() = default;
    void put(const K & k,const V & v);
    V* get(const K & k);
    void del(const K & k);
    void del_min();
    bool is_contain(const K & k);
    pair * floor(const K & k);
    int size();
    bool is_empty();
    pair * min();

    ~BST()
    {
        delete root;
    }
private:
    pair * root = nullptr;

    pair * put(pair * node,const K & k,const V & v);
    V * get(pair * node,const K & k);
    int size(pair * node);
    pair * min(pair * node);
    pair * floor(pair * node,const K & k);
    pair * del_min(pair * node);
    pair * del(pair * node,const K & k);
};

template<typename K, typename V>
void Node<K, V>::swap(Node & lsh)
{
    using std::swap;
    swap(this->key,lsh.key);
    swap(this->val,lsh.val);
    swap(this->left,lsh.left);
    swap(this->right,lsh.right);
}

template<typename K, typename V>
void BST<K, V>::put(const K &k, const V &v)
{
    root = put(root,k,v);
}

template<typename K, typename V>
typename BST<K,V>::pair * BST<K, V>::put(BST::pair *node, const K &k,const V & v)
{
    if(node == nullptr)
    {
        K * new_k = new K(k);
        V * new_v = new V(v);
        pair * new_node = new pair(new_k,new_v,1);
        return new_node;
    }

    if(k < *(node->key))
        node->left = put(node->left,k,v);
    else if(k > *(node->key))
        node->right = put(node->right,k,v);
    else
        *(node->val) = v;
    node->N = size(node->left) + size(node->right) + 1;
    return node;
}

template<typename K, typename V>
V *BST<K, V>::get(const K &k)
{
    return get(root,k);
}

template<typename K, typename V>
V *BST<K, V>::get(BST::pair *node, const K &k)
{
    if(node == nullptr)
        return nullptr;
    if(k < *(node->key))
        return get(node->left,k);
    else if(k > *(node->key))
        return get(node->right,k);
    return node->val;
}

template<typename K, typename V>
bool BST<K, V>::is_contain(const K &k)
{
    return get(k) != nullptr;
}

template<typename K, typename V>
int BST<K, V>::size()
{
    return size(root);
}

template<typename K, typename V>
int BST<K, V>::size(BST::pair *node)
{
    if(node == nullptr)
        return 0;
    return node->N;
}

template<typename K, typename V>
bool BST<K, V>::is_empty()
{
    return size(root) == 0;
}

template<typename K, typename V>
typename BST<K,V>::pair *BST<K, V>::min()
{
    if(is_empty())
        return nullptr;
    return min(root);
}

template<typename K, typename V>
typename BST<K,V>::pair *BST<K, V>::min(BST::pair *node)
{
    if(node->left == nullptr)
        return node;
    return min(node->left);
}

template<typename K, typename V>
typename BST<K,V>::pair *BST<K, V>::floor(const K &k)
{

    return floor(root,k);
}

template<typename K, typename V>
typename BST<K,V>::pair *BST<K, V>::floor(BST::pair *node, const K &k)
{
    if(node == nullptr)
        return nullptr;

    if(k < *(node->key))
        return floor(node->left,k);
    else if(k == *(node->key))
        return node;

    pair * ret = floor(node->right,k);
    if(ret == nullptr)
        return node;
    else
        return ret;
}

template<typename K, typename V>
typename BST<K,V>::pair *BST<K, V>::del_min(BST::pair *node)
{
    if(node->left == nullptr)
    {
        pair * r = node->right;
        delete node;
        return r;
    }
    node->left = del_min(node->left);
    node->N = size(node->left) + size(node->right) + 1;
    return node;
}

template<typename K, typename V>
void BST<K, V>::del_min()
{
    root = del_min(root);
}

template<typename K, typename V>
void BST<K, V>::del(const K &k)
{
    root = del(root,k);
}

template<typename K, typename V>
typename BST<K,V>::pair *BST<K, V>::del(BST::pair *node, const K &k)
{
    if(node == nullptr)
        return nullptr;
    if(*(node->key) == k)
    {
        if(node->left == nullptr)
            return node->right;
        if(node->right == nullptr)
            return node->left;
        pair * r_min = min(node->right);
        node = r_min;
        node = del_min(node->right);
    }
    else if(*(node->key) < k)
        node->right = del(node->right,k);
    else
        node->left = del(node->left,k);

    return node;
}

#endif //SYMBOL_TABLE_BST_H
