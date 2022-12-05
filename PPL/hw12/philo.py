'''
CS3210 - Principles of Programming Languages - Fall 2022
Instructor: Thyago Mota
Description: Homework 12 - Dining Philosopher Problem
Student Name: Erik Sundblad
'''

import threading
import time 
import random

class Philosopher(threading.Thread):  

    def __init__(self, name, left_fork, right_fork): 
        threading.Thread.__init__(self) 
        self.name = name 
        self.left_fork = left_fork
        self.righ_fork = right_fork

    def think(self): 
        time.sleep(
            random.randint(1, 10) / 1000
        )

    def eat(self): 
        time.sleep(
            random.randint(1, 50) / 1000
        )

    def run(self): 
        while True: 
            self.left_fork.acquire()
            print(self.name + " got the left fork")
            self.righ_fork.acquire()
            print(self.name + " got the right fork")
            self.think()
            self.eat()
            self.righ_fork.release()
            print(self.name + " released the right fork")
            self.left_fork.release()
            print(self.name + " released the left fork")

if __name__ == "__main__": 
    
    # number of philosopher
    n = 5
    
    # TODO #1: create n=5 forks 
    forks = [ threading.Lock() for i in range(n)]
    # TODO #2: create n=5 philosophers, allocating the forks in a way to avoid the deadlock
    for i in range(n):
        l_fork = forks[i]
        r_fork = forks[(i+1)%n]
        #Odd even solution switch which forks each philosopher will grab
        if i%2 ==0:
            philosopher = Philosopher(i, l_fork, r_fork)
        else:
            philosopher = Philosopher(i, r_fork, l_fork)
        
        # TODO #3: start the philosopher threads
        philosopher.start()