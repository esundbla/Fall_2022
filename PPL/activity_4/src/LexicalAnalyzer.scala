/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Activity 04 - LexicalAnalyzer (an iterable lexical analyzer)
 * Student(s) Name(s): Erik Sundblad
 */

import LexicalAnalyzer.{BLANKS, DIGITS, LETTERS, NEW_LINE, PUNCTUATIONS, SPECIALS}
import scala.io.Source
//import Lexeme.Lexeme
//import Token.Token

class LexicalAnalyzer(private var source: String) extends Iterable[Lexeme]{

  var input = ""
  for (line <- Source.fromFile(source).getLines)
    input += line + LexicalAnalyzer.NEW_LINE
  input = input.trim

  // checks if reached eof
  private def eof: Boolean = input.length == 0

  var currentChar: Char = 0

  // returns the current char
  private def getChar = {
    if (!eof)
      currentChar = input(0)
    currentChar
  }

  // advances the input one character
  private def nextChar: Unit = {
    if (!eof)
      input = input.substring(1)
  }

  // checks if input has a blank character ahead
  private def hasBlank: Boolean = {
    LexicalAnalyzer.BLANKS.contains(getChar)
  }

  // reads the input until a non-blank character is found, updating the input
  def readBlanks: Unit = {
    while (!eof && hasBlank)
        nextChar
  }

  // checks if input has a letter ahead
  private def hasLetter: Boolean = {
    LexicalAnalyzer.LETTERS.contains(getChar)
  }

  // checks if input has a digit ahead
  private def hasDigit: Boolean = {
    LexicalAnalyzer.DIGITS.contains(getChar)
  }

  // checks if input has a special character ahead
  private def hasSpecial: Boolean = {
    LexicalAnalyzer.SPECIALS.contains(getChar)
  }

  // checks if input has a punctuation character ahead
  private def hasPunctuation: Boolean = {
    LexicalAnalyzer.PUNCTUATIONS.contains(getChar)
  }

  // returns an iterator for the lexical analyzer
  override def iterator: Iterator[Lexeme] = {

    new Iterator[Lexeme] {

      // returns true/false depending whether there is a lexeme to be read from the input
      override def hasNext: Boolean = {
        readBlanks
        !eof
      }

      // returns the next lexeme (or Token.EOF if there isn't any lexeme left to be read)
      override def next(): Lexeme = {

        if (!hasNext)
          return new Lexeme("eof", Token.EOF)

        if (hasLetter) {
            val str = getChar + ""
            nextChar
            return new Lexeme(str, Token.IDENTIFIER)
        }
        // TODO #1: identify a literal value
        else if (hasDigit) {
          var str = ""
          while(hasDigit && !eof){
            str += getChar;
            nextChar
          }
          return new Lexeme(str, Token.LITERAL)
        }
        else if (getChar == '+') {
          val str = getChar + ""
          nextChar
          return new Lexeme(str, Token.ADDITION)
        }
        // TODO #2: identify a subtraction operator
        else if (getChar == '-') {
          val str = getChar + ""
          nextChar
          return new Lexeme(str, Token.SUBTRACTION)
        }
        // TODO #3: identify a multiplication operator
        else if (getChar == '*') {
          val str = getChar + ""
          nextChar
          return new Lexeme(str, Token.MULTIPLICATION)
        }
        // TODO #4: identify a division operator
        else if (getChar == '/') {
          val str = getChar + ""
          nextChar
          return new Lexeme(str, Token.DIVISION)
        }

        // throw an exception if an unrecognizable symbol is found
        throw new Exception("Lexical Analyzer Error: unrecognizable symbol found!")
      }
    }
  }
}

object LexicalAnalyzer {
  val BLANKS       = " \n\t"
  val NEW_LINE     = '\n'
  val LETTERS      = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
  val DIGITS       = "0123456789"
  val PUNCTUATIONS = ".,;:?!"
  val SPECIALS     = "<_@#$%^&()-+='/\\[]{}|"

  def main(args: Array[String]): Unit = {

    // checks the command-line for source file
    if (args.length != 1) {
      print("Missing source file!")
      System.exit(1)
    }

    // iterates over the lexical analyzer, printing the lexemes found
    val lex = new LexicalAnalyzer(args(0))
    for (lexeme <- lex)
      println(lexeme)

  } // end main method
}
