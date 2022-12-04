/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Activity 21 - DiningPhilosopherProblem
 */

public class DiningPhilosopherProblem { 

    public static void main(String[] args) {  
        int n = 5; 
   
        // create and initialize all forks 
        Object forks[] = new Object[n];
        for (int i=0; i<n; i++){
            forks[i] = new Object();
        }

        // create the philosophers and start them as threads  
        for (int i=0; i<n; i++){
            Object leftFork = forks[i];
            Object rightFork = forks[(i+1) % n];
            Philosopher philosopher;
            if(i%2 ==0){
                philosopher = new Philosopher(leftFork, rightFork);
            }else{
                philosopher = new Philosopher(rightFork, leftFork);
            }
            Thread thread = new Thread(philosopher);
            thread.setName("p" + i);
            thread.start();
        }
    } 
 } 