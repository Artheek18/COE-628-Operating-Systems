/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: arthe
 *
 * Created on February 21, 2021, 9:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define fname "stdout.txt"
/*
 * 
 */
int main(int argc, char** argv) {
    char *cmd = malloc(sizeof(char)*100);
    
    while(1){
        //Variables
        int ch;
        int index = 0;int i= 0, j = 0;
        
        
        char *line1 =  malloc(sizeof(char*)*100);
        char *line2 = malloc(sizeof(char*)*100);
        
        
       
        if(access(fname,F_OK) != 1){
            printf("The file exists\n");
   
        }
        else 
            printf("File does not Exist\n");
        
        fprintf(stdout,"Your Command> ");
        
       
      
        do 
        {
            ch = getchar();
            cmd[index] = ch;  
            index++;
        }
        while (ch  != '\n');
            cmd[index] = (char)'\0';
        
        char **split(char *line , char *whitespace){
           int size = 0;
           char **tokens = malloc(sizeof(char)*100);
           char *token;
           token= strtok(line,whitespace);
           while(token!= NULL){
                tokens[index]=token;      
                token = strtok(NULL,whitespace);
                size;
         }   
         tokens[size]=NULL;
         return tokens;
         
        }  
         
        
            while(cmd[i]!='|'){
                line1[i]= cmd[i];
                i++;
                }
            line1[i]=(char)'\0';
            i++;

            while(cmd[i]!='\0'){
                line2[j]=cmd[i];
                i++;
                j++;
            }
            line2[j]='\0';


            char **arg1;
            char **arg2;
            arg1 = split(line1, " ");
            arg2 = split(line2, " ");
            int Pipe[2];
            pipe(Pipe);
            pid_t cpid = fork();

            if (cpid == 0)
            {

                 dup(Pipe[1]);
                 printf("%d \n", Pipe[1]); 
                 close(Pipe[0]);
                 close(Pipe[1]);
                 execvp(arg1[0], arg1);
                 


            }

            else if (cpid < 0)
                 fprintf(stderr, "\n");
                 dup(Pipe[0]);
                 close(Pipe[1]);
                 close(Pipe[0]);
                 execvp(arg2[0], arg2);

           
        
        }
        
       
    
   
    
   
    
    return (EXIT_SUCCESS);
}

