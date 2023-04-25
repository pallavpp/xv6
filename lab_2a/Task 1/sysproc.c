#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "console.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

/*
  this is the actual function being called from syscall.c
  @returns - 0 if suceeded, 1 if no history in the historyId given, 2 if illgal history id
*/
int sys_history(void) {
  char *buffer;
  int historyId;
  argptr(0, &buffer, 1);
  argint(1, &historyId);
  return history(buffer, historyId);
}


int sys_wait2(void) {
  int res;
  int retime = 0;
  int rutime = 0;
  int stime = 0;
  argint(0, &retime);
  argint(1, &rutime);
  argint(2, &stime);
  res = sys_wait();
  *(int*)retime = myproc()->retime;
  *(int*)rutime = myproc()->rutime;
  *(int*)stime = myproc()->stime;
  return res;
}
