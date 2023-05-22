 

#include <iostream> 

#include <iomanip> 

#include <cstdlib> 

#include <ctime> 

using namespace std; 

int n = 100, top = -1; 

void RANDNUMBERS(int A[], int n); 

void INSERTIONSORT(int A[], int n); 

void SELECTIONSORT(int A[], int n); 

void SELECTIONSORTGEEKS(int A[], int n); 

void BUBBLESORT(int arr[], int n); 

void SHAKERSORT(int A[], int n); 

void SHELLSORT(int array[], int n); 

int binarySearchRec(int arr[], int l, int r, int x); 

int binarySearchIter(int arr[], int l, int r, int x); 

int LinSearch(int arr[], int n, int x); 

int exponentialSearch(int arr[], int n, int x); 

void Enqueue(); 

void Dequeue(); 

void Display(); 

void push(char val, char array[100]); 

void pop(char array[100]); 

void display(char array[100]); 

void COUNTINGSORT(int A[], int B[], int n); 

void HEAPSORT(int A[], int n); 

void BUILDMAXHEAP(int A[], int n); 

void MAXHEAPIFY(int A[], int i, int heapsize); 

  

int main() 

{ 

    srand(time(0)); 

    const int n = 8; 

    int A[n], j; 

    RANDNUMBERS(A, n); 

    int por; 

    cout << endl; 

    cout << "Enter the number "; 

    cin >> por; 

    int target = LinSearch(A, n, por); 

    if (target == -1) { 

        cout << "there is no..." << endl; 

    } 

    else { 

        cout << "the index is " << target << endl; 

    } 

 

 

  /*  SHELLSORT(A, n); 

    for (int i = 0; i < n; i++) 

    { 

        cout << A[i] << " "; 

    }*/ 

    /*int index = binarySearchIter(A, 0, 7, 8); 

    if (index == -1) { 

        cout << "Not found" << endl; 

    } 

    else { 

        cout << "the number is at the position " << index << endl; 

    } 

    cout << endl; 

    for (int j = 0; j < n; j++) { 

        cout << A[j] << " "; 

    }*/ 

    //int i; 

    //for (i = 0;i < 5;i++) {  

    //    Enqueue(); 

    //} 

    //Dequeue(); 

    //Dequeue(); 

    //Display(); 

    //return 0; 

    /*char stack1[100], stack2[100]; 

    push('a', stack1); 

    push('x', stack2); 

    push('b', stack1); 

    push('y', stack2); 

    push('c', stack1); 

    push('z', stack2); 

    display(stack1); 

    display(stack2);*/ 

 

} 

void RANDNUMBERS(int A[], int n) { 

    for (int i = 0; i < n; i++)  

    { 

        A[i] = 1 + rand() % 10; 

        cout << A[i] << " "; 

             

    } 

} 

//---------------------------------------------------------------------------------------SORTING----------------------------------------------------------------------------------------------- 

//************************************************************************************************************************************************************************************* 

void INSERTIONSORT(int A[], int n) { 

    int counter = 0; //     key = 1; 

    for (int j = 1; j < n; j++)            //1 4 5 7 15 46 78  

    { 

        int key = A[j]; 

        int i = j - 1; 

        while ((i >= 0) && A[i] > key) { 

            A[i + 1] = A[i]; 

            i--; counter++; 

        } 

        A[i + 1] = key; 

    } 

    cout << "Number of iterations equals " << counter << endl; 

} 

 

 

 

void SELECTIONSORT(int A[], int n) 

{        

    int i, j, min, temp; 

    for (j = 0; j < n - 1; j++) 

    { 

        for (min = j, i = j + 1; i < n; i++) 

            if (A[i] < A[min]) min = i; 

        temp = A[j]; 

        A[j] = A[min]; 

        A[min] = temp; 

    } 

} 

void IS(int A[], int n) { 

    for (int i = 1; i < n; i++) 

    { 

        int key = A[i]; 

        int j = i - 1; 

        while (j>=0 &&A[j]>key) 

        { 

            A[j + 1] = A[j]; 

        } 

        A[j + 1] = key; 

    } 

} 

void SELECTIONSORTGEEKS(int arr[], int n) 

{ 

    int  min_idx; 

 

    // One by one move boundary of 

    // unsorted subarray 

    for (int i = 0; i < n - 1; i++) 

    { 

 

        // Find the minimum element in 

        // unsorted array 

        min_idx = i; 

        for (int j = i + 1; j < n; j++) {    // 4 2 3 91 16 1 

            if (arr[j] < arr[min_idx]) { 

                min_idx = j; 

            } 

        } 

        int temp = arr[min_idx]; 

        arr[min_idx] = arr[i]; 

        arr[i] = temp; 

        

    } 

} 

void BUBBLESORT(int arr[], int n) {         // 1 3 5 512 temp 

    for (int i = 0; i < n - 1; i++) {      //  1 2 3 5 512 

        // Last i elements are already     // 5 4 3 2 1  

        // in place 

        for (int j = 0; j < n - i - 1; j++) { 

            if (arr[j] > arr[j + 1]) { 

                int temp = arr[j + 1]; 

                arr[j + 1] = arr[j]; 

                arr[j] = temp; 

            } 

        } 

    } 

} 

 

void SHAKERSORT(int A[], int n) 

{ 

    int L = 1, R = n - 1, k = n - 1; 

    int temp; 

    do 

    {                                     //             L  R       

        for (int j = R; j >= L; j--) {     // 1 2 3 5 11 7 17 21 34  

            if (A[j - 1] > A[j])          //             k                      

            { 

                temp = A[j - 1]; 

                A[j - 1] = A[j]; 

                A[j] = temp; 

                k = j; 

            } 

        } 

        L = k + 1; 

        for (int j = L; j <= R; j++) { 

            if (A[j - 1] > A[j]) 

            { 

                temp = A[j - 1]; 

                A[j - 1] = A[j]; 

                A[j] = temp; 

                k = j; 

            } 

        } 

        R = k - 1; 

    } while (L <= R); 

} 

 

void SHELLSORT(int array[], int n) { 

    // Rearrange elements at each n/2, n/4, n/8, ... intervals               i=1 temp =7 

    for (int interval = n / 2; interval > 0; interval /= 2) { 

        for (int i = interval; i < n; i++)//                                0 1 4 6 7 9 13 45 

        { 

            int temp = array[i]; 

            int j; 

            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) { 

                array[j] = array[j - interval]; 

            } 

            array[j] = temp; 

        } 

    } 

} 

void COUNTINGSORT(int A[], int B[], int n) 

{ 

    int i, j; const int k = 7; int C[k]; 

    for (i = 0; i < k; i++) C[i] = 0; 

    for (j = 0; j < n; j++) C[A[j]]++; 

    // C[i] now contains the number of elements equal to i 

    for (i = 1; i < k; i++) C[i] = C[i] + C[i - 1]; 

    for (i = 0; i < k; i++) C[i] = C[i] - 1; 

    // C[i] now contains the number of elements less than or equal to i 

    for (j = n - 1; j >= 0; j--) { 

        B[C[A[j]]] = A[j]; 

        C[A[j]] = C[A[j]] - 1; 

    } 

} 

void HEAPSORT(int A[], int n) 

{ 

    int i; 

    BUILDMAXHEAP(A, n); 

    int heapsize = n - 1; 

    for (i = n - 1; i >= 2; i--) 

    { 

        int temp = A[1]; 

        A[1] = A[i]; 

        A[i] = temp; 

        heapsize = heapsize - 1; 

        MAXHEAPIFY(A, 1, heapsize); 

    } 

} 

void BUILDMAXHEAP(int A[], int n) 

{ 

    int i, heapsize = n - 1; 

    for (i = (n - 1) / 2; i >= 1; i--) MAXHEAPIFY(A, i, heapsize); 

} 

void MAXHEAPIFY(int A[], int i, int heapsize) 

{ 

    int l, r, largest; 

    l = 2 * i; 

    r = 2 * i + 1; 

    if ((l <= heapsize) && (A[l] > A[i])) largest = l; 

    else largest = i; 

    if ((r <= heapsize) && (A[r] > A[largest])) largest = r; 

    if (largest != i) 

    { 

        int temp = A[i]; 

        A[i] = A[largest]; 

        A[largest] = temp; 

        MAXHEAPIFY(A, largest, heapsize); 

    } 

} 

 

//-----------------------------------------------------------------------------------------------SEARCH----------------------------------------------------------------------------------------- 

//********************************************************************************************************************************************************************************************** 

int binarySearchRec(int arr[], int l, int r, int x) 

{ 

    if (r >= l) { 

        int mid = (l + r) / 2; 

 

        // If the element is present at the middle 

        // itself 

        if (arr[mid] == x) 

            return mid; 

 

        // If element is smaller than mid, then 

        // it can only be present in left subarray 

        if (arr[mid] > x) 

            return binarySearchRec(arr, l, mid - 1, x); 

 

        // Else the element can only be present 

        // in right subarray 

        return binarySearchRec(arr, mid + 1, r, x); 

    } 

 

    // We reach here when element is not 

    // present in array 

    return -1; 

} 

int binarySearchIter(int arr[], int l, int r, int x) 

{ 

    while (l <= r) { 

        int mid = (l+r) / 2; 

 

        // Check if x is present at mid 

        if (arr[mid] == x) 

            return mid; 

 

        // If x greater, ignore left half 

        if (arr[mid] < x) 

            l = mid + 1; 

 

        // If x is smaller, ignore right half 

        else 

            r = mid - 1; 

    } 

 

    // if we reach here, then element was 

    // not present 

    return -1; 

} 

int LinSearch(int arr[], int n, int x) 

{ 

    int i; 

    for (i = 0; i < n; i++) { 

        if (arr[i] == x) { 

            return i; 

        } 

    } 

    return -1; 

} 

 

int exponentialSearch(int arr[], int n, int x) 

{ 

    // If x is present at first location itself 

    if (arr[0] == x) 

        return 0; 

 

    // Find range for binary search by 

    // repeated doubling 

    int i = 1; 

    while (i < n && arr[i] <= x) 

        i = i * 2; 

 

    //  Call binary search for the found range. 

    return binarySearchIter(arr, i / 2, 

        min(i, n - 1), x); 

} 

 

 

//---------------------------------------------------------------------------------------------DATASTRUCTURES----------------------------------------------------------------------------------- 

//********************************************************************************************************************************************************************************************* 

 

int queue[100], head = -1, tail = -1; 

void Enqueue() { 

    int val; 

    if (tail == n - 1) 

        cout << "Queue Overflow" << endl; 

    else { 

        if (head == -1) { 

            head = 0; 

        } 

        cout << "Insert the element in queue : " << endl; 

        cin >> val; 

        tail++; 

        queue[tail] = val; 

    } 

} 

void Dequeue() { 

    if (head == -1 || head > tail) { 

        cout << "Queue Underflow "; 

        return; 

    } 

    else { 

        cout << "Element deleted from queue is : " << queue[head] << endl; 

        head++; 

    } 

} 

void Display() { 

    if (head == -1) 

        cout << "Queue is empty" << endl; 

    else { 

        cout << "Queue elements are : "; 

        for (int i = head; i <= tail; i++) 

            cout << queue[i] << " "; 

        cout << endl; 

    } 

} 

 

void push(char val, char array[100]) { 

    if (top >= n - 1) 

        cout << "Stack Overflow" << endl; 

    else { 

        top++; 

        array[top] = val; 

    } 

} 

void pop(char array[100]) { 

    if (top <= -1) 

        cout << "Stack Underflow" << endl; 

    else { 

        cout << "The popped element is " << array[top] << endl; 

        top--; 

    } 

} 

void display(char array[100]) { 

    if (top >= 0) { 

        cout << "Stack elements are:"; 

        for (int i = top; i >= 0; i--) 

            cout << array[i] << " "; 

        cout << endl; 

    } 

    else 

        cout << "Stack is empty"; 

} 

 

/* 

Singly Linked List 

 

#include <iostream> 

using namespace std; 

struct Node 

{int data; 

  Node* next; 

}; 

void initNode(struct Node *head,int n) 

{head->data = n; 

  head->next =NULL; 

} 

void addNode(struct Node *head, int n) 

{ Node *newNode = new Node; 

   newNode->data = n; 

   newNode->next = NULL; 

    Node *cur = head; 

    while (cur) 

         { if(cur->next == NULL) 

                   { cur->next = newNode; 

                return; 

        } 

        cur = cur->next; 

    } 

} 

void insertFront(struct Node **head, int n) 

{ Node *newNode = new Node; 

   newNode->data = n; 

   newNode->next = *head; 

  *head = newNode; 

 } 

struct Node *searchNode(struct Node *head, int n) 

   { Node *cur = head; 

      while (cur) 

        { if(cur->data == n) {cout<<"Node " << n << " is in list"<<endl; return cur;} 

           cur = cur->next; 

         } 

       cout << "No Node " << n << " in list"<<endl; 

    } 

bool deleteNode(struct Node **head, Node *ptrDel) 

       { Node *cur = *head; 

    if (ptrDel == *head) 

                    { *head = cur->next; 

           delete ptrDel; 

            return true; 

                } 

    while (cur) 

           { if (cur->next == ptrDel) 

                   { cur->next = ptrDel->next; 

                delete ptrDel; 

          return true; 

        } 

        cur = cur->next; 

      } 

    return false; 

} 

 

void display (struct Node *head) 

 { Node *list = head; 

    while (list) 

        { cout << list->data << " "; 

     list = list->next; 

    } 

     cout << endl; 

  } 

int main() 

{ 

    struct Node *head = new Node; 

    initNode(head,10); 

    addNode(head,20); 

    addNode(head,30); 

    addNode(head,35); 

    addNode(head,40); 

          display(head); 

    insertFront(&head,5); 

          display(head); 

          searchNode(head,30); 

    int numDel = 5; 

    Node *ptrDelete = searchNode(head,numDel); 

    if (deleteNode (&head,ptrDelete)) 

        cout << "Node "<< numDel << " deleted"<<endl; 

    display(head); 

    return 0; 

} 

Single Linked List 

 

#include <iostream> 

using namespace std; 

struct Node 

{int data; 

  Node* next; 

}; 

void initNode(struct Node *head,int n) 

{head->data = n; 

  head->next =NULL; 

} 

void addNode(struct Node *head, int n) 

{ Node *newNode = new Node; 

   newNode->data = n; 

   newNode->next = NULL; 

    Node *cur = head; 

    while (cur) 

         { if(cur->next == NULL) 

                   { cur->next = newNode; 

                return; 

        } 

        cur = cur->next; 

    } 

} 

void insertFront(struct Node **head, int n) 

{ Node *newNode = new Node; 

   newNode->data = n; 

   newNode->next = *head; 

  *head = newNode; 

 } 

struct Node *searchNode(struct Node *head, int n) 

   { Node *cur = head; 

      while (cur) 

        { if(cur->data == n) {cout<<"Node " << n << " is in list"<<endl; return cur;} 

           cur = cur->next; 

         } 

       cout << "No Node " << n << " in list"<<endl; 

    } 

bool deleteNode(struct Node **head, Node *ptrDel) 

       { Node *cur = *head; 

    if (ptrDel == *head) 

                    { *head = cur->next; 

           delete ptrDel; 

            return true; 

                } 

    while (cur) 

           { if (cur->next == ptrDel) 

                   { cur->next = ptrDel->next; 

                delete ptrDel; 

          return true; 

        } 

        cur = cur->next; 

      } 

    return false; 

} 

 

void display (struct Node *head) 

 { Node *list = head; 

    while (list) 

        { cout << list->data << " "; 

     list = list->next; 

    } 

     cout << endl; 

  } 

int main() 

{ 

    struct Node *head = new Node; 

    initNode(head,10); 

    addNode(head,20); 

    addNode(head,30); 

    addNode(head,35); 

    addNode(head,40); 

          display(head); 

    insertFront(&head,5); 

          display(head); 

          searchNode(head,30); 

    int numDel = 5; 

    Node *ptrDelete = searchNode(head,numDel); 

    if (deleteNode (&head,ptrDelete)) 

        cout << "Node "<< numDel << " deleted"<<endl; 

    display(head); 

    return 0; 

} 

 

 

 

*/ 

 

 

 