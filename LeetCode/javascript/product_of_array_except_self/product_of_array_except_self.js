function productExceptSelf(nums) {
    const result = [];
    let currentProduct = 1;
    for (let i = 0; i < nums.length; i++) {
        result[i] = currentProduct
        currentProduct *= nums[i]
    }
    currentProduct = 1
    for (let j = nums.length-1; j >= 0; j--) {
        result[j] *= currentProduct
        currentProduct *= nums[j]
    }
    return result;
};