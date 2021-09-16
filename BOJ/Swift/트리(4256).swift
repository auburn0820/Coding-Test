import Foundation

var T = Int(), N = Int()

func postorder(_ preorder: [Int], _ inorder: [Int], _ root: Int, _ minIndex: Int, _ maxIndex: Int) {
    for i in minIndex..<maxIndex {
        if inorder[i] == preorder[root] {
            postorder(preorder, inorder, root + 1, minIndex, i)
            postorder(preorder, inorder, root + i + 1 - minIndex, i + 1, maxIndex)
            print(preorder[root], terminator: " ")
        }
    }
}

func solution() {
    T = Int(readLine()!)!
    while T > 0 {
        N = Int(readLine()!)!
        
        let preorder = readLine()!.split(separator: " ").map { Int($0)! }
        let inorder = readLine()!.split(separator: " ").map { Int($0)! }
        
        postorder(preorder, inorder, 0, 0, N)
        print()
        
        T -= 1
    }
}

solution()
