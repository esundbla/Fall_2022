/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Prg 01 - LexicalAnalyzer (an iterable lexical analyzer)
 * Student(s) Name(s): Erik SUndblad
 */

import LexicalAnalyzer.{BLANKS, DIGITS, LETTERS, NEW_LINE, PUNCTUATIONS, SPECIALS}
import scala.io.Source

class LexicalAnalyzer(private var source: String) extends Iterable[Lexeme] {

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

      // TODO: return the next lexeme (or Token.EOF if there isn't any lexeme left to be read)
      override def next(): Lexeme = {
        if (!hasNext) {
          new Lexeme("eof", Token.EOF)
        }
        else if (getChar == '"') {
          nextChar
          var str = getChar + ""
          nextChar
          while (getChar != '"') {
            str += getChar
            nextChar
          }

          nextChar
          new Lexeme(str, Token.STRING)
        }

        else if (hasLetter) {
          var str = getChar + ""
          nextChar
          while ((hasLetter || hasDigit || getChar == '_') && hasNext) {
            str += getChar
            nextChar
          }
          new Lexeme(str, Token.IDENTIFIER)
        }

        else if (hasDigit) {
          var str = getChar + ""
          nextChar
          while (hasDigit && hasNext) {
            str += getChar
            nextChar
          }
          new Lexeme(str, Token.LITERAL)
        }

        else if (hasPunctuation) {
          var str = getChar + ""
          if (getChar == '.') {
            nextChar
            new Lexeme(str, Token.DOT)
          }
          else if (getChar == '!') {
            nextChar
            if (getChar == '=') {
              str += getChar
              nextChar
              new Lexeme(str, Token.DIFFERENT)
            } else {
              new Lexeme(str, Token.OUTPUT)
            }
          }
          else if (getChar == '?') {
            nextChar
            new Lexeme(str, Token.INPUT)
          }
          else if (getChar == ';') {
            nextChar
            while (getChar != '\n') {
              str += getChar
              nextChar
            }
            str += getChar //Get that last newline charecter
            nextChar
            new Lexeme(str, Token.COMMENT)
          } else {
            throw new Exception("Invalid char: " + getChar)
          }
        }
        else if (hasSpecial) {
          var str = getChar + ""

          if (str == "=") {
            nextChar
            if (getChar == '=') { //check for equal or assignment
              str += getChar
              nextChar
              return new Lexeme(str, Token.EQUAL)
            }
            else {
              return new Lexeme(str, Token.ASSIGNMENT)
            }
          }
          else if (getChar == '+') {
            nextChar
            return new Lexeme(str, Token.ADDITION)
          }

          else if (getChar == '-') {
            nextChar
            return new Lexeme(str, Token.SUBTRACTION)
          }
          else if (getChar == '*') {
            nextChar
            return new Lexeme(str, Token.MULTIPLICATION)
          }
          else if (getChar == '/') {
            nextChar
            return new Lexeme(str, Token.DIVISION)
          }
          else if (getChar == '%') {
            nextChar
            return new Lexeme(str, Token.MODULUS)
          }
          else if (getChar == '^') {
            nextChar
            return new Lexeme(str, Token.BREAK)
          }
          else if (getChar == '(') {
            nextChar
            return new Lexeme(str, Token.OPEN_PAR)
          }
          else if (getChar == '[') {
            nextChar
            return new Lexeme(str, Token.OPEN_BRACKET)
          }
          else if (getChar == ')') {
            nextChar
            return new Lexeme(str, Token.CLOSE_PAR)
          }
          else if (getChar == ']') {
            nextChar
            return new Lexeme(str, Token.CLOSE_BRACKET)
          }
          else if (getChar == '<') {
            nextChar
            if (getChar == '=') {
              str += getChar
              nextChar
              return new Lexeme(str, Token.LESS_EQUAL)
            }
            else {
              return new Lexeme(str, Token.LESS)
            }
          }
          else if (getChar == '>') {
            nextChar
            if (getChar == '=') {
              str += getChar
              nextChar
              return new Lexeme(str, Token.GREATER_EQUAL)
            }
            else {
              return new Lexeme(str, Token.GREATER)
            }
          }
          else if (getChar == '$') {
            nextChar
            if (getChar == '$') {
              str += getChar
              nextChar
              return new Lexeme(str, Token.EO_PRG)
            }else {
              throw new Exception("Invalid End Of Program, required 2, $ but only got 1")
            }
          }else{
            throw new Exception("Invalid charecter: " + getChar)
          }
        }
        else {
          // throw an exception if an unrecognizable symbol is found
          throw new Exception("Lexical Analyzer Error: unrecognizable symbol \"" + getChar + "\" found!")
        }
      }
    }
  }
}


object LexicalAnalyzer {
  val BLANKS = " \n\t"
  val NEW_LINE = '\n'
  val LETTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
  val DIGITS = "0123456789"
  val PUNCTUATIONS = ".,;:?!"
  val SPECIALS = "><_@#$%^&*()-+='/\\[]{}|"

  def main(args: Array[String]): Unit = {

    // checks the command-line for source file
    if (args.length != 1) {
      print("Missing source file!")
      System.exit(1)
    }

    // iterates over the lexical analyzer, printing the lexemes found
    val lex = new LexicalAnalyzer(args(0))
    val it = lex.iterator
    while (it.hasNext)
      println(it.next())

  } // end main method
}

