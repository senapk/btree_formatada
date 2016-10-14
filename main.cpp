#include <iostream>
using namespace std;

template <class T>
class bnode
{
public:
    T value;
    bnode<T> * left {nullptr};
    bnode<T> * right{nullptr};

    bnode(){
    }

    bnode(T value){
        this->value = value;
    }
};


template <class T>
class btree {
public:
    bnode<T> * root{nullptr};

    btree(){
    }

    void bshow_dual(bnode<T> * node, string heranca, ostream & fout){
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            bshow_dual(node->left , heranca + "l", fout);
        int tam = heranca.size();
        for(int i = 0; i < tam - 1; i++){
            if(heranca[i] != heranca[i + 1])
                fout << "│" << "   ";
            else
                fout << " " << "   ";
        }
        if(heranca != ""){
            if(heranca.back() == 'l')
                fout << "┌───";
            else
                fout << "└───";
        }
        if(node == nullptr){
            fout << "#" << endl;
            return;
        }
        fout << node->value << endl;
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            bshow_dual(node->right, heranca + "r", fout);
    }

};

void gambiFill(btree<int> & t){
    t.root = new bnode<int>(63);
    t.root->left = new bnode<int>(29);
    t.root->left->left = new bnode<int>(20);
    t.root->left->left->left = new bnode<int>(10);
    t.root->left->right = new bnode<int>(38);
    t.root->left->right->left = new bnode<int>(34);
    t.root->left->right->right = new bnode<int>(56);
    t.root->left->right->right->left = new bnode<int>(47);

    t.root->right = new bnode<int>(83);
    t.root->right->left = new bnode<int>(71);
    t.root->right->left->left = new bnode<int>(66);
    t.root->right->left->left->left = new bnode<int>(65);
    t.root->right->left->left->right = new bnode<int>(70);
    t.root->right->left->right = new bnode<int>(74);

    t.root->right->right = new bnode<int>(98);
    t.root->right->right->left = new bnode<int>(96);
}

int main(){
    btree<int> tree;
    gambiFill(tree);
    tree.bshow_dual(tree.root, "", cout);

    return 0;
}








