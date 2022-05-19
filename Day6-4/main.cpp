#include <QCoreApplication>
#include <iostream>

using namespace std;

//@ 自然归并排序 Ref:
//@  https://blog.csdn.net/qq_44971979/article/details/108905938?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-108905938-blog-49422933.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-108905938-blog-49422933.pc_relevant_default&utm_relevant_index=2

//利用sign[]数组存储创建的标记点，并返回标记点的个数
int getIndex(int *s, int *sign, int n) {
    int cin = 0;
    sign[cin++] = 0;

    for(int i = 0; i < n-1; i++)
        if(s[i] > s[i+1])
            sign[cin++] = i+1;

    //printf("%d\n", cin);
    return cin;
}







//合并两个子段函数
void merge(int *s, int *b, int start1, int endl, int start2, int end2) {
    int b_i = start1;
    while( start1<=endl && start2<=end2 )
    {
        if(s[start1]<s[start2])
            b[b_i++] = s[start1++];
        else
            b[b_i++] = s[start2++];
    }
    while(start1<=endl)
        b[b_i++] = s[start1++];
    while(start2<=end2)
        b[b_i++] = s[start2++];
}

//合并过程函数
void mergePass(int *s, int n, int *b, int *sign, int num, int jump) {
    //标记点的控制变量
    int sign_i = 0;

    //判断是超过sign[]数组的最大下标
    //需要知道三个标记点，sign[sign_i]，sign[sign_i+jump]，sign[sign_i + 2*jump]，才能进行while循环
    while((sign_i+2*jump) < num) {
        merge(s, b, sign[sign_i], sign[sign_i+jump]-1,sign[sign_i+jump] , sign[sign_i + 2*jump]-1);
        sign_i = sign_i + 2*jump;
    }

    //注意数组不能越界，不能等于num
    //还有标记点剩余（两个），但没有合并，则这两个标记点与原数组最后的下标（n-1）构成三个标记的点，形成合并
    //注：当最后一个标记点与原数组的最后下标重合（如数组只有 6，5两个元素），也可合并
    if( sign_i+jump < num)
        merge(s, b, sign[sign_i], sign[sign_i+jump]-1, sign[sign_i+jump], n-1);

    //注：num不能越界
    //剩余一个标记点，无法合并，直接复制到b[]数组下
    else if(sign_i < num)
        for(int j = sign[sign_i];j<n;j++)
            b[j] = s[j];
}

//合并数组函数，实现自然归并排序
void mergeSort(int *s, int n, int *sign, int num) {
    int jump = 1;
    int b[10];
    while(jump < num) {
        mergePass(s, n, b, sign, num, jump);
        jump+=jump;
        for(int i=0;i<10;i++)
            s[i] = b[i];
    }
}



int main() {
    //// std::cout << "hello world!" << std::endl;
    ////cout << "Hello!\n";
    int array[10];
    int sign[10];

    for(int i=0;i<10;i++)
        cin >> array[i];

    int num = getIndex(array, sign, 10);

    mergeSort(array, 10, sign, num);

    for(int i=0;i<10;i++)
        cout << array[i] << " ";
    cout << endl;

    ////system("pause");
    return 0;
}
