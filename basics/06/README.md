## 模型-视图-投影 矩阵(Model-View-Projection Matrix)

到目前为止，我们使用的都是模型坐标系，它以模型的中心为源点。
对于有多个模型的情况，

计算出一个变换矩阵：

* 移动模型坐标系到世界坐标系(model->word)
* 从世界坐标系到视图坐标系(world->view)
* 从视图坐标系到投影(2D screen)坐标系(view->projection)
