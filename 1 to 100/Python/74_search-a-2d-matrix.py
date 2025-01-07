class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix[0])
        m = len(matrix)
        for i in range(m):
            if target < matrix[i][n-1]:
                for j in range(n-1):
                    if target == matrix[i][j]:
                        return True
                return False
            elif target == matrix[i][n-1]:
                return True
            else:
                continue
        return False