#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv [])
{
  int fd;
  char buffer[1024] = {"/0"};
  
  fd = open(argv[1],O_APPEND);
  lseek(fd,-9,SEEK_END);
  read(fd,buffer,9);
  printf("%s",buffer);
  close(fd);

  fd = open(argv[1],O_RDWR);
 	
  lseek(fd,-9,SEEK_END);
  char buffer2[1024] = {"NTHU student."};
  int len = write(fd,buffer2,13);

  lseek(fd,0,SEEK_SET);
  read(fd,buffer,1024);
  printf("%s",buffer);
	
  close(fd);
  return 0;
}
