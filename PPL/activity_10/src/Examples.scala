/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Activity 10 - Functional Programming Examples
 */

object Examples {

  // TODO: find all of the numbers from 1–1000 that are divisible by 8
  def lc1() = {
    for{
      x <- 1 to 1000
        if x % 8 == 0
    }yield x
  }

  // TODO: find all of the numbers from 1–1000 that have a 6 in them
  def lc2() = {
    for{
      x <- 1 to 1000
        if x.toString().contains('6')
    }yield x
  }

  // TODO: count the number of spaces in a (given) string
  def lc3(str: String) = {
    for{
      x <- str
      if x == ' '
    }yield 1
  }

  // TODO: remove all of the vowels in a (given) string
  def lc4(str: String) = {
    var vowels = "aeiouy"
    for{
      char <- str
      if !vowels.contains(char)
    }yield char


  }
  // TODO: find all of the words in a (given) string that are less than 5 letters
  def lc5(str: String) = {
    for{
      x <- str.split(" ")
      if x.length() < 5
    }yield x
  }

  // TODO: count the length of each word in a (given) string
  def lc6(str: String) = {
    for {
      x <- str.split(" ")
    } yield x.length()

  }

  // TODO: use a nested list comprehension to find all of the numbers from 1–1000 that are divisible by any single digit besides 1 (2–9)
  def lc7() = {
    for {
      x <- 2 to 9
      y <- 1 to 1000
      if y != x && y%x ==0
    }yield y
  }

  def polyFrom(x: Int, n: Int): LazyList[Double] = {
    LazyList.cons(Math.pow(x,n), polyFrom(x, n+1))
  }
  def main(args: Array[String]): Unit = {
    println(lc1().mkString(" "))
    println(lc2().mkString(" "))
    println(lc3("this is a string with   8 spaces!"))
    println(lc4("this string will have its vowels removed!"))
    println(lc5("words with less than five letters in this string!").mkString(" "))
    println(lc6("counting the length of each word in this string!").mkString(" "))
    println(lc7().mkString(" "))
    println(polyFrom(2, 0).take(10).mkString("+"))
  }
}