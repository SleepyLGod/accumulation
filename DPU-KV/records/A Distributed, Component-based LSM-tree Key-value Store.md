## A Distributed, Component-based LSM-tree Key-value Store

> 将 `LSM `树键值存储分解为使用 `RDMA `进行通信的组件
>
> 存储与处理分开，处理组件能够共享存储带宽和空间
>
> 处理组件将 `SSTable` 分散到任意数量的存储组件中，并使用 `power-of-d` 平衡它们之间的负载
>
> 运行时动态构建范围，以并行化压缩并提高性能
>
> 