package main

import "fmt"

func maximumWealth(accounts [][]int) int {
    res := 0
    for _, row := range accounts {
        temp := 0
        for _, value := range row {
            temp += value
        }
        if temp > res {
            res = temp
        }
    }
    return res
}

func main() {
    // Example usage
    accounts := [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
    maxWealth := maximumWealth(accounts)
    fmt.Println("Maximum wealth:", maxWealth)
}