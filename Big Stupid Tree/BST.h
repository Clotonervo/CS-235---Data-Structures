

#ifndef BST_h
#define BST_h

#include "BSTInterface.h"
#include <sstream>

/** A binary tree node with data, left and right child pointers */
template<typename T>
class BST : public BSTInterface<T> {
private:
    struct Node {                       //my node struct
        T data;
        Node* right;
        Node* left;
        Node(){
            right = NULL;
            left = NULL;
        }
        Node(T d) {
            right = NULL;
            left = NULL;
            this->data = d;
        }
    };
    Node* root_;
    
public:
    BST(){
        root_ = NULL;               //constructor
    }
    
    ~BST(){
        clearTree();                //destructor
    }
    
    
    /************************************ BST iterator ******************************/
  /*  class Iterator
    {
    private:
        Node* root_;
    public:
        Iterator(Node* root) : root_(root),... {}                                   //this is bonus that i didnt do
        ~Iterator() {}
        bool operator!=(const Iterator& rhs) const { ... }
        Iterator operator++(T) { ... }
        T operator*() const { ... }
    };
    Iterator begin() { ... }
    Iterator end() { ... }
    Iterator find(T& value) { ... } */
    /*******************************************************************************/
    
    
    /************************* Return true if node added to BST, else false ************************/
    virtual bool addNode(const T& data){
        if (root_ == NULL){
            root_ = new Node(data);
            return true;
        }
        else {
            if (addNodeTree(data, root_)){
                return true;
            }
        }
        return false;             
    }
    /************************* Return true if node added to BST, else false ************************/
    bool addNodeTree(const T& data, Node*& nodePtr){
        if (nodePtr != NULL && (data < nodePtr->data)){
            addNodeTree(data, nodePtr->left);
            return true;
        }
        else if (nodePtr != NULL && (data > nodePtr->data)){
            addNodeTree(data, nodePtr->right);
            return true;
        }
        else if (nodePtr == NULL){
            nodePtr = new Node(data);
            return true;
        }
        return false;
    }
    /******************************* Returns the predecessor node ******************************/
    Node* predecessor(Node* parent){
        Node* tempNode = parent;
        if (parent->left == NULL){
            tempNode = parent->right;
            while(tempNode->left != NULL){
                tempNode = tempNode->left;
            }
        }
        else {
            tempNode = parent->left;
            while(tempNode->right != NULL){
                tempNode = tempNode->right;
            }
        }
        return tempNode;
    }
    
    /************************* Return true if node removed from BST, else false ************************/
    virtual bool removeNode(const T& data){
        return removeNodeMemory(root_, data);
    }
    
    bool removeNodeMemory(Node*& node,const T& data){           //this is what loops through the tree
        
        if (node == NULL){
            return false;
        }
        else if (data < node->data){
            return removeNodeMemory(node->left, data);          //if data is less, move to left node
        }
        else if (data > node->data){
            return removeNodeMemory(node->right, data);         //if data is more, move to right node
        }
        else {
            if (node->left == NULL && node->right == NULL){ //case 1: no children
                delete node;
				node = NULL;
                return true;
            }
            else if (node->left == NULL){               //case 2: one child
                Node* temp = node;
                node = node->right;
                delete temp;
				temp = NULL;
                return true;
            }
            else if (node->right == NULL){              //case 2: one child
                Node* temp = node;
                node = node->left;
                delete temp;
				temp = NULL;
                return true;
            }
            else {
                Node* temp = predecessor(node);         //case 3: two children
                node->data = temp->data;
                node->left = temp->left;
                delete temp;
				temp = NULL;
                return true;
            }
        }
        return false;
    }
    
    /******************* Return true if BST cleared of all nodes, else false ******************/
    virtual bool clearTree(){
		while (root_ != NULL) {
			removeNode(root_->data);
		}
		return true;
    }

    /************************************ Output nodes at a given level ***********************************/
    bool outLevel(Node* root, int level, std::stringstream& out) const{
        if (root == NULL){
            return false;
        }
        if (level == 0){
            if (root == NULL){
                out << "Empty";
            }
            else{
                out << " " << root->data;
                if ((root->left != NULL) || (root->right != NULL)){
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        if ((level == 1) && !root->left && root->right){
            out << " _";
        }
        bool left = outLevel(root->left, level - 1, out);
        bool right = outLevel(root->right, level - 1, out);
        if ((level == 1) && root->left && !root->right){
            out << " _";
        }
        return left || right;
    }
    
    /********************** Return a level order traversal of a BST as a string **************************/
    virtual string toString() const{
        std::stringstream OS;
        int level = -1;
        
        if(root_ == NULL){
            OS << " Empty";
            return OS.str();
        }
        
        do{
            OS << std::endl << "  " << ++level << ":";
        }while (outLevel(root_, level, OS));

        return OS.str();
    }
    
};

#endif /* BST_h */
