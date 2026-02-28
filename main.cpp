#include <iostream>
#include <cstdlib>  // for malloc
using namespace std;

// TODO: Declare 2 initialized global variables (DATA segment)

int global1 = 10;
int global2 = 20;

// TODO: Declare 2 uninitialized global variables (BSS segment)

int global3;
int global4;

// Stack check function: receives address from caller (parent frame)
// and compares with a local variable (child frame)
void checkStack(int* parentAddr) {
    int childVar = 0;
    cout << "--- STACK SEGMENT (Cross-function comparison) ---" << endl;
    // TODO: Print parentAddr value (points to main's local var - parent frame)
    cout << "Value of parentAddr: " << parentAddr << endl;
    // TODO: Print &parentAddr (parameter's own address - child frame)
    cout << "Address of parentAddr: " << &parentAddr << endl;
    // TODO: Print &childVar (local var address - child frame)
    cout << "Address of childVar: " << &childVar << endl;
    // TODO: Print "Stack grows: DOWN" or "UP" based on comparison
    //       Compare: parentAddr > &childVar ? "DOWN" : "UP"
    //       (parent frame address vs child frame address)

    if (parentAddr > &childVar) {
        cout << "DOWN" << endl;
    } else {
        cout << "UP" << endl;
    }

    cout << endl;
}

int main() {

    // TODO: Declare a local variable (STACK - will be passed to checkStack)

    int local1;

    // TODO: Allocate 2 heap variables using malloc (use larger sizes, e.g. 1024)
    //       Note: new may not allocate sequentially; malloc with larger sizes
    //       is more reliable for demonstrating heap growth direction

    
    cout << "=== MEMORY SEGMENT BOUNDARIES ===" << endl;
    cout << endl;
    
    void* heap1 = malloc(1024);
    void* heap2 = malloc(1024);

    // TODO: Print TEXT segment - 2 function addresses
    //       e.g., (void*)&main and (void*)&checkStack
    cout << "--- TEXT SEGMENT (Code) ---" << endl;
    cout << "Address of main: " << (void*)&main << endl;
    cout << "Address of check fn: " << (void*)&checkStack << endl;
    cout << endl;
    // ...

    // TODO: Print DATA segment - 2 initialized global addresses + values
    cout << "--- DATA SEGMENT (Initialized Globals) ---" << endl;
    cout << "Address of global1: " << &global1 << endl;
    cout << "Value of global1: " << global1 << endl;

    cout << "Address of global2: " << &global2 << endl;
    cout << "Value of global2: " << global2 << endl;
    // ...
    cout << endl;

    // TODO: Print BSS segment - 2 uninitialized global addresses + values
    cout << "--- BSS SEGMENT (Uninitialized Globals) ---" << endl;

    cout << "Address of global3: " << &global3 << endl;
    cout << "Value of global3: " << global3 << endl;

    cout << "Address of global4: " << &global4 << endl;
    cout << "Value of global4: " << global4 << endl;

    // ...
    cout << endl;

    // STACK: call checkStack with address of your local variable
    // TODO: checkStack(&yourLocalVar);

    checkStack(&local1);

    // TODO: Print HEAP segment - 2 heap addresses + comparison
    //       Print "Heap grows: UP" or "DOWN"
    cout << "--- HEAP SEGMENT (Dynamic Allocation) ---" << endl;

    cout << "Heap1: " << heap1 << endl;
    cout << "Heap2: " << heap2 << endl;

    if (heap2> heap1) {
        cout << "Heap: grows up" << endl;
    } else {
        cout << "Heap: grows down" << endl;
    }

    // ...
    cout << endl;

    // TODO: Print relative position summary
    cout << "=== RELATIVE POSITION SUMMARY ===" << endl;

    cout << "Address of main: " << (void*)&main << endl;
    cout << "Address of global1: " << &global1 << endl;
    cout << "Address of global3: " << &global3 << endl;
    cout << "Dyn alloc 1: " << heap1 << endl;
    cout << "Address of check fn: " << (void*)&checkStack << endl;
    

    // ...

    // TODO: Free all heap allocations

    return 0;
}

/*
 * EXPERIMENTAL RESULTS:
 * TODO: After running your program, explain what you observed:
 * - Which segment has the lowest addresses?
 * - Which has the highest?
 * - Does stack grow down? How did you verify this?
 * - Does heap grow up? How did you verify this?
 * - What is the gap between HEAP and STACK?
 */
