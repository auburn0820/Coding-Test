//
//  main.swift
//  Swift_CodingTest
//
//  Created by 피수영 on 2021/07/13.
//

struct Queue<T> {
    private var queue = Array<T>()
    
    public var size: Int {
        return self.queue.count
    }
    
    public var isEmpty: Bool {
        return self.size == 0 ? true : false
    }
    
    mutating public func push(_ value: T) {
        self.queue.append(value)
    }
    
    mutating public func pop() {
        if !self.isEmpty {
            queue.removeFirst()
        }
    }
    
    public func front() -> T? {
        return self.isEmpty == true ? nil : queue.first
    }
}

struct HumanInfo {
    var x: Int
    var y: Int
    var kCount: Int
    var moveCount: Int
    
    init(_ x: Int, _ y: Int, _ kCount: Int, _ moveCount: Int) {
        self.x = x
        self.y = y
        self.kCount = kCount
        self.moveCount = moveCount
    }
}

class Solve {
    var N = Int()
    var M = Int()
    var K = Int()
    var map = [[Int]]()
    var isVisit = [[Int]]()
    let dx: [Int] = [1, -1, 0, 0]
    let dy: [Int] = [0, 0, 1, -1]
    var isDaytime = true

    func findMinPath() -> Int {
        var q = Queue<HumanInfo>()
        
        q.push(HumanInfo(0, 0, 0, 1))
        
        while !q.isEmpty {
            var qSize = q.size
            
            while qSize > 0 {
                qSize -= 1
                
                let curX = q.front()!.x
                let curY = q.front()!.y
                let curKCnt = q.front()!.kCount
                let curMoveCnt = q.front()!.moveCount
                
                q.pop()
                
                if curX == M - 1 && curY == N - 1 {
                    return curMoveCnt
                }
                
                for i in 0..<4 {
                    let nextX = curX + dx[i]
                    let nextY = curY + dy[i]
                    
                    if nextX < 0 || nextY < 0 || nextX >= M || nextY >= N {
                        continue
                    }
                    
                    if map[nextY][nextX] == 1 {
                        if curKCnt >= K {
                            continue
                        }
                        if !isDaytime {
                            q.push(HumanInfo(curX, curY, curKCnt, curMoveCnt + 1))
                            continue
                        }
                        if curKCnt + 1 < isVisit[nextY][nextX] {
                            q.push(HumanInfo(nextX, nextY, curKCnt + 1, curMoveCnt + 1))
                            isVisit[nextY][nextX] = curKCnt + 1
                            continue
                        }
                    } else {
                        if curKCnt < isVisit[nextY][nextX] {
                            q.push(HumanInfo(nextX, nextY, curKCnt, curMoveCnt + 1))
                            isVisit[nextY][nextX] = curKCnt
                            continue
                        }
                    }
                }
            }
            isDaytime.toggle()
        }
        
        return -1
    }

    func main() {
        var numbers = Array(readLine()!.split(separator: " ").map { Int($0)! })
        
        N = numbers[0]
        M = numbers[1]
        K = numbers[2]
        
        map = Array(repeating: Array(repeating: 0, count: M), count: N)
        isVisit = Array(repeating: Array(repeating: 987654321, count: M), count: N)
        
        for i in 0..<N {
            numbers = Array(readLine()!).map { Int(String($0))! }
            for j in 0..<M {
                map[i][j] = numbers[j]
            }
        }
        
        print(findMinPath())
    }
}

let solve = Solve()

solve.main()
