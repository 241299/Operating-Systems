/**
 * Defining Node
 */

typedef struct node
{
    char *value; // generic value (not really sure)
    struct node *next;
} Node;

/**
 * Defining List Data Structure
 */

typedef struct list
{
    int size;
    Node *head;
    Node *tail;
} List;

/**
 * Inserts a value to the end of the list and returns a Node
 */

Node *insertNode(List *l, char *value)
{
    Node *node = malloc(sizeof(Node));
    (*node).value = value;

    if ((*l).size == 0) (*l).head = node; // First element
    else (*(*l).tail).next = node; // Last element

    (*l).tail = node;

    (*l).size++;

    // debug info
    printf("Inserted %d. Size: %d\n", *value, (*l).size);

    return node;
}

/**
 * Removes the node containing the value from the list
 * Returns value if operation succeeded or NUL char otherwise
 */

char *deleteNode(List *l, char *value)
{
    if ((*l).size == 0) return '\0'; // Crutch

    // Check the head
    Node *node = (*l).head;
    if (*value == *(*node).value)
    {
        // Deletion
        (*l).head = (*node).next;
        (*l).size--;

        // Save the value for return and collect garbage
        char *r = (*node).value;
        free(node);

        return r;
    }

    // Iterate by checking the next element
    for (int i = 0; i < (*l).size - 1; i++)
        if (*value == *(*(*node).next).value)
        {
            Node *del = (*node).next;

            // Deletion
            (*node).next = (*del).next;
            (*l).size--;

            // Checking whether to update the tail of the list
            if ((*l).tail == del) (*l).tail = node;

            // Save the value for return and collect garbage
            char *r = (*del).value;
            free(del);

            return r;
        }
        else node = (*node).next;

    return '\0';
}

/**
 * Main
 */

int main()
{
    // Creation
    List *l = malloc(sizeof(List));

    // Tests of insertion

    char c0 = 5;
    insertNode(l, &c0);

    char c1 = 8;
    insertNode(l, &c1);

    char c2 = -100;
    insertNode(l, &c2);

    /*
     * Tests of deletion
     */

    printf("Tail: %d. Size: %d\n", *(*(*l).tail).value, (*l).size);


    // Unknown element deletion (nothing happens)
    char du = 100500;
    deleteNode(l, &du);

    printf("Head: %d. Size: %d\n", *(*(*l).head).value, (*l).size);


    // Middle deletion
    char dm = -100;
    deleteNode(l, &dm);

    printf("Head: %d. Size: %d\n", *(*(*l).head).value, (*l).size);


    // Tail deletion
    char dt = -100;
    deleteNode(l, &dt);

    printf("Tail: %d. Size: %d\n", *(*(*l).tail).value, (*l).size);


    // Head deletion
    char dh = 5;
    deleteNode(l, &dh);

    printf("Head: %d. Size: %d\n", *(*(*l).head).value, (*l).size);

    return 0;
}