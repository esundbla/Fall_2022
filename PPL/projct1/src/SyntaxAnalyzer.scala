/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Prg 01 - SyntaxAnalyzer (an iterable syntax analyzer)
 * Student(s) Name(s): Erik Sundblad
 */

class SyntaxAnalyzer(private var source: String) {

  private val it = new LexicalAnalyzer(source).iterator
  private var current: Lexeme = null

  // returns the current lexeme
  private def getLexeme: Lexeme = {
    if (current == null)
      nextLexeme
    current
  }

  // advances the input one lexeme
  private def nextLexeme = {
    current = it.next
  }

  // returns true if the given token identifies a statement (or the beginning of a statement)
  private def isStatement(token: Token.Value): Boolean = {
    token == Token.IDENTIFIER     ||
    token == Token.LITERAL        ||
    token == Token.STRING         ||
    token == Token.INPUT          ||
    token == Token.OUTPUT         ||
    token == Token.ASSIGNMENT     ||
    token == Token.ADDITION       ||
    token == Token.SUBTRACTION    ||
    token == Token.MULTIPLICATION ||
    token == Token.DIVISION       ||
    token == Token.MODULUS        ||
    token == Token.LESS           ||
    token == Token.LESS_EQUAL     ||
    token == Token.GREATER        ||
    token == Token.GREATER_EQUAL  ||
    token == Token.EQUAL          ||
    token == Token.DIFFERENT      ||
    token == Token.BREAK          ||
    token == Token.DOT            ||
    token == Token.OPEN_BRACKET   ||
    token == Token.OPEN_PAR
  }

  // returns true if the given token identifies a line (or the beginning of a line)
  // a line can be a statement or a comma
  private def isLine(token: Token.Value): Boolean = {
    isStatement(token) || token == Token.COMMENT
  }

  // parses the program, returning its corresponding parse tree
  def parse: Node = {
    parseMouse
  }

  // TODO: mouse = { line } ´$$´
  private def parseMouse: Node = {
    val node = new Node(new Lexeme("mouse"))
    while(getLexeme.token != Token.EO_PRG)          //loop through calling parseline till we get to $$
      node.add(parseLine)       //parse the line  

    node.add(new Node(getLexeme))   //return $$ node 
    node
  }

  // TODO: line = statement | comment
  private def parseLine: Node = {
    val node = new Node(new Lexeme("line"))
    if (getLexeme.token == Token.COMMENT)     //Add comment and move to next line
      node.add(new Node(getLexeme))
      nextLexeme
    else
      node.add(parseStatement)         
  
    node
  }

  // TODO: statement = ´?´ | ´!´ | string | identifier | ´=´ | literal | ´+´ | ´-´ | ´*´ | ´/´ | ´%´ | ´<´ | ´<=´ | ´>´ | ´>=´ | ´==´ | ´!=´ | ´^´ | ´.´ |  | if | while
  private def parseStatement: Node = {
    val node = new Node(new Lexeme("statement"))
    if (isStatement(getLexeme.token))               //grab if not if or while
      node.add(new Node(getLexeme))
      if( getLexeme.token == Token.OPEN_BRACKET)
        nextLexeme
        node.add(parseIf)
        if (getLexeme.token == Token.CLOSE_BRACKET)   //after if statement we need a closing bracket or throw error  
          node.add(new Node(getLexeme))
          nextLexeme
        else
          throw new Exception("Expected closing bracket { but got " + getLexeme)
      else if ( getLexeme.token == Token.OPEN_PAR)    //if open Par then move to while parse
        nextLexeme
        node.add(parseWhile)
        if (getLexeme.token == Token.CLOSE_PAR)   //after if statement we need a closing par or throw error  
          node.add(new Node(getLexeme))
          nextLexeme
        else
          throw new Exception("Expected closing par ( but got " + getLexeme)
      else
        nextLexeme
        
    else
      throw new Exception("Invalid element for statement: " + getLexeme)  //invalid token throw exception

    node
  }

  // TODO: if = ´[´ { line } ´]´
  def parseIf: Node = {
    val node = new Node(new Lexeme("if"))
    while(getLexeme.token != Token.CLOSE_BRACKET && getLexeme.token != Token.EO_PRG)
      node.add(parseLine)
    node
  }

  // TODO: while = ´(´ { line } ´)´
  def parseWhile: Node = {
    val node = new Node(new Lexeme("while"))
    while(getLexeme.token != Token.CLOSE_PAR && getLexeme.token != Token.EO_PRG)
      node.add(parseLine)
    node
  }
}

object SyntaxAnalyzer {
  def main(args: Array[String]): Unit = {

    // check if source file was passed through the command-line
    if (args.length != 1) {
      print("Missing source file!")
      System.exit(1)
    }

    val syntaxAnalyzer = new SyntaxAnalyzer(args(0))
    val parseTree = syntaxAnalyzer.parse
    print(parseTree)
  }
}
