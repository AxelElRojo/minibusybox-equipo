#include "libuname.h"

void unameValidation(int argc, char * argv[])
{

struct utsname buf ;
uname(&buf);

if(argc > 1)
   {
      if(strcmp(argv[1], "--help") == 0)
      {
        printf("printing uname's help\n");
      }
	  else if(strcmp(argv[1], "--version") == 0)
      {
        printf("printing uname's version\n");
      }	  
      else
      {
		  if(strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--kernel-name") == 0)
		  {
			  printf("the kernel name is: %s\n", buf.sysname);
		  }
		  else if(strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "--kernel-release") == 0)
		  {
			  printf("the kernel's release release is: %s\n", buf.release);
		  }
		  else if(strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--kernel-version") == 0)
		  {
			  printf("the kernel's version is: %s\n", buf.version);
		  }
		  else if(strcmp(argv[1], "-p") == 0 || strcmp(argv[1], "--processor") == 0)
		  {
			  printf("the processor type is: %s\n", buf.machine);
		  }
		  else
		  {
			  printf("uname with argument %s is not currently implemented\n", argv[1]);
		  }		  
      }
   }
   else
   {
    printf("uname without arguments calling getting default\n");
    printf("the kernel name is: %s\n", buf.sysname);	
   }
}
