object Main {
  def add(a: Int, b: Int): Int = a+b;
  def main(args: Array[String]): Unit = {
    println(add(2, 4))
    val f = add(_,2)
    println(f(3))

  }
}