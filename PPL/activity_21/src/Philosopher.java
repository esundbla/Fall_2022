/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Activity 21 - Philosopher
 */

import java.util.Random; 

public class Philosopher implements Runnable { 

   private Object leftFork, rightFork; 
   private static final Random rnd = new Random(); 

   Philosopher(Object leftFork, Object rightFork) {
        this.leftFork = leftFork;
        this.rightFork = rightFork;
   } 

   void think() { 
       try {
        int thinkT = rnd.nextInt(10) +1;
         Thread.sleep(thinkT);  
       } 
       catch (InterruptedException ex) {} 
   } 
 
   void eat() { 
       try { 
        int eatTime = rnd.nextInt(50) +1;
        Thread.sleep(eatTime);
       } 
       catch (InterruptedException ex) {} 
   } 

   @Override 
   public void run() { 
       String name = Thread.currentThread().getName(); 
       while (true) { 
            synchronized(leftFork){
                synchronized(rightFork){
                    System.out.println(name + " Is Thinking");
                    think();
                    System.out.println(name + " Is Eating");
                    eat();
                }
            }
       } 
   } 
}
