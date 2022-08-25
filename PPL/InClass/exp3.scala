object exp3 {
  def main(args: Array[String]) = {
    // test1 is implicitly declared as a String
    var test1 = "Type inference in Scala!"
    // Scala is a statically typed language (so in this case if we try to assign a value other than a String it won't work!)
    test1 = 10
    // we use "val" to declare constants in Scala
    val test2 = "Initial value"
    // once an initial value is given to a constant, you cannot assign a new value
    test2 = "trying to change it (won't work!)"
  }
}