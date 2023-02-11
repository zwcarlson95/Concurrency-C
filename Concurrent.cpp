/*
 * Concurrent.cpp
 *
 *  Created on: Jan 28, 2023
 *      Author: zachcarlson
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cond;
int count = 0;
bool going_up() {return count < 20;}
bool going_down() {return count >= 0;}


void countUp() {
	std::unique_lock<std::mutex> lock(mtx);
	cond.wait(lock, going_up);

    for (int i = 0; i <= 19; i++) {

        count = i;

        std::cout << "Thread 1: count = " << count << std::endl;
    }
    cond.notify_all();
}

void countDown() {
	std::unique_lock<std::mutex> lock(mtx);
	cond.wait(lock, going_down);

    for (int i = 20; i >= 0; i--) {

        count = i;

        std::cout << "Thread 2: count = " << count << std::endl;
    }
    cond.notify_all();
}

int main() {
    std::thread t1(countUp);
    std::thread t2(countDown);
    t1.join();
    t2.join();
    return 0;
}


