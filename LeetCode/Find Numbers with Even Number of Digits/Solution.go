func findNumbers(nums []int) int {
    cnt := 0
    for _, val := range nums {
        digit := 0
        num := val
        for num > 0 {
            num /= 10
            digit++
        }
        if digit % 2 == 0 {
            cnt++
        }
    }
    return cnt
}