#include <cs50.h>
#include <stdio.h>
//include all the additional libraries for the additional commands such as atoi, strlen and isdigit
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //set condition on the command line argument to only accept one argument
    //only positive decimal digits allowed
    if (argc == 2 && isdigit(*argv[1]))
    {
        //convert caesar key value into an integer
        int k = atoi(argv[1]), i;
        //get plaintext input from user
        string p = get_string("plaintext:  ");
        printf("ciphertext: ");
        int s = strlen(p);

        for (i = 0; i < s; i++)
        {
            //program the algorithm separately for lowercase and uppercase letters to simplify calculation
            //define ciphertext as char
            char c1 = 65 + ((p[i] - 65) + k) % 26;
            char c2 = 97 + ((p[i] - 97) + k) % 26;

            //ascii values of lowercase letters set as parameters for case 1
            if (p[i] >= 65 && p[i] <= 90)
            {
                printf("%c", c1);
            }

            //ascii values of uppercase letters set as parameters for case 2
            else if (p[i] >= 97 && p[i] <= 122)
            {
                printf("%c", c2);
            }

            //otherwise make alternate process to avoid error
            else
            {
                printf("%c", p[i]);
            }
        }

        //print new line and exit by returning 0 from main
        printf("\n");
        return 0;
    }

    //if a non decimal digit is inputted prints error message and a value of 1 is returned from main
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}