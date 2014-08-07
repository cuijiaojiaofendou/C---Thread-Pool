// =====================================================================================
// 
//       Filename:  Mutex.h
//
//    Description:  锁的封装
//
//        Version:  1.0
//        Created:  2014年08月07日 14时45分05秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Striver (CuiJiaojiao), cuijiaojiaofendou@gmail.com
//        Company:  Class 1204 of Software Engineering
// 
// =====================================================================================

#ifndef MUTEX_H_
#define MUTEX_H_

#include <iostream>
#include <unistd.h>
#include <pthread.h>

class Mutex
{
public:
	Mutex();
	~Mutex();

	int lock();
	int unlock();

	pthread_mutex_t *getMutex();

private:
	pthread_mutex_t mutex;
};


#endif
