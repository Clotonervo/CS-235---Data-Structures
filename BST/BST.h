

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
        Node* nodeParent;
        Node(){
            right = NULL;
            left = NULL;
        }
        Node(T d) {
            right = NULL;
            left = NULL;
            nodeParent = NULL;
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
    
    
    /*_____________________________________ BST Iterator __________________________________(BONUS)*/
    class Iterator {
    private:
        Node* treeRoot;
        Node* location;
        
    public:
        Iterator(Node* donde, Node* root){              //Iterator constructor
            location = donde;
            treeRoot = root;
        }
        ~Iterator() {}                                  //Destructor
        
        bool operator!=(const Iterator& rhs) const {    // != Operator override
            return (location != rhs.location);
        }
        
        Iterator operator++() {                         //++ Operator override
            Node* temp;
            if (location->right != NULL){
                location = location->right;
                
                while (location->left != NULL){
                    location = location->left;
                }
            }
            else{
                temp = location->nodeParent;
                while (temp != NULL && location == temp->right){
                    location = temp;
                    temp = temp->nodeParent;
                }
                location = temp;
            }
            return *this;
        }
        
        T operator*() const {
            return location->data;
        }
    };
    /*________________________________________________________________________*/
    
    /*_______________________________ Other Iterator stuff ________________________________(BONUS)*/
    Iterator begin(){                           //Iterator begin()
        Node* temp = root_;
        if (root_ == NULL){
            return end();
        }
        else{
            while (temp->left != NULL){
                temp = temp->left;
            }
            return Iterator(temp, root_);
        }
    }
    
    Iterator end(){                               //Iterator end()
        return Iterator(NULL, root_);
    }
    
    /*_____________ Returning True if Iterator is found, else false ___________________________ (BONUS)*/
    bool find(T& value){
        for(Iterator iter = begin(); iter != end(); ++iter){
            if (*iter == value){
                return true;
            }
        }
        return false;
    }
    
    /*________________________________ Iterator: In-Order Printing ______________________________ (BONUS)*/
    string inOrderToString(){
        std::stringstream OS;
        if (root_ == NULL){
            OS << "Empty";
            return OS.str();
        }
        for(Iterator iter = begin(); iter != end(); ++iter){
            OS << *iter << " ";
        }
        return OS.str();
    }
    
    /************************* Return true if node added to BST, else false ************************/
    virtual bool addNode(const T& data){
        if (root_ == NULL){
            root_ = new Node(data);          //adding a root
            return true;
        }
        else {
            if (addNodeTree(data, root_)){      //calling recursive add node function
                return true;
            }
        }
        return false;             
    }
    /************************* Return true if node added to BST, else false ************************/
    bool addNodeTree(const T& data, Node*& nodePtr){
        if (nodePtr != NULL && (data < nodePtr->data)){
            addNodeTree(data,nodePtr->left);
            return true;
        }
        else if (nodePtr != NULL && (data > nodePtr->data)){            //recursive function for adding a node
            addNodeTree(data,nodePtr->right);
            return true;
        }
        else if (nodePtr == NULL){
            nodePtr = new Node(data);
            Node* parent = findParent(nodePtr, root_);
            nodePtr->nodeParent = parent;
            return true;
        }
        return false;
    }
    /******************************* Returns the predecessor node ******************************/
    Node* predecessor(Node* parent){
        Node* tempNode = parent;
            tempNode = parent->left;                    //as stated, returns predecessor
            while(tempNode->right != NULL){
                tempNode = tempNode->right;
            }
        return tempNode;
    }
    /******************************* Returns the parent node ******************************/
    Node* findParent(Node* node, Node* parent){
        if (parent->right == node || parent->left == node){
            return parent;
        }
        else if (node->data < parent->data){                    //as stated, returns the parent node
            return findParent(node,parent->left);
        }
        else if (node->data > parent->data){
            return findParent(node, parent->right);
        }
        return NULL;
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
                node->nodeParent = findParent(node, root_);
                delete temp;
				temp = NULL;
                return true;
            }
            else if (node->right == NULL){              //case 2: one child
                Node* temp = node;
                node = node->left;
                node->nodeParent = findParent(node, root_);
                delete temp;
				temp = NULL;
                return true;
            }
            else {
                Node* temp = predecessor(node);         //case 3: two children
                node->data = temp->data;
                return removeNodeMemory(node->left, temp->data);
            }
        }
        return false;
    }
    
    /******************* Return true if BST cleared of all nodes, else false ******************/
    virtual bool clearTree(){
		while (root_ != NULL) {
			removeNode(root_->data);            //recursive function for delete entire tree
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
                    return false;                               //toString funct for level printing (recusive)
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
        }                                               //toString funct for level printing
        
        do{
            OS << std::endl << "  " << ++level << ":";
        }while (outLevel(root_, level, OS));

        return OS.str();
    }
    
};

#endif /* BST_h */
