import Foundation

let numbers = readLine()!.split(separator: " ").map({ Int($0)! })
let N = numbers[0]
let K = numbers[1]
var is_visit = Array<Array<Int>>(repeating: Array<Int>(repeating: -1, count: 500001), count: 2)

struct Pair {
    let position: Int
    let count: Int
    
    init(_ position: Int, _ count: Int) {
        self.position = position
        self.count = count
    }
}

func sum(_ number: Int) -> Int {
    return number * (number + 1) / 2
}

func BFS() {
    var queue = [Pair]()
    queue.append(Pair(N, 0))
    var idx = 0
    
    while idx < queue.count {
        let curPosition = queue[idx].position
        let curCount = queue[idx].count
        idx += 1
        
        if curPosition > 500000 || curPosition < 0 {
            continue
        }
        
        if is_visit[curCount % 2][curPosition] != -1 {
            continue
        }
        
        is_visit[curCount % 2][curPosition] = curCount
        queue.append(Pair(curPosition + 1, curCount + 1))
        queue.append(Pair(curPosition - 1, curCount + 1))
        queue.append(Pair(curPosition * 2, curCount + 1))
    }
}

func solution() {
    BFS()
    
    for i in 0..<500000 {
        let nextK = K + sum(i)
        
        if nextK > 500000 {
            print(-1)
            break
        }
        
        if(is_visit[i % 2][nextK] != -1 && is_visit[i % 2][nextK] <= i) {
            print(i)
            break
        }
    }
}

solution()
