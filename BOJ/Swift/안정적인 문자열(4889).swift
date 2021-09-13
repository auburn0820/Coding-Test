import Foundation

var arr = Array<Character>()
var stack = [Character]()

func isCorrect(_ str: Array<Character>) -> Bool {
    
    for i in str {
        if str.isEmpty {
            stack.append(i)
        } else if stack.last == "{" && i == "}" {
            stack.removeLast()
        } else {
            stack.append(i)
        }
    }
    
    if stack.isEmpty {
        return true
    } else {
        return false
    }
}

func countOperation() -> Int {
    var count = 0
    var stackForCount = [Character]()
    
    for i in stack {
        if stackForCount.isEmpty {
            stackForCount.append(i)
        } else if stackForCount.last == i {
            count += 1
            stackForCount.removeLast()
        } else if stackForCount.last != i {
            count += 2
            stackForCount.removeLast()
        }
    }
    
    return count
}

func solution() {
    var idx = 1
    while true {
        arr = Array(readLine()!)
        
        if arr.contains("-") {
            break
        }
        
        if isCorrect(arr) {
            print("\(idx). 0")
        } else {
            print("\(idx). \(countOperation())")
        }
        
        stack.removeAll()
        
        idx += 1
    }
}

solution()
