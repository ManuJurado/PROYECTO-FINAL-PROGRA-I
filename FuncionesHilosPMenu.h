#ifndef FUNCIONESHILOSPMENU_H_INCLUDED
#define FUNCIONESHILOSPMENU_H_INCLUDED

#include "windows.h"
#include "gotoxy.h"
#include "semaphore.h"
#include "pthread.h"
#include "conio.h"

#define MUTEXLOCK pthread_mutex_lock(&key_mutex)
#define MUTEXUNLOCK pthread_mutex_unlock(&key_mutex)

// Variables globales para almacenar la tecla y un flag de acción
volatile char global_key = 0;
volatile int capturing = 1;
pthread_mutex_t key_mutex; // Mutex para proteger la variable global

void flush_stdin();
void *key_thread(void *arg);
void *funcionHiloCoche(void *arg);
void der1();
void der2();
void der3();
void der4();
void centro();

#endif // FUNCIONESHILOSPMENU_H_INCLUDED
