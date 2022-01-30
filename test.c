/**
 *这是顺序线性存储结构的高级操作;
 * 初始化，销毁，清空，判断是否为空，判断是否为满，得到长度，查找某个位置的元素，查找某个元素的位置并找到其出现了几次，找值前驱，找值的后继，位置插入，
 * 值插入，位置删除，值删除，打印，排序，追加，颠倒，大约18个操作
 * 顺序线性存储结构优点：存储速度快、查找元素效率高；缺点：需连续的很大的内存、插入删除效率低；
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#define LIST_INIT_SIZE 10
typedef struct ArrayList
{
    int* data;
    int length; //存储当前长度
    int listSize;//存储容量
}A,*PA;
PA initArrayList(PA PArr);
PA destroyArrayList(PA PArr);
void clearArrayList(PA PArr);
bool isEmpty(PA PArr);
bool isFull(PA PArr);
int getLength(PA PArr);
void getElem(PA PArr);
int getElemPos(PA PArr, int val);
void getPrior(PA PArr);
void getPost(PA PArr);
void insertArrayList(PA PArr);
void deleteArrayList(PA PArr);
void printArrayList(PA PArr);
void appendArrayList(PA PArr);
void reverseArrayList(PA PArr);
void sortArrayList(PA PArr);
int main()
{
    printf("*************************\n");
    printf("* 1.initArrayList       *\n");
    printf("* 2.destroyArrayList    *\n");
    printf("* 3.Empty Or Not        *\n");
    printf("* 4.insertArrayList     *\n");
    printf("* 5.deleteArrayList     *\n");
    printf("* 6.clearArrayList      *\n");
    printf("* 7.printArrayList      *\n");
    printf("* 8.sortArrayList       *\n");
    printf("* 9.getElem             *\n");
    printf("* 10.getElemPos         *\n");
    printf("* 11.getPrior           *\n");
    printf("* 12.getPost            *\n");
    printf("* 13.reverseArrayList   *\n");
    printf("* 14.getLength          *\n");
    printf("* 15.Full Or Not        *\n");
    printf("* 16.appendArrayList   *\n");
    printf("*************************\n");
    char str;
    int num;
    int val;
    PA PArr = NULL;
    do
    {
        printf("Input Operand:");
        scanf("%d",&num);
        switch(num)
        {
        case 1:
            PArr = initArrayList(PArr); 
            break;
        case 2:
            PArr = destroyArrayList(PArr);
            break;
        case 3:
            if(isEmpty(PArr))
            {
                printf("Empty.\n");
            }
            else
            {
                printf("Not Empty.\n");
            }
            break;
        case 4:
            insertArrayList(PArr);
            break;
        case 5:
            deleteArrayList(PArr);
            break;
        case 6:
            clearArrayList(PArr);
            break;
        case 7:
            printArrayList(PArr);
            break;
        case 8:
            sortArrayList(PArr);
            break;
        case 9:
            getElem(PArr);
            break;
        case 10:
            printf("请输入你想要寻找的值:");
            scanf("%d",&val);
            getElemPos(PArr, val);
            break;
        case 11:
            getPrior(PArr);
            break;
        case 12:
            getPost(PArr);
            break;
        case 13:
            reverseArrayList(PArr);
            break;
        case 14:
            printf("长度为:%d\n",getLength(PArr));
            break;
        case 15:
            if(isFull(PArr))
            {
                printf("Full.\n");
            }
            else
            {
                printf("Not Full.\n");
            }
            break;
        case 16:
            appendArrayList(PArr); 
            break;
        }
        printf("Continue Or Not(Y/N):");
        scanf(" %c",&str);
    }while(str=='Y' || str=='y');
    return 0;
}
PA initArrayList(PA PArr)
{
    PArr = (PA)malloc(sizeof(A));
    if(NULL == PArr)
    {
        printf("Dynamic malloc failed.\n");
        exit(-1);
    }
    PArr->data = (int *)malloc(sizeof(int)*LIST_INIT_SIZE);
    if(NULL == PArr->data)
    {
        printf("Dynamic malloc failed.\n");
        exit(-1);
    }
    PArr->length = 0;
    PArr->listSize = LIST_INIT_SIZE;
    return PArr;
}
PA destroyArrayList(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    free(PArr->data);
    PArr->data = NULL;
    PArr->length = 0;
    PArr->listSize = 0;
    free(PArr);
    return NULL;
    
}
void clearArrayList(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    PArr->length = 0;
}
bool isEmpty(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    if(0 == PArr->length)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isFull(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    if(PArr->length == PArr->listSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int getLength(PA PArr)
{
    return PArr->length;
}
void getElem(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    printArrayList(PArr);
    int pos;
    printf("请输入你想要查找的位置:");
    scanf("%d",&pos);
    if(pos<1 ||pos>PArr->length)
    {
        printf("位置输入错误.\n");
        return;
    }
    else
    {
        printf("第%d个位置的元素为:%d\n",pos,PArr->data[pos-1]);
    }
}
int getElemPos(PA PArr, int val)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    printArrayList(PArr);
    int times = 0;
    printf("位置依次为:");
    for(int i = 0;i<PArr->length;i++)
    {
        if(PArr->data[i] == val)
        {
            printf("%d ",i+1);
            times++;
        }
    }
    if(0 == times)
    {
        printf("none");
    }
    else
    {
        printf(",共出现%d次",times);
    }
    printf("\n");
    return times;
}
void getPrior(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    printArrayList(PArr);
    int option;
    printf("1.求位置前驱，2.求值前驱.请输入你的选择:");
    scanf("%d",&option);
    if(1 == option)
    {
        int pos;
        printf("请输入你想要查找前驱的位置:");
        scanf("%d",&pos);
        if(pos<2 || pos>PArr->length)
        {
            printf("无前驱.\n");
        }
        else
        {
            printf("第%d个位置的前驱为:%d\n",pos,PArr->data[pos-2]);
        }
    }
    else if(2 == option)
    {
        int val;
        int times = 0;
        printf("请输入你想要查找前驱的值:");
        scanf("%d",&val);
        printf("前驱依次为:");
        for(int i = 1;i < PArr->length;i++)
        {
            if(PArr->data[i] == val)
            {
                printf("%d ",PArr->data[i-1]);
                times++;
            }
        }
        if(0 == times)
        {
            printf("none.");
        }
        printf("\n");
    }
    else
    {
        printf("option error.\n");
    }
}
void getPost(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    printArrayList(PArr);
    int option;
    printf("1.求位置后继，2.求值后继.请输入你的选择:");
    scanf("%d",&option);
    if(1 == option)
    {
        int pos;
        printf("请输入你想要查找后继的位置:");
        scanf("%d",&pos);
        if(pos<1 || pos>PArr->length-1)
        {
            printf("无后继.\n");
        }
        else
        {
            printf("第%d个位置的后继为:%d\n",pos,PArr->data[pos]);
        }
        
    }
    else if(2 == option)
    {
        int val;
        int times = 0;
        printf("请输入你想要查找后继的值:");
        scanf("%d",&val);
        printf("后继依次为:");
        for(int i = 0;i < PArr->length-1;i++)
        {
            if(PArr->data[i] == val)
            {
                printf("%d ",PArr->data[i+1]);
                times++;
            }
        }
        if(0 == times)
        {
            printf("none.");
        }
        printf("\n");
    }
    else
    {
        printf("option error.\n");
    }
}
void insertArrayList(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    printf("插入前");
    printArrayList(PArr);
    int option;
    printf("1.位置插入，2.值插入.请输入你的选择:");
    scanf("%d",&option);
    if(1 == option)
    {
        if(isFull(PArr))
        {
            PArr->data = (int*)realloc(PArr->data,PArr->length+LIST_INIT_SIZE);
            if(NULL == PArr->data)
            {
                printf("Dynamic realloc failed.\n");
                exit(-1);
            }
            PArr->listSize += LIST_INIT_SIZE; 
        }
        int pos;
        printf("请输入你想要插入的位置:");
        scanf("%d",&pos);
        int val;
        printf("请输入你想要插入的值:");
        scanf("%d",&val);
        if(pos<1 || pos>PArr->length+1)
        {
            printf("插入位置错误.\n");
            return;
        }
        for(int i = PArr->length-1;i >= pos-1;i--)
        {
            PArr->data[i+1] = PArr->data[i];
        }
        PArr->data[pos-1] = val;
        PArr->length++;
        printf("插入后");
        printArrayList(PArr);
    }
    else if(2 == option)
    {
        int val1;
        printf("请输入该值:");
        scanf("%d",&val1);
        int times = getElemPos(PArr, val1);
        if(0 == times)
        {
            printf("无该值.\n");
            return;
        }
        if(PArr->length+times > PArr->listSize)
        {
            PArr->data = (int*)realloc(PArr->data,PArr->length+LIST_INIT_SIZE);
            if(NULL == PArr->data)
            {
                printf("Dynamic realloc failed.\n");
                exit(-1);
            }
            PArr->listSize += LIST_INIT_SIZE; 
        }
        int option1;
        printf("1.插入到该值前面，2.插入到该值后面.请输入你的选择:");
        scanf("%d",&option1);
        int val2;
        printf("请输入你要插入的值:");
        scanf("%d",&val2);
        if(1 == option1)
        {
            for(int i = 0;i < PArr->length;i++)
            {
                if(PArr->data[i] == val1)
                {
                    for(int j = PArr->length-1; j >= i;j--)
                    {
                        PArr->data[j+1] = PArr->data[j];
                    }
                    PArr->data[i] = val2;
                    PArr->length++;
                    i++;
                }
            }
            printf("插入后");
            printArrayList(PArr);
        }
        else if(2 == option1)
        {
            for(int i = 0;i < PArr->length;i++)
            {
                if(PArr->data[i] == val1)
                {
                    for(int j = PArr->length-1; j >= i+1;j--)
                    {
                        PArr->data[j+1] = PArr->data[j];
                    }
                    PArr->data[i+1] = val2;
                    PArr->length++;
                    i++;
                }
            }
            printf("插入后");
            printArrayList(PArr);
        }
        else
        {
            printf("option error.\n");
        }
    }
    else
    {
        printf("option error.\n");
    }
}
void deleteArrayList(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    printf("删除前");
    printArrayList(PArr);
    int option;
    printf("1.位置删除，2.值删除.请输入你的选择:");
    scanf("%d",&option);
    if(1 == option)
    {
        if(isEmpty(PArr))
        {
            printf("为空.\n");
            return;
        }
        int pos;
        printf("请输入你想要删除的位置:");
        scanf("%d",&pos);
        if(pos<1 || pos>PArr->length)
        {
            printf("删除位置错误.\n");
            return;
        }
        for(int i = pos-1;i < PArr->length-1;i++)
        {
            PArr->data[i] = PArr->data[i+1];
        }
        PArr->length--;
        printf("删除后");
        printArrayList(PArr);
    }
    else if(2 == option)
    {
        int val1;
        int times = 0;
        printf("请输入要删除的值:");
        scanf("%d",&val1);
        for(int i = 0;i < PArr->length;i++)
        {
            if(PArr->data[i] == val1)
            {
                times++;
                for(int j = i;j < PArr->length-1;j++)
                {
                    PArr->data[j] = PArr->data[j+1];
                }
                PArr->length--;
                i--;
            }
        }
        if(0 == times)
        {
            printf("不存在该值.\n");
        }
        else
        {
            printf("删除后");
            printArrayList(PArr);
        }
    }
    else
    {
        printf("option error.\n");
    }
}
void printArrayList(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    printf("遍历为:");
    if(isEmpty(PArr))
    {
        printf("为空.");
    }
    for(int i = 0;i < PArr->length;i++)
    {
        printf("%d ",PArr->data[i]);
    }
    printf("\n");
}
void appendArrayList(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    printf("追加前");
    printArrayList(PArr);
    if(isFull(PArr))
    {
        PArr->data = (int*)realloc(PArr->data,PArr->length+LIST_INIT_SIZE);
        if(NULL == PArr->data)
        {
            printf("Dynamic realloc failed->\n");
            exit(-1);
        }
        PArr->listSize += LIST_INIT_SIZE; 
    }
    int val;
    printf("请输入你要追加的值:");
    scanf("%d",&val);
    PArr->data[PArr->length] = val;
    PArr->length++;
    printf("追加后");
    printArrayList(PArr);
}
void reverseArrayList(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    int i = 0;
    int j = PArr->length-1;
    while(i < j)
    {
        int temp = PArr->data[i];
        PArr->data[i] = PArr->data[j];
        PArr->data[j] = temp;
        i++;
        j--;
    }
    
}
void sortArrayList(PA PArr)
{
    if(NULL == PArr)
    {
        printf("PArr为NULL.\n");
        return;
    }
    for(int i = 0; i < PArr->length-1;i++)
    {
       for(int j = 0;j < PArr->length-1-i;j++)
       {
           if(PArr->data[j] > PArr->data[j+1])
           {
               int temp = PArr->data[j];
               PArr->data[j] = PArr->data[j+1];
               PArr->data[j+1] = temp;
           }
       }
    }
}
