import Foundation

var N = Int(), K = Int()
var coordinates = [(Int, Int)]()
var dp = Array(repeating: Array(repeating: -1, count: 501), count: 501)
var distances = Array(repeating: Array(repeating: -1, count: 501), count: 501)

func input() {
    let numbers = readLine()!.split(separator: " ").map { Int($0)! }
    N = numbers[0]
    K = numbers[1]
    
    for _ in 0..<N {
        let coordinate = readLine()!.split(separator: " ").map { Int($0)! }
        coordinates.append((coordinate[0], coordinate[1]))
    }
}

func getMinDistance(_ index: Int, _ k: Int) -> Int {
    if index == 1 {
        return 0
    }
    if dp[index][k] != -1 {
        return dp[index][k]
    }
    
    var minDistance = Int.max
    for i in 0...k {
        if index - i - 1 < 1 {
            break
        }
        minDistance = min(getMinDistance(index - i - 1, k - i) + distances[index - i - 1][index], minDistance)
    }
    
    dp[index][k] = minDistance
    
    return minDistance
}

func solution() {
    for i in 0..<N - 1 {
        for j in i + 1...N - 1 {
            distances[i + 1][j + 1] = abs(coordinates[i].0 - coordinates[j].0) + abs(coordinates[i].1 - coordinates[j].1)
        }
    }
    
    print(getMinDistance(N, K))
}

input()
solution()
