class NumArray {
  static class BinaryIndexedTree {
    int[] nums;
    int[] BIT;
    int n;

    public BinaryIndexedTree(int[] nums) {
      this.nums = nums;
      this.n = nums.length;
      BIT = new int[n + 1];
      for (int i = 0; i < n; i++) {
        init(i, nums[i]);
      }
    }

    void init(int i, int val) {
      i++;
      while (i <= n) {
        BIT[i] += val;
        i += (i & -i);
      }
    }

    void update(int i, int val) {
      int diff = val - nums[i];
      nums[i] = val;
      init(i, diff);
    }

    int getSum(int i) {
      i++;
      int ret = 0;
      while (i > 0) {
        ret += BIT[i];
        i -= (i & -i);
      }
      return ret;
    }
  }

  BinaryIndexedTree binaryIndexedTree;

  public NumArray(int[] nums) {
    binaryIndexedTree = new BinaryIndexedTree(nums);
  }

  public void update(int index, int val) {
    binaryIndexedTree.update(index, val);
  }

  public int sumRange(int left, int right) {
    return binaryIndexedTree.getSum(right) - binaryIndexedTree.getSum(left - 1);
  }
}
