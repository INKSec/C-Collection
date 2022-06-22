#include <stdio.h>
#include <stdlib.h>

typedef struct node
    {
		int data;
		struct node* next;
	}node;

// Head pointer zeigt immer auf das erste Element der Liste
node* head;


// Create Element 
node* create(int data, node* next);
node* prepend(node* head, int data);

// Callback um Elemente zu manipulieren
typedef void (*callback)(node* data);
// Durchläuft die Liste
void traverse(node* head, callback f);

int count(node *head);
// Anzahl der Elemente der Liste

// Exemplar nach einem Element einfuegen
node* insert_after(node *head, int data, node* prev);
// exemplar vor Element einfuegen


int main(void){
	
	

    int command = 0;
    int data;
 
    node* head = NULL;
    node* tmp = NULL;
    //callback disp = display;
 
    //menu();
    while(1)
    {
        printf("\nEnter a command(0-10,-1 to quit):");
        scanf("%d",&command);
 
        if(command == -1)
            break;
        switch(command)
        {
        case 0:
            //menu();
            break;
        case 1:
            printf("Please enter a number to prepend:");
            scanf("%d",&data);
          //  head = prepend(head,data);
           // traverse(head,disp);
            break;
        case 2:
            printf("Please enter a number to append:");
            scanf("%d",&data);
           // head = append(head,data);
            traverse(head,disp);
            break;
        case 3:
            printf("Please enter a number to search:");
            scanf("%d",&data);
            tmp = search(head,data);
            if(tmp != NULL)
            {
                printf("Element with value %d found.",data);
            }
            else
            {
                printf("Element with value %d not found.",data);
            }
            break;
        case 4:
            printf("Enter the element value where you want to insert after:");
            scanf("%d",&data);
            tmp = search(head,data);
            if(tmp != NULL)
            {
                printf("Enter the element value to insert after:");
                scanf("%d",&data);
                head = insert_after(head,data,tmp);
                if(head != NULL)
                    traverse(head,disp);
            }
            else
            {
                printf("Element with value %d not found.",data);
            }
            break;
        case 5:
            printf("Enter the element value where you want to insert before:");
            scanf("%d",&data);
            tmp = search(head,data);
            if(tmp != NULL)
            {
                printf("Enter the element value to insert before:");
                scanf("%d",&data);
                head = insert_before(head,data,tmp);
 
                if(head != NULL)
                    traverse(head,disp);
            }
            else
            {
                printf("Element with value %d not found.",data);
            }
            break;
        case 6:
            head = remove_front(head);
            if(head != NULL)
                traverse(head,disp);
            break;
        case 7:
            head = remove_back(head);
            if(head != NULL)
                traverse(head,disp);
            break;
        case 8:
            printf("Enter the element value to remove:");
            scanf("%d",&data);
            tmp = search(head,data);
            if(tmp != NULL)
            {
                remove_any(head,tmp);
                if(head != NULL)
                    traverse(head,disp);
            }
            else
            {
                printf("Element with value %d not found.",data);
            }
            break;
        case 9:
            head = insertion_sort(head);
            if(head != NULL)
                traverse(head,disp);
            break;
        case 10:
            head = reverse(head);
            if(head != NULL)
                traverse(head,disp);
            break;
        }
 
    }
    dispose(head);
    return 0;
}
	
	
	


// Erzeugt ein neues Element der Struktur 
node* create(int data, node* next){
	node* new_node = (node*)malloc(sizeof(node));
	if(new_node == NULL) {
		printf("Fehler");
		exit(0);
		}
	new_node->data = data;
	new_node->next = next;
}

// zuerst wird das Element erzeugt, dann wird das neue Element zum Head und zeigt auf das folgende Element
node* prepend(node* head, int data) {
	node* new_node = create(data, head);
	head = new_node;
	return head;
}

// Durchläuft alle Exemplare der der Structur
void traverse(node* head, callback f)
{
	node* zeiger = head;
	while(zeiger != NULL)
	{
		f(zeiger);
		zeiger = zeiger->next;
	}
}
// Zaehlt die Elemente der Liste
int count(node *head)
{
    node *cursor = head;
    int c = 0;
    while(cursor != NULL)
    {
        c++;
        cursor = cursor->next;
    }
    return c;
}

// Erzeugt ein Element vor einem Element
node* insert_after(node *head, int data, node* prev)
{
    
    node *cursor = head;
    while(cursor != prev)
        cursor = cursor->next;
 
    if(cursor != NULL)
    {
        node* new_node = create(data,cursor->next);
        cursor->next = new_node;
        return head;
    }
    else
    {
        return NULL;
    }
}

// Erzeugt ein Element nach einem Element
node* insert_before(node *head, int data, node* nxt)
{
    if(nxt == NULL || head == NULL)
        return NULL;
 
    if(head == nxt)
    {
        head = prepend(head,data);
        return head;
    }
 
    
    node *cursor = head;
    while(cursor != NULL)
    {
        if(cursor->next == nxt)
            break;
        cursor = cursor->next;
    }
 
    if(cursor != NULL)
    {
        node* new_node = create(data,cursor->next);
        cursor->next = new_node;
        return head;
    }
    else
    {
        return NULL;
    }
}

// Alle Elemente Loeschen
void dispose(node *head)
{
    node *cursor, *tmp;
 
    if(head != NULL)
    {
        cursor = head->next;
        head->next = NULL;
        while(cursor != NULL)
        {
            tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
}