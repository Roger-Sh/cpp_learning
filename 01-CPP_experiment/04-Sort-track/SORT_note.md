# SORT 多目标追踪



## SORT 

### 流程

1.  初始化
    -   KF追踪器列表
    -   是否第一帧的flag
2.  对每一帧识别结果的操作
    -   bbox_vec size check
    -   confi skip
    -   class skip
    -   检查当前帧的识别数量
    -   对识别结果从高到低初步的排序
3.  第一帧
    -   KF: 对每一个BBOX初始化KF追踪器, 将拥有编号的BB加入KF追踪器列表
4.  第二帧
    -   KF: 预测
        -   根据上一帧结果结合dt进行线性预测当前帧位置
        -   对上一帧没有匹配的追踪器不进行预测
    -   KM: 将这一帧的BB, 与上一帧**预测结果**进行KM最佳匹配
        -   需要将当前帧的BB与预测的BB计算距离, 生成权重map
            -   根据IOU或者距离确认权重map
        -   数量不足的set补上最大距离
        -   KF_trackers 为setA, new_bbox 为setB
        -   距离匹配超过阈值的设置为匹配失败 
    -   KF: 更新
        -   case1: 获得匹配的KF追踪器
            -   重置失去匹配计数器为0
            -   根据匹配的观测结果更新KF追踪器
        -   case2: 失去匹配的KF追踪器
            -   失去匹配计数器+1, 维持一段时间的生命周期, 如果超过生命周期则将其删除
        -   case3: 没有得到匹配的新观测结果
            -   当作新的识别结果, 初始化为新的KF追踪器以及获取新的编号
    -   可视化KF追踪器中的BBOX以及编号



### 注意事项

-   识别帧率越高越好, 低帧率容易导致匹配出现问题, 60hz时匹配效果较好
-   KF:
    -   预测部分的协方差矩阵, 设置大一些表示不信任预测结果, 10000 - 1000000
    -   检测部分的测量噪声矩阵, 设置小一些, 表示更大的权重, 0.000001
    -   追踪器的生命周期 10帧, 减少检测框闪烁
-   KM:
    -   匹配权重采用欧式距离, 表现上比IOU更加稳定
    -   也可尝试IOU*100-欧式距离, 当有IOU时设置欧式距离为0, 当无IOU时只使用欧式距离



## Kalman Filter for detection

### Predict

$$
\begin{align}
\mathrm{with\ control}:\ x' &= Ax + Bu \\
\mathrm{without\ control}:\ x' &= Ax \\
P' &= APA^{\mathrm{T}} + Q
\end{align}
$$

with:
$$
\begin{align}
\mathrm{mean\ state}&:\ x = 
\begin{bmatrix}
cx, cy, w, h, v_{cx}, v_{cy},v_w, v_h 
\end{bmatrix} ^{\mathrm{T}} \\
\\
\mathrm{predict\ trans\ matrix}&: A =
\begin{bmatrix}
1 & 0 & 0 & 0 & dt & 0 & 0 & 0 \\
0 & 1 & 0 & 0 & 0 & dt & 0 & 0 \\
0 & 0 & 1 & 0 & 0 & 0 & dt & 0 \\
0 & 0 & 0 & 1 & 0 & 0 & 0 & dt \\
0 & 0 & 0 & 0 & 1 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 1 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 1 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 1 \\
\end{bmatrix}\\
\\
\mathrm{system\ noise}&:\ Q = \mathrm{I}\cdot q,\mathrm{I}\in\R^{8,8} \\
\\
\mathrm{error\ covariance\ matrix}&:\ P = \mathrm{I}\cdot p,\mathrm{I}\in\R^{8,8} \\
\end{align}
$$


### Update

$$
\begin{align}
y &= z - H \cdot x' \\
S &= HP'H^{\mathrm{T}} + R \\
K &= P'H^{\mathrm{T}}S^{-1} \\
\\
x'' &= x' + K\cdot y \\
P'' &= (\mathrm{I} - KH)\cdot P'
\end{align}
$$

with:
$$
\begin{align}
\mathrm{measurement\ state}&:\ z = 
	\begin{bmatrix}
	cx & cy & w & h 
	\end{bmatrix} \\
\\
\mathrm{measure\ trans\ matrix}&:\ H = 
	\begin{bmatrix}
		1 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
		0 & 1 & 0 & 0 & 0 & 0 & 0 & 0 \\
		0 & 0 & 1 & 0 & 0 & 0 & 0 & 0 \\
		0 & 0 & 0 & 1 & 0 & 0 & 0 & 0 \\
	\end{bmatrix} \\
\\
\mathrm{measure\ noise}&:\ R = \mathrm{I} \cdot r,\mathrm{I} \in \R^{4, 4} 

\end{align}
$$




