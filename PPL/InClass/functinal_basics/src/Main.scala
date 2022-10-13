object Main {
  def add(a: Int, b: Int): Int = a+b;
  def main(args: Array[String]): Unit = {
    for (i <- 10 to 1 by -1) {
      print(s"$i ")
    }
    print("\n")

    def addr(a: Int): Int => Int => Int = (b: Int) => (c: Int) => {
      a + b + c
    }

    println(addr(1)(2)(3))

    var arr = 1 to 10

    def double(a: Int) = 2 * a

    var ar2 = arr.map(double)
    println(ar2)
  }


}