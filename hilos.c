#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
//Estas librerias son para el open()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//Esta libreria es para el write()
#include <unistd.h>

void *thread_routine(void *arg)
{   
    int fd;
    int nr_lineas = *((int*)arg);
    char buf[] = "Nueva línea \n";
    printf("El hilo comienza a ejecutarse...\n");
    for(int i = 0; i < nr_lineas; i++)
    {   
        printf("Línea %d escrita \n", i+1);
        fd = open("tuto_hilos", O_WRONLY | O_APPEND | O_CREAT );
        write(fd, buf,sizeof(buf)-1);
        close(fd);
    }
}

int main(int argc, char *argv[])
{
    pthread_t thread1;
    int value = atoi(argv[1]);
    
    if( 0 != pthread_create( &thread1, NULL, thread_routine , &value)){
        return -1;
    }
    
    printf("Esperando culminación del hilo \n");
    pthread_join(thread1, NULL);
    printf("Hilo culminado \n");
    
    return 0;
}