/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Homework 04 - Lexeme: a symbol with an optional token value
 * Student Name: Erik Sundblad
 */
package Lexeme

class exeme(var label: String, var token: Token.Value = null) {
  override def toString: String = {
    var s = s"Lexeme($label"
    if (token != null)
      s += s", $token"
    s + ")"
  }
}

