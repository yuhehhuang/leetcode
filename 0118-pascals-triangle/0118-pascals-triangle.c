/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // 設置要返回的數組的大小
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows*sizeof(int));
    // 分配二維矩陣記憶體
    int **output = (int**)malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i++) {
        output[i] = (int*)malloc((i + 1) * sizeof(int));
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                // 邊界上的元素為 1
                output[i][j] = 1;
            } else {
                // 內部元素為上一行同列和前一列的元素之和
                output[i][j] = output[i - 1][j - 1] + output[i - 1][j];
            }
        }
        (*returnColumnSizes)[i] = i + 1; // 設置每一行的列數
    }

    return output;  // 返回生成的帕斯卡三角形
}
//這個版本的程式碼使用了二維矩陣的概念，通過迴圈填充每個位置的值，生成了帕斯卡三角形。同樣地，記得在使用完數組後，使用 free 釋放相應的記憶體。

