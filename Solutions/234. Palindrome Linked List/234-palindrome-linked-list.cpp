    // LeetCode: 234. Palindrome Linked List

    /*
        Coded by Fatih Cinar
        on November 26th, 2019
    */

#include <iostream>

using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
                                   
};

/* PART FOR THE LEETCODE */

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {

        ListNode* whereLeft = NULL; 
        // a pointer that show where we left the last time
        // at the end of the linked list 

        ListNode* symmetry = NULL;
        // an iterator for the symmetry of a node 
        // it will point to the symmetry of a node

        ListNode* iterator = head;
        // an iterator that starts from head

        if (iterator == NULL || iterator->next == NULL)  return true;
        // if linked list is empty or 
        // the case that linked list has one element
        // it is palindrome

        /* This algorithm is to be used it there are at least 2 elements */
        while(true){

            // symmetry is the previous of WHERE WE LEFT
            // go to the symmetry of the node that iterator points to 
            symmetry = head;
            while(symmetry->next != whereLeft){
                symmetry = symmetry->next;
            }

            if(iterator->val == symmetry->val){
                // if this node and its symmetry node are the SAME
                // for these pairs, IT'S ALRIGHT
                // Keep Searching
                whereLeft = symmetry; // next time remember where we left 
                // and search to that point
                iterator = iterator->next; 
                // move on the linked list by one node 

                /* EXIT CASES */ 
                if(iterator->next == whereLeft) return true; 
                // ODD NUMBERED LINKED LIST CASE 
                // this is the middle node situation , no need to check furhermore
                if (iterator == whereLeft) return true;
                // EVEN NUMBERED LINKED LIST 
                // this means we have checked all nodes

            }
            else{
                // if this node and its symmetry node are NOT THE SAME
                // this breaks being palindrome 
                return false;
            }

        }

    }
};


/* BELOW is for testing the algorithm */

void InsertEnd(ListNode** head,int value){

    ListNode* newNode = new ListNode(value);


    if (*head == NULL){
        *head = newNode;
        return;
    }
    else{
        // go to the end of the element
        ListNode* iterator = *head;
        
        while(iterator->next != NULL){ iterator = iterator->next;}

        iterator->next = newNode;

        return;
    }

}

void Display(ListNode* head){
    ListNode* iterator = head;

    cout << "< " ;

    while(iterator != NULL){
        cout << iterator->val << " " ;
        iterator = iterator->next;
    }

    cout << " >" << endl;
}

int main(){

    Solution solution;

    // TEST CASES
    
    ListNode* head1 = NULL;    // 9 1 5 7
    InsertEnd(&head1, 9);
    InsertEnd(&head1, 1);
    InsertEnd(&head1, 5);
    InsertEnd(&head1, 7);

    ListNode *head2 = NULL; // 4 3 2 9 9 2 3 4
    InsertEnd(&head2, 4);
    InsertEnd(&head2, 3);
    InsertEnd(&head2, 2);
    InsertEnd(&head2, 9);
    InsertEnd(&head2, 9);
    InsertEnd(&head2, 2);
    InsertEnd(&head2, 3);
    InsertEnd(&head2, 4);

    ListNode *head3 = NULL; // 1 3 5 3 1
    InsertEnd(&head3, 1);
    InsertEnd(&head3, 3);
    InsertEnd(&head3, 5);
    InsertEnd(&head3, 3);
    InsertEnd(&head3, 1);

    ListNode *head4 = NULL; // 1 2
    InsertEnd(&head4, 1);
    InsertEnd(&head4, 2);

    ListNode *head5 = NULL; // 7
    InsertEnd(&head5, 7);

    ListNode *head6 = NULL; // 7 9 2 1 8 5 3 2 1 0 
    InsertEnd(&head6, 7);
    InsertEnd(&head6, 9);
    InsertEnd(&head6, 2);
    InsertEnd(&head6, 1);
    InsertEnd(&head6, 8);
    InsertEnd(&head6, 5);
    InsertEnd(&head6, 3);
    InsertEnd(&head6, 2);
    InsertEnd(&head6, 1);
    InsertEnd(&head6, 0);

    ListNode* testArray[6] = {head1, head2, head3, head4, head5, head6};


    for(int S = 0; S < 6 ; S++){
        Display(testArray[S]);
        if (solution.isPalindrome(testArray[S])){
            cout << "Palindrome" << endl;
        }
        else{
            cout << "Not-palindrome" << endl;
        }
    }

    return 0;
}
