/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Activity 09 - Functional Programming Examples
 */

object Examples {

  

  def main(args: Array[String]): Unit = {
    def add3(a: Int): Int => Int => Int = (b:Int) => (c:Int) => a + b+ c
    def add4(d: Int): Int => Int => Int => Int = (a: Int) => (b: Int) =>  (c: Int) => d + add3(a)(b)(c)

    //println(add3(4)(5)(6))
    //println(add4(4)(5)(6)(7))

    def gcd(a: Int): Int => Int = (b: Int) => if (a%b == 0) b else gcd(b)(a%b)

    def coprime(a: Int)= (b: Int) => gcd(a)(b) == 1

    def totientPhi(m: Int) =
      (1 until m).filter((r: Int) => coprime(r)(m))
    print()

    println(totientPhi(15))
    println(coprime(2)(4))
    println(gcd(1)(3))

  }
}