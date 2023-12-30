#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h> 
 
int main() { 
    pid_t pid = fork(); 
    if (pid < 0) { 
        perror("fork failed"); 
        exit(1); 
    } else if (pid == 0) { 
        // Это код дочернего процесса 
        execl("./prog1", "prog1", NULL); 
        perror("execl failed"); 
        exit(1); 
    } else { 
        // Это код родительского процесса 
        int status; 
        waitpid(pid, &status, 0); 
        if (WIFEXITED(status)) { 
            printf("Дочерний процесс завершился с кодом: %d\n", WEXITSTATUS(status)); 
        } 
         
        pid = fork(); 
        if (pid < 0) { 
            perror("fork failed"); 
            exit(1); 
        } else if (pid == 0) { 
            // Это код дочернего процесса 
            execl("./prog2", "prog2", NULL); 
            perror("execl failed"); 
            exit(1); 
        } else { 
            // Это код родительского процесса 
            waitpid(pid, &status, 0); 
            if (WIFEXITED(status)) { 
                printf("Дочерний процесс завершился с кодом: %d\n", WEXITSTATUS(status)); 
            } 
        } 
    } 
 
    return 0; 
}
