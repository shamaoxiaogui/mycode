#ifndef ADRO_DQPOINTER_H
#define ADRO_DQPOINTER_H

//这个函数的意义在于，当ptr被传入一个智能指针时，可以触发其转换
//机制，得到其内部的原生指针
template <typename T> static inline T *qGetPtrHelper(T *ptr) { return ptr; }
template <typename Wrapper> static inline typename Wrapper::pointer qGetPtrHelper(const Wrapper &p) { return p.data(); }

// 使用Q_D之前必须使用下面这个宏，定义d_func
#define Q_DECLARE_PRIVATE(Class) \
    inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(qGetPtrHelper(d_ptr)); } \
    inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(qGetPtrHelper(d_ptr)); } \
    friend class Class##Private;

#define Q_DECLARE_PRIVATE_D(Dptr, Class) \
    inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(Dptr); } \
    inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(Dptr); } \
    friend class Class##Private;

// 和上面的那个private宏相对用，在使用Q_Q之前必须定义
#define Q_DECLARE_PUBLIC(Class)                                    \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;

#define Q_D(Class) Class##Private * const d = d_func()
#define Q_Q(Class) Class * const q = q_func()

// QT中大名鼎鼎的Q_D和Q_Q。用于实现私有数据类机制。也就是，将公共类
// 分为两部分，一部分作为暴露给用户（程序员）的接口，另一部分作为私
// 有的数据，将这些数据单独放到一个XXXPrivate类中，在公共类只放该私
// 有类的一个指针。这样做有至少两点好处：
// 1. 保证不同库（QT）发布版本之间的二进制兼容性
// 2. 减少依赖，加快编译速度
// 缺点自然就是效率了，需要多一层指针间接访问
// 使用时需要在类中定义一个XXXPravite指针d_ptr
#endif
