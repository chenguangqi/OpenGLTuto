矩阵变换时的注意事项：
* 变换应用的顺序与矩阵相乘的顺序相反。`M = M_translation * M_rotation`的意思是先旋转，后平移。
* 与单位矩阵是一个什么也不做的矩阵，即不发生变换。
* 对顶点的变换，是用矩阵乘以顶点：`v' = M * v`
* 4x4的矩阵只与4x1的向量相乘，这里顶点的第四个维度是1：(x, y, z, 1)