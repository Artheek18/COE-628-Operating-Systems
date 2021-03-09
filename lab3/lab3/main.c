/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Artheeckkumarran Shanmugalingam
 *
 * Created on February 6, 2021, 2:28 AM
 */


/*
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
/*
 * 
he */
int main(int argc, char** argv) 
{
    while(1)
    {
        char * cmnd;
        char * demo;
        pid_t pid;

    
        fprintf(stdout,"Your Command> ");
        
        int ch; 
        //initialize space and Characters
        demo = (char*)calloc(0, sizeof(char)); 
        cmnd  = (char*)calloc(0, sizeof(char)); 

        int indexSize = 0;
        int i = 0,  numArgs = 1, j=0;
        bool andFlag= false;
    
        do 
        {
            indexSize++;
            demo = realloc(cmnd, indexSize*sizeof(char));
            cmnd = demo;
            ch = getchar();
                if (ch == '&') 
                 {
                    andFlag = true;
                    fprintf(stdout,"Parent\n");
                    continue;
                }
            
            cmnd[indexSize-1] = ch;  
        }
        while (ch  != '\n');
        
        

        //Termination
        for (i = 0; i < indexSize; i++)
        {
            if (cmnd[i] == ' ' || cmnd[i] == '\n')
            {
                cmnd[i] = '\0';
                numArgs++;
              
            }

        }

        //store in an array of pointers 
        char * execCmnd[numArgs];
        execCmnd[0] = &cmnd[0];   
        for (i =0; i < indexSize-1; i++)
        {
            if (cmnd[i] == '\0' && i < indexSize)
            {
                j++;
                execCmnd[j] = &cmnd[i+1];
            }
        }
        execCmnd[numArgs-1] = '\0';
        
        if (strcmp(execCmnd[0], "exit") == 0) 
        {
            break;
        }

        //Child processes
        pid_t cpid = fork();
        if (cpid < 0){
             fprintf(stderr,"\n");
            
        }
        else if (cpid == 0)
        {
             fprintf(stdout, "CHILD\n ");
             execvp(execCmnd[0],execCmnd);
             
      
        }
        //Parent
        if (pid > 0)
        {
            if (andFlag == false) 
            {   
                fprintf(stdout, "Waited\n");
                
                pid = wait(NULL);
   
                
                
            }
            else 
                printf("\n");
    
                
               
            
        }
        
    }
    

    return (EXIT_SUCCESS);
    
}
    