### c语言指针
#### 1.指针与数组的初始化

```c
    char *p = "I love Shanghai.";       // 正确
    char a[20] = "I love Shanghai."     // 正确
    p = "I love Beijing.";              // 正确
    a = "I love Beijing.";              // 错误
```
        原因：a实际上是常量，在数组定义时就已经分配地址，且不可被改变；

#### 2.指针+1的长度

```c
    p=&a;               // 将变量a的地址赋给p，p++跳跃该类型的长度

    p=&array;           // 将数组array地址赋给p(与首元素地址相同，但指向整个数组)，p++跳跃一个数组的长度
    p=array;            // 将数组array首元素的地址赋给p，p++跳跃一个元素的长度
    p=&array[0];        // 将数组array首元素的地址赋给p，p++跳跃一个元素的长度
```
        总结：指针指向的是什么，+1后跳跃的长度就是被指向内容所占据的长度

#### 3.指针结构体

```c
	// typedef常用来定义类型别名

    typedef struct mem{
        int num;
        struct mem *next;
    }Member;
    // c++在使用结构体时可以省略struct

    typedef struct mem Member;
    struct mem{
        int num;
        Member *next;
    }
    // typedef的定义必须要先于使用

    typedef struct mem *Member;
    struct mem{
        int num;
        Member next;
    };
    // typedef可以定义指针类型

    typedef struct{
        int num;
    }Num;
    // 这是定义一个匿名结构体
```

#### 4.使用结构体指针的数据结构的小失误

```c
    /*
     * 1.指针未分配空间就去访问结构体指针内容
     */
    Member *head;
    head->next=...;     // 相当于*(head).next 通常头指针需要分配空间

    /*
     * 2.循环一次也没进入时，存在不能访问的指针
     */
    Member *p;
    for(i=1,i<n,i++)
        p=(Member*)malloc(sizeof(Member));
    p->next=head;       // 该结构体指针不能访问

    /*
     * 3.存在指针的情况下，循环计数初始值不像数组直观 - 不涉及到偏移量时，和涉及到偏移量时的初始值有些区别
     */
     for(q=head,p=q->next,i=2;q!=p;q=p,p=p->next,i++) // 已经存在两个了
        if(i==3)
            ...;

    /*
     * 4.同样的，存在指针的情况下，循环计数值自增周期也不直观
     */
     for(...;...;i++)
        if(i==3)
            i=0;        //这样实际上回到的初始值为1

```