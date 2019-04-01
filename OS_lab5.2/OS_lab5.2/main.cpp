//
//  main.cpp
//  OS_lab5.2
//
//  Created by MacBook Pro on 01/04/2019.
//  Copyright © 2019 MacBook Pro. All rights reserved.
//

#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[])
{
    std::cout << "Child process started"<<std::endl;
    
    for (int count = 0; count < argc; ++count)
    {
        std::cout << count + 1 << " " << argv[count] << '\n';
        sleep(1);
    }
    std::cout << " CHILD: My PID -- " << getpid() << std::endl;
    std::cout << " CHILD: Parent PID -- " << getppid() << std::endl;
    std::cout << "Child process finished" << std::endl;
    exit(int(5));
}

