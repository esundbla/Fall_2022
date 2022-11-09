/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Prg 02 - Sudoku Puzzle
 */

import scala.io._

object Sudoku {

  // TODO #1: return an 2D array of Int representing a sudoku board given a filename
  def readBoard(fileName: String): Array[Array[Int]] = {
    var board = Array[Array[Int]]()
    Source.fromFile(fileName).getLines().foreach { line =>
      board = board :+ line.map((c: Char) => c.toString.toInt).toArray
    }
    board
  }

  // TODO #2: return a String representation from a given sudoku board
  def boardToString(board: Array[Array[Int]]): String =
    board.map((a: Array[Int]) => a.mkString("") + '\n').mkString("")

  // TODO #3: return a specific row from a sudoku board as a sequence of numbers
  def getRow(board: Array[Array[Int]], row: Int): Array[Int] =
    board(row)

  // TODO #4: return a specific column from a sudoku board as a sequence of numbers
  def getCol(board: Array[Array[Int]], col: Int): Array[Int] = {
    val tran = board.transpose
    tran(col)
  }

  //(board.indexOf(a) >= x * 3) && (board.indexOf(a) < x * 3 + 3) && (a.indexOf(el) >= 3 * y) && (a.indexOf(el) <= 3 * y +2)))
  // TODO #5: return a specific box from a sudoku board as a sequence of numbers
  def getBox(board: Array[Array[Int]], x: Int, y: Int): Array[Int] = {
  val res =for{
    ar <- 3*x until 3*x+3
    el <- 3*y until 3*y+3
  }yield(board(ar)(el))
    res.toArray
  }

  // TODO #6: a sequence is valid if it has 9 numbers in [0-9] with possibly repeated zeros
  def isValid(seq: Array[Int]): Boolean =
    seq.filter((el: Int) => el != 0).corresponds(seq.filter((el: Int) => el != 0).distinct)(p = (a:Int, b:Int) => a == b)

  // TODO #7: return whether all rows of the given board are valid sequences
  def allRowsValid(board: Array[Array[Int]]): Boolean =
    board.forall((a: Array[Int]) => isValid(a))

  // TODO #8: return whether all columns of the given board are valid sequences
  def allColsValid(board: Array[Array[Int]]): Boolean =
    board.transpose.forall((a: Array[Int]) =>isValid(a))

  // TODO #9: return whether all boxes of the given board are valid sequences
  def allBoxesValid(board: Array[Array[Int]]): Boolean = {
    var boxes = for{
      x <- 0 to 2
      y <- 0 to  2
    } yield getBox(board, x, y)
    boxes.forall((a: Array[Int]) => isValid(a))
  }

  // TODO #10: a board is valid if all of its rows, columns, and boxes are also valid
  def isValid(board: Array[Array[Int]]): Boolean = {
    allColsValid(board) && allRowsValid(board) && allBoxesValid(board)
  }

  // TODO #11: a board is complete if there is no zero
  def isComplete(board: Array[Array[Int]]): Boolean =
    board.forall((a: Array[Int]) => !a.contains(0))

  // TODO #12: a board is solved if is complete and valid
  def isSolved(board: Array[Array[Int]]): Boolean =
    isValid(board) && isComplete(board)

  // TODO #13: return a new board configuration from the given one by setting a digit at a specific (row, col) location
  def getChoice(board: Array[Array[Int]], row: Int, col: Int, d: Int): Array[Array[Int]] =
    board.updated(row, board(row).updated(col, d))

  // TODO #14: return all possible new board configurations from the given one
  def getChoices(board: Array[Array[Int]]): IndexedSeq[Array[Array[Int]]] = {
     for {
      x <- 0 to 8
      y <- 0 to 8
      z <- 1 to 9
      if board(x)(y) == 0 && isValid(getChoice(board, x, y, z))
    } yield getChoice(board, x, y, z)
  }


  // TODO #15: return a solution to the puzzle (null if there is no solution)
  def solve(board: Array[Array[Int]]): Array[Array[Int]] = {
    if(isSolved(board))
      return board
    else
      getChoices(board).foreach((a: Array[Array[Int]]) => {/*print(boardToString(a));*/ return solve(a)})
    null
  }


  def main(args: Array[String]): Unit = {
    val board = readBoard("sudoku1.txt")
    //println(boardToString(board))
    //println(getBox(board, 2, 2).mkString(""))
    //println(isValid(Array(0, 1, 2, 3, 4, 5, 6)))
    //println(getCol(board, 2).mkString(""))
    //println(isValid(board))
    //println(isSolved(board))
    //println(boardToString(getChoice(board, 0, 0, 1)))


    val sol = solve(board)
    if(sol != null)
      println(boardToString(sol))
    else
      print("NULL")
  }
}
