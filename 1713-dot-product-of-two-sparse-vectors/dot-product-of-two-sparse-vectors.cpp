class SparseVector {
public:
    const vector<int> &sparseVector;
    SparseVector(vector<int> &nums):sparseVector(nums) {}
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int dotProduct = 0;
        for(int i = 0; i < (sparseVector).size() ; i++)
        {
            dotProduct += sparseVector[i] * vec.sparseVector[i];
        }
        return dotProduct;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);