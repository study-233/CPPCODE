# STL
    默认都是从小到大排序
    greater<T> 从大到小的规则
    也可以自定义排序规则
        struct Rule{
            bool operator() (const T & a1,const T & a2) const{
                //排序规则
            }
        }
## 排序

    sort(a+i,a+j,Rule)
    左闭右开


## 二分查找

###    binary_search(数组名+n1,数组名+n2,key值，Rule排序规则结构名())

    1.Rule规则要与排序规则一致
    2.等于含义是 a必须在b前面 与 b必须在a前面 都不成立
      所以key不一定等于查找到的值

###  查找下界
#### T* lower_bound(数组名+n1,数组名+n2,key值)
    数组从小到大排好
    *P是查找区间里下标最小的， 大于等于"值"后面的元素。如果找不到，p指向下标为n2的元素
#### T* lower_bound(数组名+n1,数组名+n2,key值，Rule排序规则结构名())
    返回 *P
    *P是查找区间里下标最小的， 按自定义排序规则， 可以排在"值"后面的元素。如果找不到，p指向下标为n2的元素
### 查找上界
#### T* upper_bound(数组名+n1,数组名+n2,key值)
    数组从小到大排好
    *P是查找区间里下标最小的， 大于"值"后面的元素。如果找不到，p指向下标为n2的元素
#### T* upper_bound(数组名+n1,数组名+n2,key值，Rule排序规则结构名())

    返回 *P
    *P是查找区间里下标最小的， 按自定义排序规则， 必须排在"值"后面的元素。如果找不到，p指向下标为n2的元素

## 平衡二叉树数据结构

### multiset<T> st   复杂度log(n)

#### 基本
    排序规则：a<b
    st.insert() 添加
    st.find() 查找
        找不到返回值为st.end()
        规则：a必须在b前面 与 b必须在a前面 都不成立
    st.erase() 删除
    st.count(x) x的个数
    st.size() 元素个数
    >返回值都是迭代器
#### 访问元素 迭代器
    multiset<T>::iterator p;
    >p相当于指针，指向元素
    >可以++,--,!=,==
    >不可以比大小，不可加减整数，不可相减

    st.begin()
    st.end()

#### st.lower_bound(key)
    该函数返回一个迭代器，该迭代器指向刚好大于key的下一个元素。如果参数中传入的键超过了容器中的最大键，则返回的迭代器将指向st.end(),该数值对应容器中最后一个元素之后的下标.
#### st.upper_bound(key)
    该函数返回一个迭代器，该迭代器指向刚好等于key的一个元素。如果参数中传递的键不在容器中，则返回的迭代器将指向刚好大于key的那个元素，如果传入的key超过了容器中的最大键，则返回的迭代器将指向st.end(),该数值对应容器中最后一个元素之后的下标.

### set<T>
    其中元素内容不能重复
    在插入时可能不成功
    result = st.insert(value);
        返回值时pair类型
            struct {
                set<int>::iterator first;
                bool second;
            }
    !result.second == true 表示插入不成功

### multimap
    typedef multimap<T1,T2> MAP_STD
        struct {
            T1 first;
            T2 second;
        }
        按照first排序 a.first < b.first
    MAP_STD 等价于 multimap<T1,T2>

    typedef multimap<T1,T2> MP
    MP mp;
    mp.insert(make_pair(,))
### map

    可以使用[],插入查找
    下标为关键字，返回值为first与关键字相同的元素的second