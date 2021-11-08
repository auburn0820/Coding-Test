import Foundation

var N = 0, C = 0
var arr = [Int]()
var map = [Int: Int]()

func input() {
    arr = readLine()!.split(separator: " ").map { Int(String($0))! }
    
    N = arr[0]
    C = arr[1]
    
    arr.removeAll()
    arr = readLine()!.split(separator: " ").map { Int(String($0))! }
}

func solve() {
    var storage = Array(repeating: (num: 0, count: 0), count: arr.max()! + 1)
    
    for number in arr {
        if storage[number] == (0, 0) {
            storage[number] = (number, 1)
        } else {
            storage[number] = (number, storage[number].count + 1)
        }
    }
    
    storage = storage.filter {
        if $0 != (0, 0) {
            return true
        } else {
            return false
        }
    }
    
    storage = storage.sorted {
        if $0.count == $1.count {
            let left = arr.firstIndex(of: $0.num)!
            let right = arr.firstIndex(of: $1.num)!
            
            return left < right
        } else {
            return $0.count > $1.count
        }
    }
    
    for i in storage {
        for _ in 0..<i.count {
            print(i.num, terminator: " ")
        }
    }
    print()
}

input()
solve()
