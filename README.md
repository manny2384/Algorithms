# Algorithms

## Graph Theory
- [Bellman Ford](/graphs/bellman.cpp)
- [Depth First Search](/graphs/dfs.cpp)

## Sorting Algorithms
- [Merge Sort](/sort/mergesort.cpp)
- [Quick Sort](/sort/quicksort.cpp)

## Searching Algorithms
- [Breadth First Search](/search/bfs.cpp) of Missionary and Cannibals Problem

## Data Structures

## Dynamic Programming
- [Fibonacci Sequence](/dp/fibonacci.cpp)

## Linked Lists

### Remove Linked List Elements
```
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        
        while(head->val == val && head != NULL)
        {
            head = head->next;
            if(head == NULL) return NULL;
        }
        
        if(head->next)
            head->next = removeElements(head->next, val);
        
        
        return head;
    }
};
```
### Odd Even Linked List
```
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        

        ListNode * odd = head, * even = head->next, * evenHead = head->next;
   
        while(odd != NULL && even != NULL){

            odd->next = odd->next->next;
            
            
            if(odd->next == NULL){
                odd->next = evenHead;
                return head;
            }
            
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
            
        }
        
        odd->next = evenHead;
        
        
        return head;
    }
```
### Palindrome Linked List

```
    bool checkList(ListNode* &a, ListNode * &b){
        if(b == NULL){
            return true;
        }    
        
        bool returner = checkList(a, b->next);
        
        returner = (returner && a->val == b->val) ? true : false;
        
        a = a->next;

        
        return returner;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head->next == NULL || head == NULL) return true;
        
        int count = 0;
        ListNode * itr = head;
        while(itr != NULL){
            itr = itr->next;
            count += 1;
        }
        
        ListNode * t = head;
        int idx = 0;
        while(idx < count/2){
            t = t->next;
            idx += 1;
        }
        
        
        if(count % 2 == 1) t = t->next;

        

        return checkList(head, t);
        
    }
```