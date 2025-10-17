#include <iostream>
using namespace std;
struct n
{
    int data;
    struct n* fwd;
} n;
struct n* swap(struct n* ptr1, struct n* ptr2)
{
    struct n* tmp = ptr2->fwd;
    ptr2->fwd = ptr1;
    ptr1->fwd = tmp;
    return ptr2;
}
int bubbleSort(struct n** head, int c)
{
    struct n** h;
    int i, j, s;
 
    for (i = 0; i <= c; i++)
    {
        h = head;
        s = 0;
        for (j = 0; j < c - i - 1; j++)
        {
 
            struct n* p1 = *h;
            struct n* p2 = p1->fwd;
 
            if (p1->data > p2->data)
            {
                *h = swap(p1, p2);
                s = 1;
            }
 
            h = &(*h)->fwd;
        }
        if (s == 0)
            break;
    }
}
void printList(struct n* n)
{
    while (n != NULL)
    {
        cout << n->data << " -> ";
        n = n->fwd;
    }
    cout << endl;
}
void insertAtTheBegin(struct n** strt, int data)
{
    struct n* ptr1= (struct n*)malloc(sizeof(struct n));
    ptr1->data = data;
    ptr1->fwd = *strt;
    *strt = ptr1;
}
int main()
{
    int arr[] = { 78, 20, 10, 32, 1, 5 };
    int list_size, i;
    struct n* start = NULL;
    list_size = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < list_size; i++)
        insertAtTheBegin(&start, arr[i]);
    cout <<"Linked list before sorting\n";
    printList(start);
    bubbleSort(&start, list_size);
    cout <<"Linked list after sorting\n";
    printList(start);
    return 0;
}
 
