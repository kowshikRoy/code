package main

import (
	"fmt"
	"os/exec"
)

func main() {
	buildC := exec.Command("g++-9", "/Users/kowshik.roy/code/codeforces/792/A.cpp")
	out, err := buildC.CombinedOutput()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(string(out))
}
