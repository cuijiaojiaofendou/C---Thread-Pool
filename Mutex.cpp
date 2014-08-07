// =====================================================================================
// 
//       Filename:  Mutex.cpp
//
//    Description:  锁封装的扩展
//
//        Version:  1.0
//        Created:  2014年08月07日 14时51分45秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Striver (CuiJiaojiao), cuijiaojiaofendou@gmail.com
//        Company:  Class 1204 of Software Engineering
// 
// =====================================================================================

#include "Mutex.h"


/*
 *构造函数，初始化锁
 * */
Mutex::Mutex()
{
	pthread_mutexattr_t attr;

	///初始化互斥锁的属性
	pthread_mutexattr_init(&attr);      
	
	///设置互斥锁属性PTHREAD_MUTEX_NORMAL
	pthread_mutexattr_setpshared(&attr, PTHREAD_MUTEX_NORMAL);

	///初始化锁
	pthread_mutex_init(&mutex, &attr);
	
	///销毁互斥锁属性
	pthread_mutexattr_destroy(&attr);
}

/*
 * 析构函数，销毁锁
 * */
Mutex ::~Mutex()
{
	pthread_mutex_destroy(&mutex);
}

/*
 * 加锁函数，错误返回-1，成功返回0
 * */
int Mutex::lock()
{
	int err;
	err = pthread_mutex_lock(&mutex);

	if (err != 0){
		std::cout << "pthread add the lock is err\n";
		return err;
	}

	return 0;
}

/*
 *解锁函数，错误返回-1，成功返回0
 * */
int Mutex::unlock()
{
	int err ;

	err = pthread_mutex_unlock(&mutex);
	
	if (err != 0){
		std::cout << "unlock is err\n";
		return -1;
	}

	return 0;
}

pthread_mutex_t* Mutex::getMutex()
{
	return &mutex;
}
