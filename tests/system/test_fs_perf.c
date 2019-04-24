/* SPDX-License-Identifier: BSD-2-Clause */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/mman.h>
#include <sys/time.h>

#include "devshell.h"
#include "sysenter.h"

static void create_file(const char *path, int n)
{
   char abs_path[256];
   int rc;

   sprintf(abs_path, "%s/test_%d", path, n);

   rc = creat(abs_path, 0644);
   DEVSHELL_CMD_ASSERT(rc > 0);
   close(rc);
}

static void remove_file(const char *path, int n)
{
   char abs_path[256];
   int rc;

   sprintf(abs_path, "%s/test_%d", path, n);

   rc = unlink(abs_path);
   DEVSHELL_CMD_ASSERT(rc == 0);
}

int cmd_fs_perf1(int argc, char **argv)
{
   const int n = 1000;
   u64 start, end, elapsed;
   const char *dest_dir = argc > 0 ? argv[0] : "/tmp";
   printf("Using '%s' as test dir\n", dest_dir);

   start = RDTSC();

   for (int i = 0; i < n; i++)
      create_file(dest_dir, i);

   end = RDTSC();
   elapsed = (end - start) / n;
   start = RDTSC();

   printf("Avg. creat() cost:  %4llu K cycles\n", elapsed / 1000);

   for (int i = 0; i < n; i++)
     remove_file(dest_dir, i);

   end = RDTSC();
   elapsed = (end - start) / n;
   printf("Avg. unlink() cost: %4llu K cycles\n", elapsed / 1000);
   return 0;
}

int cmd_fs_perf2(int argc, char **argv)
{
   const int n = 1024;
   char path[256];
   char buf[1024];
   int fd, rc;
   u64 start, end, elapsed;
   const char *dest_dir = argc > 0 ? argv[0] : "/tmp";

   printf("Using '%s' as test dir\n", dest_dir);

   sprintf(path, "%s/test_file", dest_dir);
   fd = open(path, O_WRONLY | O_CREAT, 0644);
   DEVSHELL_CMD_ASSERT(fd > 0);

   memset(buf +   0, 'a', 256);
   memset(buf + 256, 'b', 256);
   memset(buf + 512, 'c', 256);
   memset(buf + 768, 'd', 256);

   start = RDTSC();

   for (int i = 0; i < n; i++) {
      rc = write(fd, buf, 1024);
      DEVSHELL_CMD_ASSERT(rc == 1024);
   }

   end = RDTSC();
   elapsed = (end - start);
   close(fd);

   printf("Tot written: %d KB\n", n);
   printf("Avg. cost per KB: %4llu cycles\n", elapsed / KB);
   return 0;
}