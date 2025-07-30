#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(void)
{
  int fd;
  unsigned char buf[8];
  int i;

  fd = open ("/dev/random", O_RDONLY);
  if(fd < 0){
    printf(1, "cannot open /dev/random\n");
    exit();
  }

  if(read(fd, buf, sizeof(buf)) != sizeof(buf)){
    printf(1, "read error\n");
    close(fd);
    exit();
  }

  close(fd);

  for(i = 0; i < sizeof(buf); i++){
    printf(1, "%d ", buf[i]);
  }
  printf(1, "\n");

  exit();
}
