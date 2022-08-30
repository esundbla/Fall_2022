/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Activity 01 - PowerFunction
 */

object PowerFunction {

  // TODO: write the power function below using pattern matching
  // y y if n is positive and even, where y = x^(n/2)
  // x x^(n-1) if n is positive and odd
  // 1/x^(-n) if n is negative
  // 1 if n is 0
  def power(x: Double, n: Int): Double = {
    n match
        case 0 => 1
        case negative if n < 0 => 1/scala.math.pow(x,-n)
        case even if n % 2 == 0 => scala.math.pow(x, (n/2))
        case odd if n % 2 != 0 => scala.math.pow(x, (n-1))
        
  }

  def main(args: Array[String]): Unit = {
    println(s"2^8 = ${power(2, 8)}")
    println(s"2^7 = ${power(2, 7)}")
    println(s"2^-2 = ${power(2, -2)}")
    println(s"2^0 = ${power(2, 0)}")
  }
}
