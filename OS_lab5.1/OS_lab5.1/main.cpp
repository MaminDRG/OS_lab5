//
//  main.cpp
//  OS_lab5.1
//
//  Created by MacBook Pro on 01/04/2019.
//  Copyright © 2019 MacBook Pro. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    std::cout << "Program started"<<std::endl;
    pid_t pid;
    int status = 0;
    switch(pid=fork()) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            execvp("./OS_lab5.2", argv+1);
        default:
            std::cout << "Main process started"<<std::endl;
            waitpid(pid, &status, 0);
            std::cout<<"Main parent pid  "<<getppid()<<std::endl;
            std::cout<<"PARENT pid "<<getpid()<<std::endl;
            std::cout<<"Child pid "<<pid<<std::endl;
            
            std::cout<<"Child status from parent is "<<status<<std::endl;
            std::cout << "WEXITSTATUS(status) = " << WEXITSTATUS(status) << " Child returned this code" << std::endl;
            std::cout << "Main process finished"<<std::endl;
    }
    std::cout << "Program finished"<<std::endl;
    return 0;
}


