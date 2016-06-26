#ifndef __HEAP_H__
#define __HEAP_H__
#include <list>
      
class TreeNode {
    public:
    int value;
    int key;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode* parent;
    
    
    TreeNode(int key, int value) {
        this->key = key;
        this->value = value;
        leftChild = NULL;
        rightChild = NULL;
        parent = NULL;
    }
    
    /*
     * @Overload operator
     */
    bool operator < (const TreeNode& anotherNode);
    
    /*
     * @Overload operator
     */
    bool operator > (const TreeNode& anotherNode);
    
};


class BinaryHeap {
    
    
    
    public:
    bool isMaxHeap;
    TreeNode * root;
    int size;
    /*
    * If isMaxHeap == true, initialize as a MaxHeap.
    * Else, initialize as a MinHeap.
    */
    BinaryHeap(bool max);
    
    
    /*
    * Given an array of TreeNode elements, create the heap.
    * Assume the heap is empty, when this is called.
    */
    void heapify(int size, TreeNode * nodes);
    
    /*
    * insert the node into the heap.
    * return false, in case of failure.
    * return true for success.
    */
    bool insert(TreeNode * node);
    bool insertInternal(TreeNode * node, TreeNode * root, std::list<bool> bits);
    void bubbleUp(TreeNode* node);
    void bubbleDown(TreeNode* node);
    TreeNode* findLastNode();
    void setMaxHeap(bool val);
    void downHeap(TreeNode * root);
    
    void heapSort();
    /*
     * Return the minimum element of the min-heap [max element of max-heap]
     */
    TreeNode * extract();
    
    /*
     * Return the current size of the Heap.
     */
    int sizeHeap();
    void peek();
    
};

#endif
