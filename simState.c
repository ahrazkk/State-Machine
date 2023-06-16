#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct node {
    char data;
    struct node * zero;
    struct node * one;
};

struct node * createFSM() {
    struct node * a = malloc(sizeof(struct node));
    struct node * b = malloc(sizeof(struct node));
    struct node * c = malloc(sizeof(struct node));
    struct node * d = malloc(sizeof(struct node));
    struct node * e = malloc(sizeof(struct node));
    struct node * f = malloc(sizeof(struct node));
    struct node * g = malloc(sizeof(struct node));
    struct node * h = malloc(sizeof(struct node));

    a -> data = 'A';
    b -> data = 'B';
    c -> data = 'C';
    d -> data = 'D';
    e -> data = 'E';
    f -> data = 'F';
    g -> data = 'G';
    h -> data = 'H';

    a -> zero = c; a -> one = g;

    b -> zero = h; b -> one = c;
    c -> zero = g; c -> one = d;
    d -> zero = e; d -> one = h;
    e -> zero = e; e -> one = a;
    f -> zero = b; f -> one = e;
    g -> zero = f; g -> one = b;
    h -> zero = d; h -> one = f;

    return b;
}

int main(int argc, char * argv[]) {
    char command[10];
    char state;
    int value;

    struct node * current_state = createFSM();
    struct node * fsm = current_state;

    printf("Starting state is %c.\n", current_state -> data);

    char input[100];
    while (1) {
        printf("Enter a command (or press 'q' to exit): ");
        fgets(input, 100, stdin);

        if (strcmp(input, "q\n") == 0) {
            printf("Program Status: Exit\n");
            break;
        } else if (strcmp(input, "c\n") == 0) {
            scanf("%d %c", & value, & state);
            if ((value == 0 || value == 1) && state >= 'A' && state <= 'H') {
                // update state machine configuration
                struct node * temp = fsm -> one -> one -> zero -> one;
                if (value == 0) {
                    switch (state) {
                        case 'A':
                            current_state -> zero = fsm -> one -> one -> zero -> one;
                            break;
                        case 'B':
                            current_state -> zero = fsm;
                            break;
                        case 'C':
                            current_state -> zero = fsm -> one;
                            break;
                        case 'D':
                            current_state -> zero = fsm -> one -> one;
                            break;
                        case 'E':
                            current_state -> zero = fsm -> one -> one -> zero;
                            break;
                        case 'F':
                            current_state -> zero = fsm -> one -> zero -> zero;
                            break;
                        case 'G':
                            current_state -> zero = fsm -> one -> zero;
                            break;
                        case 'H':
                            current_state -> zero = fsm -> zero;
                            break;
                        default:
                            printf("Invalid state.\n");
                            break;
                    }
                    printf("State is %c\n", current_state -> zero -> data);
                }



                if (value == 1) {
                    switch (state) {
                        case 'A':
                            current_state -> one = fsm -> one -> one -> zero -> one;
                            break;
                        case 'B':
                            current_state -> one = fsm;
                            break;
                        case 'C':
                            current_state -> one = fsm -> one;
                            break;
                        case 'D':
                            current_state -> one = fsm -> one -> one;
                            break;
                        case 'E':
                            current_state -> one = fsm -> one -> one -> zero;
                            break;
                        case 'F':
                            current_state -> one = fsm -> one -> zero -> zero;
                            break;
                        case 'G':
                            current_state -> one = fsm -> one -> zero;
                            break;
                        case 'H':
                            current_state -> one = fsm -> one;
                            break;
                        default:
                            printf("Invalid state.\n");
                            break;
                    }
                    printf("State is %c\n", current_state -> one -> data);
                }
            }
        }
        else if (strcmp(input, "0\n") == 0) {
            current_state = current_state -> zero;
            printf("Current state is %c\n", current_state -> data);
        } else if (strcmp(input, "1\n") == 0) {
            current_state = current_state -> one;
            printf("Current state is %c\n", current_state -> data);
        }
        //Garbage funtion
        //ill be honest i dont understand this funtion
        else if (strcmp(input, "g\n") == 0) {

        }   //Deleted funtion
        //ill be honest i dont understand this funtion either
        else if (strcmp(input, "d\n") == 0) {
            scanf("%d", & value);
            if (value == 0) {
                current_state -> zero = 0;
                current_state = current_state -> one;
                printf("deleted\n");

            }
        }




        else if (strcmp(input, "h\n") == 0) {
            printf("\nCommands:\nq - Quit the program\np - Print the FSM\nc - Command funtion\ng - garbage funtion\nd - delete funtion\n");



        }








        if (strcmp(input, "p\n") == 0) {
            printf("FSM:\n");
//struct node * temp = fsm;
struct node * nodes[] = { fsm -> one -> one -> zero -> one, fsm, fsm -> one, fsm -> one -> one, fsm -> one -> one -> zero, fsm -> one -> zero -> zero, fsm -> one -> zero, fsm -> zero };
            for (int i = 0; i < 8; i++) {
    struct node * temp = nodes[i];


                printf("%c ", temp -> data);
                temp = temp -> zero;
                printf("%c ", temp -> data);
                temp = nodes[i];
                temp = temp -> one;
                printf("%c\n", temp -> data);

            }
        }





        if (strcmp(input, "p\n") != 0 && strcmp(input, "0\n") != 0 && strcmp(input, "1\n") != 0 && strcmp(input, "h\n") != 0 && strcmp(input, "c\n") != 0 && strcmp(input, "g\n") != 0 && strcmp(input, "d\n") != 0) {
            printf("Error: Invalid input. Please enter '0', '1', 'c', 'p', 'g', 'd' or 'h' for help.\n");
            continue;

        }
    }





// this is my personal dictinary for what letter corresponds to what, with fsm being b and everything building from that

    /*
            fsm =b
     fsm->zero = h
      fsm->one = C
       fsm->one->one = D
       fsm->one->zero = G
       fsm->one->one->zero = E
        fsm->one->one->zero->one = A
       fsm->one->zero->zero = F
       
     //this was the list for my fsm

    fsm->one->one->zero->one,fsm->one, fsm->one->zero,
    fsm,fsm->zero, fsm->one,
    fsm->one,fsm->one->zero ,fsm->one->one
    fsm->one->one,fsm->one->one->zero,fsm->zero,
    fsm->one->one->zero,fsm->one->one->zero,fsm->one->one->zero->one,
    fsm->one->zero->zero,fsm,fsm->one->one->zero,
    fsm->one->zero,fsm->one->zero->zero,fsm,
    fsm->zero,fsm->one->one,fsm->one->zero->zero
    
    
    A C G
    B H C
    C G D
    D E H
    E E A
    F B E
    G F B
    H D F
    
    */
        

}

