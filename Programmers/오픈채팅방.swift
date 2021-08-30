import Foundation

func solution(_ record:[String]) -> [String] {
    var userInfo = [[String]]()
    var uidSet = [String: String]()
    var returnArr = [String]()
    
    for i in 0..<record.count {
        userInfo.append(record[i].split(separator: " ").map { String($0) })
    }
    
    for i in 0..<userInfo.count {
        if userInfo[i][0] == "Enter" {
            if uidSet[userInfo[i][1]] != nil {
                uidSet.removeValue(forKey: userInfo[i][1])
                uidSet.updateValue(userInfo[i][2], forKey: userInfo[i][1])
            }
            else {
                uidSet.updateValue(userInfo[i][2], forKey: userInfo[i][1])
            }
        }
        else if userInfo[i][0] == "Change" {
            uidSet.removeValue(forKey: userInfo[i][1])
            uidSet.updateValue(userInfo[i][2], forKey: userInfo[i][1])
        }
    }
    
    for i in 0..<userInfo.count {
        if userInfo[i][0] == "Enter" {
            returnArr.append("\(uidSet[userInfo[i][1]]!)님이 들어왔습니다.")
        }
        else if userInfo[i][0] == "Leave" {
            returnArr.append("\(uidSet[userInfo[i][1]]!)님이 나갔습니다.")
        }
    }
    
    return returnArr
}
