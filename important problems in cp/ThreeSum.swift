class ThreeSum {
    func threeSum(_ nums: [Int]) -> [[Int]] {
        
        var result: [[Int]] = []
        let nums = nums.sorted()
        let len = nums.count
        
        guard len >= 3 else { return result }
        
        for i in 0..<len {
            if i > 0 && nums[i] == nums[i-1] { continue }
            
            let num = 0 - nums[i]
            var a = i + 1, b = len - 1
            
            while a < b {
                let numA = nums[a], numB = nums[b]
                let sum = numA + numB
                if sum == num {
                    result.append([nums[i], numA, numB])
                    a += 1
                    b -= 1
                    while a < b && nums[a] == nums[a-1] { a += 1 }
                    while a < b && nums[b] == nums[b+1] { b -= 1 }
                } else {
                    sum > num ? b -= 1 : (a += 1)
                }
            }
        }
        return result
    }
}
