/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] ????

    ???????????????????????????????????????val ? next?val ????????next ???????????/????????????????????? prev ????????????????????????? 0-index ??

    ????????????

    get(index)??????? index ????????????????-1?
    addAtHead(val)?????????????????? val ???????????????????????
    addAtTail(val)???? val ????????????????
    addAtIndex(index,val)??????? index ????????? val  ?????? index ???????????????????????? index ???????????????
    deleteAtIndex(index)????? index ??????????? index ????
     

    ???

    MyLinkedList linkedList = new MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1,2);   //????1-> 2-> 3
    linkedList.get(1);            //??2
    linkedList.deleteAtIndex(1);  //?????1-> 3
    linkedList.get(1);            //??3
     

    ???

    ????? [1, 1000] ???
    ??????  [1, 1000] ???
    ???????? LinkedList ??

 */
class dListNode {
public:
    int val;
    dListNode* pre;
    dListNode* next;
    dListNode(int x, dListNode* n, dListNode* p): val(x), next(n) , pre(p){}
};

class MyLinkedList {
public:
    dListNode* root;
    dListNode* tail;
    int size;
    /** Initialize your data structure here. */
    MyLinkedList() {
        root = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int cnt = 0;
        dListNode* cur = root;
        while (cur != nullptr) {
            if (cnt == index)
                return cur->val;
            cur = cur->next;
            cnt++;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (root != nullptr) {
            dListNode* cur = new dListNode(val, root, nullptr);
            root->pre = cur;
            root = cur;
        } else {
            root = new dListNode(val, nullptr, nullptr);
            tail = root;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (root != nullptr) {
            dListNode* cur = new dListNode(val, nullptr, tail);
            tail->next = cur;
            tail = cur;
        } else {
            tail = new dListNode(val, nullptr, nullptr);
            root = tail;
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return ;
        } 
        if (index == size) {
            addAtTail(val);
            return ;
        }
        int cnt = 0;
        dListNode* cur = root;
        dListNode* pre = nullptr;
        while (cur != nullptr) {
            if (cnt == index) {
                dListNode* newNode = new dListNode(val, cur, pre);
                if (pre != nullptr)
                    pre->next = newNode;
                cur->pre = newNode;
                size++;
                return;
            }
            pre = cur;
            cur = cur->next;
            cnt++;
        } 
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int cnt = 0;
        dListNode* cur = root;
        dListNode* pre = nullptr;
        if (index == 0) {
            dListNode* old = root;
            root = root->next;
            if (root != nullptr) 
                root->pre = nullptr;
            delete old;
            size--;
            return;
        }
        if (index == size - 1) {
            dListNode* old = tail;
            tail = tail->pre;
            if (tail != nullptr) 
                tail->next = nullptr;
            delete old;
            size--;
            return;
        }
        while (cur != nullptr) {
            if (cnt == index) {
                dListNode* old = cur;
                if (pre != nullptr)
                    pre->next = cur->next;
                if (cur->next != nullptr)
                    cur->next->pre = pre;
                delete old;
                size--;
                return;
            }
            pre = cur;
            cur = cur->next;
            cnt++;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

