/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Student: Erik Sundblad
 * Description: Homework 01 - Scala Basics
 */

object ScalaBasics {

  def main(args: Array[String]): Unit = {

    // TODO #1: declare an integer constant named MAX and set it to 10; declare an integer variable named sum and initialized it to 0
    var MAX = 10;
    var sum = 0;
    // TODO #2: write a for loop to compute sum as 1 + 2 + ... + MAX; then, display "sum is ..." substituting with the value of sum (must use variable substitution)
    for( x <- sum to MAX){
      sum = sum + x;
    }
    println(f"sum is $sum")
    // TODO #3: write a conditional to display "sum is even!" or "sum is odd!" depending on the value of sum;
    if(sum % 2 == 0){
      println("sum is even!");
    }
    else{
      println("sum is odd!");
    }
  }
}
