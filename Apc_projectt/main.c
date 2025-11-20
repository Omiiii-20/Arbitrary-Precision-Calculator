// Name : Om Bidikar
// Date : 14nd Nov 2025
//Batch : 25017_172

#include "apc.h"

int main(int argc, char *argv[])
{
	 /* Check for correct number of command line arguments */
    if (argc != 4)
    {
        printf("Usage: ./a.out <num1> <operator> <num2>\n");
        printf("Example: ./a.out 1234 + 5678\n");
        return -1;
    }

	/* Declare the pointers */
      
	Dlist *head1=NULL, *tail1=NULL;
        Dlist *head2=NULL, *tail2=NULL; 
        Dlist *headR=NULL,*tailR=NULL;

    digit_to_list(&head1,&tail1,&head2,&tail2,argv);


	char operator=argv[2][0];


		switch (operator)
		{
			case '+':
                               // digit_to_list(&head1,&tail1,&head2,&tail2,argv);
				/* call the function to perform the addition operation */
                                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
								 printf("\nResult (Addition): ");
            print_list(headR);
				break;
			case '-':	
				/* call the function to perform the subtraction operation */
				subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
           //printf("\nResult (Subtraction): ");
            print_list(headR);
				break;
			case '*':	
				/* call the function to perform the multiplication operation */
				 multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("\nResult (Multiplication): ");
            print_list(headR);
				break;
			case '/':	
				/* call the function to perform the division operation */
				division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("\nResult (Division): ");
            print_list(headR);
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}

		 /* Free all allocated memory */
			free_list(&head1, &tail1);
			free_list(&head2, &tail2);
			free_list(&headR, &tailR);
	return 0;
}
