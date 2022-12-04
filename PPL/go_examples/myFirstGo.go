/*
 * Go Language basics
 * Erk Sundblad
 * Fall 2022 PPL
 */

package main

import "fmt"

Node = {
	int id
	string name
}

func main() {
	for i := 0; i < 10; i++ {
		fmt.Printf("%d\n", i)
	}
	
	sum := 1
	for sum < 20 {
		fmt.Printf("%d\n", sum)
		sum++
	}
}
