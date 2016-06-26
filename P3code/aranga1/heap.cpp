#include <iostream>
#include <cstdlib>
#include <list>
#include "heap.h"

using namespace std;

    bool TreeNode::operator < (const TreeNode& anotherNode) {
        // TODO : add your logic here.
        return false;
    }
    
    bool TreeNode::operator > (const TreeNode& anotherNode) {
        // TODO : add your logic here.
        return false;
    }
    
    /*
    * If isMaxHeap == true, initialize as a MaxHeap.
    * Else, initialize as a MinHeap.
    */
    BinaryHeap::BinaryHeap(bool max) {
        this->isMaxHeap = max;
        root = NULL;
        size = 0;
        // TODO : add your logic here.
    }
    
    /*
    * Given an array of TreeNode elements, create the heap.
    * Assume the heap is empty, when this is called.
    */
    //void BinaryHeap::heapify(int size, TreeNode * nodes) {
        
        // TODO : add your logic here.
    //}
    
    /*
    * insert the node into the heap.
    * return false, in case of failure.
    * return true for success.
    */
    bool BinaryHeap::insert(TreeNode * node) {
        //this is the insert that I call from the main method. It calls insertInternal which is a recursive method that does the actual insertion
        if (root == NULL) {
            //in the case of an empty heap
            root = node;
            root->parent = NULL;
            size++;
            return true;
        }
        //using a list to hold the binary of the value we need to get to
        list<bool> bits;
        int sizeT = size + 1;
        while (sizeT != 0) {
            if (sizeT & 1) {
                bits.push_front(true);
            }
            else {
                bits.push_front(false);
            }
            sizeT = sizeT >> 1;
        }
        bits.pop_front();
        
        TreeNode * temp = root;
        bool t;
        int i = 0;
        while (bits.size() != 1) {
            t = bits.front();
            bits.pop_front();
            if (t) {
                temp = temp->rightChild;
            } else {
                temp = temp->leftChild;
                
            }
        }
        
        t = bits.front();
        bits.pop_front();
        if (t) {
            node->parent = temp;
            temp->rightChild = node;
            size++;
        }
        else {
            node->parent = temp;
            temp->leftChild = node;
            size++;
        }
        //call bubbleup or bubbledown based on isMaxHeap value to maintain heap structure
        if (isMaxHeap) {
            bubbleUp(node);//finish this
        }
        else {
            bubbleDown(node);//finish this
        }
        return true;
        // TODO : add your logic here.
    }

void BinaryHeap::bubbleUp(TreeNode * node) {
    //to maintain heap structure in case of maxHeap
    if (node->parent == NULL) {
        return;
    }
    if (size == 0) {
        cout << "empty\n";
    }
    else if (node->parent->key < node->key) {
        int temp = node->key;
        int temp1 = node->value;
        node->key = node->parent->key;
        node->value = node->parent->value;
        node->parent->key = temp;
        node->parent->value = temp1;
        
        bubbleUp(node->parent);
    }
}

void BinaryHeap::bubbleDown(TreeNode * node) {
    //to maintain heap structure in case of minHeap
    if (node->parent == NULL) {
        return;
    }
    if (size == 0) {
        cout << "empty\n";
    }
    else if (node->parent->key > node->key) {
        int temp = node->key;
        int temp1 = node->value;
        node->key = node->parent->key;
        node->value = node->parent->value;
        node->parent->key = temp;
        node->parent->value = temp1;
        
        bubbleDown(node->parent);
    }
}

void BinaryHeap::downHeap(TreeNode * rootNode) {
    //the heapify method that keeps the heap in check after the root is removed
    TreeNode * node = rootNode;
    if(size == 0){
        cout<<"empty"<<endl;
    }
    if(isMaxHeap == true){
        // a lot of cases need to be taken care of :
        
        if (node->leftChild != NULL && node->rightChild != NULL) {
            //  check of when both children exist
            if (node->key < node->leftChild->key && node->key < node->rightChild->key) {
                if (node->leftChild->key > node->rightChild->key) {
                    // if the leftChild is lesser than the right child
                    int tempv = node->value;
                    int tempk = node->key;
                    node->key = node->leftChild->key;
                    node->value = node->leftChild->value;
                    node->leftChild->key = tempk;
                    node->leftChild->value = tempv;
                    downHeap(node->leftChild);
                } else {
                    // if rightChild is lesser than the left child
                    int tempv = node->value;
                    int tempk = node->key;
                    node->key = node->rightChild->key;
                    node->value = node->rightChild->value;
                    node->rightChild->key = tempk;
                    node->rightChild->value = tempv;
                    downHeap(node->rightChild);
                }
            } else if (node->key < node->leftChild->key && node->key > node->rightChild->key) {
                // if the leftChild is smaller & rightChild is greater than the  parent
                int tempv = node->value;
                int tempk = node->key;
                node->key = node->leftChild->key;
                node->value = node->leftChild->value;
                node->leftChild->key = tempk;
                node->leftChild->value = tempv;
                downHeap(node->leftChild);
            } else if (node->key > node->leftChild->key && node->key < node->rightChild->key) {
                // if the rightChild is smaller & leftChild is greater than parent
                int tempv = node->value;
                int tempk = node->key;
                node->key = node->rightChild->key;
                node->value = node->rightChild->value;
                node->rightChild->key = tempk;
                node->rightChild->value = tempv;
                downHeap(node->rightChild);
            }
        } else if (node->rightChild == NULL && node->leftChild != NULL) {
            //  if Only the leftChild exists and is smaller than the parent
            if (node->leftChild->key > node->key) {
                
                int tempv = node->value;
                int tempk = node->key;
                node->key = node->leftChild->key;
                node->value = node->leftChild->value;
                node->leftChild->key = tempk;
                node->leftChild->value = tempv;
            }
        }
    }
    
    else if (isMaxHeap == false) {
        if (node->leftChild != NULL && node->rightChild != NULL) {
            //  chek when both children exist
            if (node->key > node->leftChild->key && node->key > node->rightChild->key) {
                //check for when left child and right child are smaller than the parent
                
                if (node->leftChild->key < node->rightChild->key) {
                    // if the leftChild is lesser than the right child
                    
                    int tempv = node->value;
                    int tempk = node->key;
                    node->key = node->leftChild->key;
                    node->value = node->leftChild->value;
                    node->leftChild->key = tempk;
                    node->leftChild->value = tempv;
                    
                    downHeap(node->leftChild);
                } else {
                    // rightChild is lesser than the left child
                    int tempv = node->value;
                    int tempk = node->key;
                    node->key = node->rightChild->key;
                    node->value = node->rightChild->value;
                    node->rightChild->key = tempk;
                    node->rightChild->value = tempv;
                    
                    downHeap(node->rightChild);
                }
            } else if (node->key > node->leftChild->key && node->key < node->rightChild->key) {
                // leftChild is smaller & rightChild is greater than parent
                
                int tempv = node->value;
                int tempk = node->key;
                node->key = node->leftChild->key;
                node->value = node->leftChild->value;
                node->leftChild->key = tempk;
                node->leftChild->value = tempv;
                
                downHeap(node->leftChild);
                
            } else if (node->key < node->leftChild->key && node->key > node->rightChild->key) {
                
                // rightChild is smaller & leftChild is greater than parent
                
                
                int tempv = node->value;
                int tempk = node->key;
                node->key = node->rightChild->key;
                node->value = node->rightChild->value;
                node->rightChild->key = tempk;
                node->rightChild->value = tempv;
                
                downHeap(node->rightChild);
            }
        } else if (node->rightChild == NULL && node->leftChild != NULL) {
            // Only the leftChild exists
            
            
            if (node->leftChild->key < node->key) {
                // The existing leftChild is smaller than parent
                
                int tempv = node->value;
                int tempk = node->key;
                node->key = node->leftChild->key;
                node->value = node->leftChild->value;
                node->leftChild->key = tempk;
                node->leftChild->value = tempv;
            }
        }
    }
}

TreeNode* BinaryHeap::findLastNode() {
    //finds last node in heap structure
    list<int> bits;
    int sizeT = size;
    while (sizeT != 0) {
        if (sizeT & 1) {
            bits.push_front(true);
        } else {
            bits.push_front(false);
        }
        
        sizeT = sizeT >> 1;
    }
    // Omit the first bit
    bits.pop_front();
    TreeNode * traverse = root;
    bool temp;
    int ct = 1;
    while (bits.size() != 0) {
        temp = bits.front();
        bits.pop_front();
    
        if (temp) {
            traverse = traverse->rightChild;
        } else {
            traverse = traverse->leftChild;
            if (traverse == NULL) {
            }
        }
    }
    return traverse;
}

void BinaryHeap::setMaxHeap(bool val) {
    isMaxHeap = val;
}
    
    /*
     * Return the minimum element of the min-heap [max element of max-heap]
     */
    TreeNode * BinaryHeap::extract() {
        //removes the root node. Works in both cases, min heap or max heap
        if (root == NULL) {
            //root is null. Return empty object
            return NULL;
        }
        TreeNode * temp = new TreeNode(root->key, root->value);
        
        if (root == findLastNode()) {
            //root is the only node there
            root = NULL;
            size--;
            return temp;
        }
        TreeNode* last = findLastNode();
        root->key = last->key;
        root->value = last->value;
        TreeNode * parent = last->parent;
        if (parent->leftChild == last) {
            parent->leftChild = NULL;
        }
        else {
            parent->rightChild = NULL;
        }
        size--;
        downHeap(root);
        return temp;
    }
    
    /*
     * Return the current size of the Heap.
     */
    int BinaryHeap::sizeHeap() {
        //returns the current size of the heap
        return size;
    }
    
    void BinaryHeap::heapSort() {
        //sorts the heap
        int sizeTemp = size;
        while (sizeTemp != 0) {
            TreeNode * req = extract();
            cout << req->key << " " << req->value << endl;
            sizeTemp--;
        }
    }
void BinaryHeap::peek() {
    //peeks the root element. Prints 'empty' if root is null
    if (root == NULL) {
        cout << "empty\n";
        return;
    }
    TreeNode* temp = root;
    cout << temp->key << " " << temp->value << endl;
}
