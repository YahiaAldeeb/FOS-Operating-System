/*
 * channel.c
 *
 *  Created on: Sep 22, 2024
 *      Author: HP
 */
#include "channel.h"
#include <kern/proc/user_environment.h>
#include <kern/cpu/sched.h>
#include <inc/string.h>
#include <inc/disk.h>

//===============================
// 1) INITIALIZE THE CHANNEL:
//===============================
// initialize its lock & queue
void init_channel(struct Channel *chan, char *name)
{
	strcpy(chan->name, name);
	init_queue(&(chan->queue));
}

//===============================
// 2) SLEEP ON A GIVEN CHANNEL:
//===============================
// Atomically release lock and sleep on chan.
// Reacquires lock when awakened.
// Ref: xv6-x86 OS code
void sleep(struct Channel *chan, struct spinlock *lk)
{
	//TODO: [PROJECT'24.MS1 - #10] [4] LOCKS - sleep
	//COMMENT THE FOLLOWING LINE BEFORE START CODING
	//panic("sleep is not implemented yet");
	acquire_spinlock(&ProcessQueues.qlock);
	release_spinlock(lk); //release spin lock
	enqueue(&(chan->queue) , get_cpu_proc());
	get_cpu_proc()->env_status =ENV_BLOCKED;
	//chan->queue.lh_last->env_status = 3;
	      sched();
	      acquire_spinlock(lk);
	      release_spinlock(&ProcessQueues.qlock);

	//Your Code is Here...

}

//==================================================
// 3) WAKEUP ONE BLOCKED PROCESS ON A GIVEN CHANNEL:
//==================================================
// Wake up ONE process sleeping on chan.
// The qlock must be held.
// Ref: xv6-x86 OS code
// chan MUST be of type "struct Env_Queue" to hold the blocked processes
void wakeup_one(struct Channel *chan)
{
	//TODO: [PROJECT'24.MS1 - #11] [4] LOCKS - wakeup_one
	//COMMENT THE FOLLOWING LINE BEFORE START CODING
	//panic("wakeup_one is not implemented yet");
	//Your Code is Here...

	struct Env *popped_element;
	acquire_spinlock(&ProcessQueues.qlock);

	if(chan->queue.size==0)
		{
			cprintf("size=0!!\n");
		}
		else{
				popped_element = dequeue(&(chan->queue));

				sched_insert_ready(popped_element);
		}
	 release_spinlock(&ProcessQueues.qlock);
}
//====================================================
// 4) WAKEUP ALL BLOCKED PROCESSES ON A GIVEN CHANNEL:
//====================================================
// Wake up all processes sleeping on chan.
// The queues lock must be held.
// Ref: xv6-x86 OS code
// chan MUST be of type "struct Env_Queue" to hold the blocked processes

void wakeup_all(struct Channel *chan)
{
	//TODO: [PROJECT'24.MS1 - #12] [4] LOCKS - wakeup_all
	//COMMENT THE FOLLOWING LINE BEFORE START CODING
	//panic("wakeup_all is not implemented yet");
	//Your Code is Here...

	int queue_size=chan->queue.size;
	if(chan->queue.size!=0)
	{
		for(int i=0;i<queue_size;i++)
			{
			//acquire_spinlock(&ProcessQueues.qlock);
				wakeup_one(chan);
		    //release_spinlock(&ProcessQueues.qlock);
			}
	}

}

