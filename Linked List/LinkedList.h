
#ifndef LinkedList_h
#define LinkedList_h

#include "LinkedListInterface.h"

/*********************************** Linked List ***************************************/
template<typename T>
class LinkedList : public LinkedListInterface<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(){
            next = NULL;
        }
        Node(T d) {
            next = NULL;
            this->data = d;
        }
        Node(T d, Node* n) {
            this->data = d;
            this->next = n;
        }
    };
    Node* head;
    
public:
    LinkedList() {
        this->head = NULL;
    }
    ~LinkedList() {
        clear();
    }
    /******************** Iterator Class for PrintList (BONUS) *************************/
    
    class Iterator {
    public:
        
        Iterator(Node* temp) {
            this->temp = temp;
        }
        
        bool operator!=(const Iterator& other) const {
            return (temp != other.temp);
        }
     
        Iterator& operator++() {
            temp = temp->next;
            return *this;
        }
        
        T& operator*() const {
            return temp->data;
        }
        
        Iterator end() {
            Node *temp = NULL;
            return LinkedList<T>::Iterator(temp);
        }
        
    private:
                                                        //private members of the Iterator class
        Node* temp;
    };
    //----------------------------- ^^ End of Iterator class ^^ ------------------------------------
    
    Iterator begin() {
        return LinkedList<T>::Iterator(head);
    }
    
    Iterator end() {
        Node *temp = NULL;
        return LinkedList<T>::Iterator(temp);
    }
    
    /**--------------------------- Duplicate checker ---------------------------*/ // This function is used to check for duplicates
    bool dupChecker(T value){
        Node* dupCheck = head;
        
        if (head == NULL){
            return true;
        }

        while ((dupCheck->next != NULL) || (dupCheck->data == value)){
            if (dupCheck->data == value){
                return false;
            }
            else {
                dupCheck = dupCheck->next;
            }
        }
        
        return true;
    }
    
    /**--------------------------- Insert Node at beginning of list (no duplcates) ---------------------------*/
    virtual bool insertHead(T value){                               
        if (head == NULL){
            head = new Node(value);
            return true;
        }
        else {
            if (dupChecker(value)){
                head = new Node(value,head);
                return true;
            }
            else {
                return false;
            }
        }
    }
    
    /**--------------------------- Insert Node at end of list (no duplcates) ---------------------------*/
    virtual bool insertTail(T value){
       
        if(dupChecker(value)){
            if (head == NULL){
                insertHead(value);
                return true;
            }
            else {
                Node *temp = head;
                while (temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = new Node(value);
                return true;
            }
        }
        else {
            return false;
        }
    }
    /**--------------------------- Insert node after matchNode (no duplicates) ---------------------------*/
    virtual bool insertAfter(T matchNode, T node){
        Node *inRange = head;
        while (inRange->data != matchNode){
            if (inRange->next == NULL){
                return false;
            }
            inRange = inRange->next;
        }

        if (dupChecker(node)){
        
            Node *temp = head;
            while (temp->data != matchNode){                    
                temp = temp->next;
            }
            
            Node *newNode = new Node(node);
            newNode->next = temp->next;
            temp->next = newNode;
            return true;
        }
        else{
            return false;
        }
    }
  
    /**--------------------------- Remove Node from linked list ---------------------------*/
    virtual bool remove(T value){
        
        if (head == NULL){
            return false;
        }
        else if (head->data == value){
            Node *temp = head;
            head = temp->next;
            delete temp;
            return true;
        }
        
        else{
            if (!dupChecker(value)){
                Node *temp = head;
                while (temp->next->data != value){
                    temp = temp->next;
                }
                
                Node *secondTemp =  temp->next;
                temp->next = secondTemp->next;
                delete secondTemp;
                return true;
            }
            else{
                return false;
            }
        }
    }
    /**--------------------------- Remove all Nodes from linked list ---------------------------*/
    virtual bool clear(){
        while (head != NULL){
            remove(head->data);
        }
        
        return true;
    }
    
    /**--------------------------- Return Node at index (0 based) ---------------------------*/
    virtual T at(int index){
        int counter = 0;
        
            if ((head == NULL) || (size() <= index) || (index < 0)){
                throw("Invalid Index");
            }
            else{
                Node *temp = head;
                while (counter != index){
                    temp = temp->next;
                    counter++;
                }
            return temp->data;
        }
    }
    
    /**--------------------------- Returns the number of nodes in the linked list ---------------------------*/
    virtual int size() const{
        int counter = 0;
        Node *temp = head;
        
        if (head == NULL){
            return counter;
        }
        else {
            counter = 1;
            while (temp->next != NULL){
                temp = temp->next;
                counter++;
            }
            return counter;
        }
    }
    /**--------------------------- Prints all data in the linked list ---------------------------*/
    std::string printList (){
        std::stringstream os;
        if (head == NULL){
            os << "Empty";
        }
        else{
            for (LinkedList<T>::Iterator iter(head); iter != iter.end(); ++iter){
                os << *iter << " ";
            }
        }
        return os.str();
    }
};

#endif /* LinkedList_h */
