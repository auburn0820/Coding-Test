import Foundation

var N = 0, M = 0, H = 0
var isExist = Array(repeating: Array(repeating: false, count: 12), count: 31)
var result = -1

func input() {
    var arr = readLine()!.split(separator: " ").map { Int(String($0))! }
    
    N = arr[0]
    M = arr[1]
    H = arr[2]
    
    arr.removeAll()
    
    for _ in 0..<M {
        var a = 0, b = 0
        arr = readLine()!.split(separator: " ").map { Int(String($0))! }
        a = arr[0]
        b = arr[1]
        
        isExist[a][b] = true
    }
}

func simulate() -> Bool {
    for i in 1...N {
        var x = i
        
        for j in 1...H {
            if isExist[j][x - 1] {
                x -= 1
            } else if isExist[j][x] {
                x += 1
            }
        }
        
        if x != i {
            return false
        }
    }
    return true
}

func find_cases(curCount: Int, height: Int, maxCount: Int) {
    if curCount == maxCount {
        if simulate() {
            print(curCount)
            exit(0)
        }
        return
    }
    
    for i in height...H {
        for j in 1...N {
            if isExist[i][j] || isExist[i][j - 1] || isExist[i][j + 1] {
                continue
            }
            
            isExist[i][j] = true
            find_cases(curCount: curCount + 1, height: i, maxCount: maxCount)
            isExist[i][j] = false
        }
    }
}

func solve() {
    input()
    for i in 0...3 {
        find_cases(curCount: 0, height: 1, maxCount: i)
    }
    
    print(-1)
}

solve()
