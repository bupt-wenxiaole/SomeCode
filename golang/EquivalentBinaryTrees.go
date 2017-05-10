package main

import "golang.org/x/tour/tree"

import "fmt"

// Walk walks the tree t sending all values
// from the tree to the channel ch.
func Walk(t *tree.Tree, ch chan int) {
	helper(t, ch)
	close(ch)
}
func helper(t *tree.Tree, ch chan int) {
	if t == nil {
		return
	}
	helper(t.Left, ch)
	ch <- t.Value
	helper(t.Right, ch)
}

// Same determines whether the trees
// t1 and t2 contain the same values.
func Same(t1, t2 *tree.Tree) bool {
	c1 := make(chan int)
	c2 := make(chan int)
	go Walk(t1, c1)
	go Walk(t2, c2)
	for {
		i, ok1 := <-c1
		j, ok2 := <-c2
		if i != j || ok1 != ok2 {
			return false
		}
		if !ok1 {
			break
		}

	}
	return true
}

func main() {

	fmt.Println(Same(tree.New(1), tree.New(1)))
	fmt.Println(Same(tree.New(1), tree.New(2)))
}
