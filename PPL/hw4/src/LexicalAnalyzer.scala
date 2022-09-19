/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Homework 04 - LexicalAnalyzer (an iterable lexical analyzer)
 * Student Name: Erik Sundblad
 */

import LexicalAnalyzer.{BLANKS, DIGITS, LETTERS, NEW_LINE, PUNCTUATIONS, SPECIALS}
import scala.io.Source
import scala.util.control.Breaks._

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
        // TODO: finish the implementation
        
        else if (hasLetter || getChar == '_' || getChar == '$')
          var str = getChar + ""
          nextChar
          while (!hasBlank && !eof && getChar != ',' && getChar != '{' && getChar != '}')
            if (hasDigit || hasLetter || getChar == '_' || getChar == '$')
              str = str + getChar.toString
              nextChar
            else
              throw new Exception("Lexical Analyzer Error: unrecognizable symbol found: " + getChar)
          
          
          if (str == "class")
            return new Lexeme(str, Token.CLASS)
            
          else if (str == "public")
            return new Lexeme(str, Token.PUBLIC)
            
          else if (str == "abstract")
            return new Lexeme(str, Token.ABSTRACT)
            
          else if (str == "final")
            return new Lexeme(str, Token.FINAL)
            
          else if (str == "extends")
            return new Lexeme(str, Token.EXTENDS)
            
          else if (str == "implements")
            return new Lexeme(str, Token.IMPLEMENTS)
      
          else
            return new Lexeme(str, Token.IDENTIFIER)
            
        else if (hasSpecial)
          if (getChar == '{')
            val str = getChar + ""
            nextChar
            return new Lexeme(str, Token.BLOCK_OPEN)
  
          else if (getChar == '}')
            val str = getChar + ""
            nextChar
            return new Lexeme(str, Token.BLOCK_CLOSE)

        else if (hasPunctuation)
          if(getChar == ',')
            val str = getChar + ""
            nextChar
            return new Lexeme(str, Token.COMMA)
        
        // throw an exception if an unrecognizable symbol is found
        throw new Exception("Lexical Analyzer Error: unrecognizable symbol found: " + getChar)
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
