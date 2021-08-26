

class Main {
    var N = Int()
    var B = Int()
    var matrix = [[Int64]]()
    
    func main() {
        var numbers = readLine()!.split(separator: " ").map { Int($0)! }

        N = numbers[0]
        B = numbers[1]
        
        matrix = Array(repeating: Array(repeating: 0, count: N), count: N)

        for i in 0..<N {
            numbers = readLine()!.split(separator: " ").map { Int($0)! }
            for j in 0..<N {
                matrix[i][j] = Int64(exactly: numbers[j])!
            }
        }
        
        let matrixToPrint = matrixPow(matrix: &matrix)
        
        for i in 0..<N {
            for j in 0..<N {
                print(matrixToPrint[i][j], terminator: " ")
            }
            print()
        }
    }
    
    func matrixMul(a: [[Int64]], b: [[Int64]]) -> [[Int64]] {
        var res = [[Int64]]()
        res = Array(repeating: Array(repeating: 0, count: N), count: N)
        
        for i in 0..<N {
            for j in 0..<N {
                for k in 0..<N {
                    res[i][j] += a[i][k] * b[k][j]
                }
                res[i][j] %= 1000
            }
        }
        return res
    }
    
    func matrixPow(matrix: inout [[Int64]]) -> [[Int64]] {
        var res = [[Int64]]()
        res = Array(repeating: Array(repeating: 0, count: N), count: N)
        var n = B
        
        for i in 0..<N {
            res[i][i] = 1
        }
        
        while n > 0 {
            if n % 2 == 1 {
                res = matrixMul(a: res, b: matrix)
            }
            n /= 2
            matrix = matrixMul(a: matrix, b: matrix)
        }
        
        return res
    }
}

let main = Main()

main.main()
