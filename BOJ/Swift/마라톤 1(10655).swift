import Foundation

var N = Int()
var coordinates = [(Int, Int)]()

func input() {
    N = Int(readLine()!)!
    
    for _ in 0..<N {
        let coordinate = readLine()!.split(separator: " ").map { Int($0)! }
        coordinates.append((coordinate[0], coordinate[1]))
    }
}

func solution() {
    var result = 0
    var totalDistance = 0
    for i in 1..<coordinates.count {
        totalDistance += abs(coordinates[i - 1].0 - coordinates[i].0) + abs(coordinates[i - 1].1 - coordinates[i].1)
    }
    
    result = totalDistance
    
    for i in 1..<coordinates.count - 1 {
        let prevDistance = abs(coordinates[i - 1].0 - coordinates[i].0) + abs(coordinates[i - 1].1 - coordinates[i].1)
        let nextDistance = abs(coordinates[i + 1].0 - coordinates[i].0) + abs(coordinates[i + 1].1 - coordinates[i].1)
        let newDistance = abs(coordinates[i + 1].0 - coordinates[i - 1].0) + abs(coordinates[i + 1].1 - coordinates[i - 1].1)
        
        totalDistance -= (prevDistance + nextDistance)
        totalDistance += newDistance
        result = min(result, totalDistance)
        totalDistance += (prevDistance + nextDistance)
        totalDistance -= newDistance
    }
    
    print(result)
}

input()
solution()
